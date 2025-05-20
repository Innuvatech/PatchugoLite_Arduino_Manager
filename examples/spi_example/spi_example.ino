#include <patchugo_lite.h>
#include <SPI.h>

PatchugoLite patchugoLite;

SPISettings spiSettings(5000000, MSBFIRST, SPI_MODE1);

#define R_REF 430.0
#define RTD_A 3.9083e-3
#define RTD_B -5.775e-7
#define R0    100.0

static float calculateTemperature(uint16_t rtd_raw) {
  float rtd_resistance = ((float)rtd_raw * R_REF) / 32768.0;
  float Z1 = -RTD_A;
  float Z2 = RTD_A * RTD_A - (4 * RTD_B);
  float Z3 = (4 * RTD_B) / R0;
  float Z4 = 2 * RTD_B;

  float temp = Z1 + sqrt(Z2 + (Z3 * rtd_resistance));
  temp = temp / Z4;

  return temp;
}

void setup() {
  Serial.begin(115200);

  patchugoLite.Init();
  patchugoLite.SPI_Init(5000000, MSBFIRST, SPI_MODE1);

  uint8_t cmd[2] = {0x80, 0x01};
  patchugoLite.SPI_Write(cmd, 2);

  cmd[0] = 0x86;
  cmd[1] = 0x00;
  patchugoLite.SPI_Write(cmd, 2);

  cmd[0] = 0x85;
  cmd[1] = 0x00;
  patchugoLite.SPI_Write(cmd, 2);

  cmd[0] = 0x84;
  cmd[1] = 0xFF;
  patchugoLite.SPI_Write(cmd, 2);

  cmd[0] = 0x83;
  cmd[1] = 0xFF;
  patchugoLite.SPI_Write(cmd, 2);

  cmd[0] = 0x80;
  cmd[1] = 0x03;
  patchugoLite.SPI_Write(cmd, 2);

  cmd[0] = 0x80;
  cmd[1] = 0x01;
  patchugoLite.SPI_Write(cmd, 2);

  cmd[0] = 0x80;
  cmd[1] = 0xD0;
  patchugoLite.SPI_Write(cmd, 2);

}

void loop() {

  uint8_t oneShot[2] = {0x80, 0xA1};
  patchugoLite.SPI_Write(oneShot, 2);

  uint8_t rawVal[2] = {0};

  patchugoLite.SPI_Read(0x01, 2, rawVal);

  uint16_t rtd = ((uint16_t)rawVal[0] << 8 | rawVal[1]) >> 1;
  float testTemp = calculateTemperature(rtd);
  Serial.print("TEMPERATURE: ");
  Serial.println(testTemp);

  digitalWrite(PA15, HIGH);

  delay(3000);

}
