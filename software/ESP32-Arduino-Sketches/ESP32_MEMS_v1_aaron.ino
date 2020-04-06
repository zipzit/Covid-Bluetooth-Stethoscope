/* UDP audio streamer with ESP32 and MEMS I2S mic
 * Resources:
 * https://www.hackster.io/julianso/esp32-voice-streamer-52bd7e
 * https://superuser.com/questions/597227/linux-arecord-capture-sound-card-output-rather-than-microphone-input
 * https://esp32.com/viewtopic.php?f=19&t=4997
 * to play live:
 *         nc -l -u 7777 | aplay -r 44100 -f S32_LE -c2
 * convert to wav file:  
 *         nc -l -u 7777 > test32.dump
 *         sox -t raw -r 44100 -e unsigned-integer -L -b 32 -c 2 test32.dump output.wav
*/
#include <Arduino.h>
#include <WiFi.h>
#include <driver/i2s.h>

// setup I2S
const i2s_port_t I2S_PORT = I2S_NUM_0;

// Wireless network setup
const char* ssid     = "[YOUR WIFI SSID]";
const char* password = "[PASSWORD]";

// remote port
const int port   = 7777;
const char* host = "192.168.86.242";

// UDP client
WiFiUDP client;

// init
void setup() {    
  // for debugging  
  Serial.begin(500000);

  // seutp wireless, don't bother with event handling
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("Leased IP address: ");
  Serial.println(WiFi.localIP());

  // The I2S config as per the example
  const i2s_config_t i2s_config = {
      .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX), 
      .sample_rate = 44100,                         
      .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT, 
      .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT, 
      .communication_format = I2S_COMM_FORMAT_I2S_MSB,
      .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,      
      .dma_buf_count = 4, 
      .dma_buf_len = 8    
  };

  // pin config as per the setup
  const i2s_pin_config_t pin_config = {
      .bck_io_num = 14,   // BCKL
      .ws_io_num = 15,    // LRCL
      .data_out_num = -1, // not used (only for TX)
      .data_in_num = 32   // DOUT
  };

  // setup pins
  pinMode(32, INPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);

  // Configuring the I2S driver and pins.
  // This function must be called before any I2S driver read/write operations.
  if (i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL) != ESP_OK) {
    Serial.println("Failed installing driver!");
    while (true);
  }
  if (i2s_set_pin(I2S_PORT, &pin_config) != ESP_OK) {
    Serial.println("Failed configuring pins.");
    while (true);
  }
  Serial.println("I2S driver installed.");

  // setup UDP client  
  client.beginPacket(host,port);
}

// main logic
void loop() {
  uint32_t sample;

  // read samples without timeout
  int bytes_read = i2s_pop_sample(I2S_PORT, (char *)&sample, portMAX_DELAY); 

  // convert to byte and dump to UDP 
  byte *p;
  p = (byte*)&sample;
  client.write(p,sizeof(p));
}