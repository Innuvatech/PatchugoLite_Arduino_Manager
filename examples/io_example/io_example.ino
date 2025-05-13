#include <patchugo_lite.h>


PatchugoLite patchugoLite;

void setup() {

  //Initialize serial for debug prints
  Serial.begin(115200);
  
  //Initializes all peripherals on the board
  patchugoLite.Init();

  //Writes to a single OUTPUT pin(OUT 4)
  patchugoLite.IO_Write(OutputPin::OUT_4, SET);
  delay(1000);
  patchugoLite.IO_Write(OutputPin::OUT_4, RESET);

  //Reads a single INPUT pin(IN 2)
  uint8_t readVal = patchugoLite.IO_Read(InputPin::IN_2);

}

void loop() {

  //Writes 1 to all OUTPUT pins
  for(uint8_t i = 0; i < patchugoLite.N_OUT_PINS; i++) {
    patchugoLite.IO_Write(patchugoLite.outputPinsList[i], SET);
    delay(1000);
  }

  //Reads all INPUT pins
  for(uint8_t i = 0; i < patchugoLite.N_IN_PINS; i++) {
    uint8_t readPin = patchugoLite.IO_Read(patchugoLite.inputPinsList[i]);
    Serial.printf("READ IN%d:  ", i+1);
    Serial.print(readPin);
  }
}
