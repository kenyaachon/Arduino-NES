#include <Arduino.h>
// #include "SD_MMC.h"
#include "SPI.h"
#include "SD.h"

#define SD_CS 5

SPIClass spi = SPIClass(VSPI);

void setup() {
  // put your setup code here, to run once:
  pinMode(SD_CS, OUTPUT);
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  spi.begin(SCK, MISO, MOSI, SS);

  Serial.print("MOSI: ");
  Serial.println(MOSI);
  Serial.print("MISO: ");
  Serial.println(MISO);
  Serial.print("SCK: ");
  Serial.println(SCK);
  Serial.print("SS: ");
  Serial.println(SS);
// if(!SD_MMC.begin(SS, spi, 80000000)){
//         Serial.println("Card Mount Failed");
//         return;
//     }
//     uint8_t cardType = SD_MMC.cardType();

//     if(cardType == CARD_NONE){
//         Serial.println("No SD_MMC card attached");
//         return;
//     }

//     Serial.print("SD_MMC Card Type: ");
//     if(cardType == CARD_MMC){
//         Serial.println("MMC");
//     } else if(cardType == CARD_SD){
//         Serial.println("SDSC");
//     } else if(cardType == CARD_SDHC){
//         Serial.println("SDHC");
//     } else {
//         Serial.println("UNKNOWN");
//     }


if(!SD.begin(SS, spi, 80000000)){
    Serial.println("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD.cardType();

  if(cardType == CARD_NONE){
    Serial.println("No SD card attached");
    return;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}