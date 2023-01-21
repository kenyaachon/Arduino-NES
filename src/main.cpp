#include <Arduino.h>
// #include "SD_MMC.h"
#include "SPI.h"
#include "SD.h"

SPIClass spi = SPIClass(SPI);

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(115200);

  Serial.print("MOSI: ");
  Serial.println(MOSI);
  Serial.print("MISO: ");
  Serial.println(MISO);
  Serial.print("SCK: ");
  Serial.println(SCK);
  Serial.print("SS: ");
  Serial.println(SS); 

  spi.begin(SCK, MISO, MOSI, SS);

  if (!SD.begin(SS,spi,80000000)) {
    Serial.println("Card Mount Failed");
    return;
  }

  uint8_t cardType = SD.cardType();

  if(cardType == CARD_NONE){
    Serial.println("No SD card attached");
    return;
  }

  Serial.print("SD Card Type: ");
  if(cardType == CARD_MMC){
    Serial.println("MMC");
  } else if(cardType == CARD_SD){
    Serial.println("SDSC");
  } else if(cardType == CARD_SDHC){
    Serial.println("SDHC");
  } else {
    Serial.println("UNKNOWN");
  }

  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.printf("SD Card Size: %lluMB\n", cardSize);
}

void loop()
{
  // Serial.println("Hello world");
}