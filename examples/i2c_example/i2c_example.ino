#include <patchugo_lite.h>

PatchugoLite pathcugoLite;


void setup() {

  Serial.begin(115200);
  
  pathcugoLite.Init();

  Serial.println("SETUP");

  pathcugoLite.I2C_Init(0x23);

  uint8_t cmd = 0x01;
  pathcugoLite.I2C_Write(&cmd, 1);

  cmd = 0x07;
  pathcugoLite.I2C_Write(&cmd,1);

  cmd = 0x10;
  pathcugoLite.I2C_Write(&cmd, 1);

}

void loop() {
  
  uint8_t data[2] = {0};

  pathcugoLite.I2C_Read(0x23, 2, data);

  uint16_t val = data[0] | (data[1] << 8);
  Serial.print("VAL: ");
  Serial.println(val);
  delay(1000);

}
