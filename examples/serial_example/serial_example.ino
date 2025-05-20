#include <patchugo_lite.h>

PatchugoLite patchugoLite;

void my_callback(uint8_t buf[], uint8_t len) {
  //Manage data here
}

void setup() {

  Serial.begin(115200);

  Serial.println("SETUP START");
  
  patchugoLite.Init();

  //Sets mode to RX
  patchugoLite.RS485_Set_Mode(RS485_Mode::RX);

  //Sets callback function
  patchugoLite.RS485_Set_RXCallback(my_callback);


  Serial.println("SETUP DONE");

}

void loop() {

  patchugoLite.RS485_Update();
}
