#include <patchugo_lite.h>

PatchugoLite patchugoLite;

void my_callback(uint8_t buf[], uint8_t len) {
  
  if(len == 3) {
    if(buf[0] == 0x08) {
      Serial.println("Send response");
      uint8_t response = 105;
      PatchugoStatusCode checkError = patchugoLite.BT_Write(&response, 1);
      if(checkError != PatchugoStatusCode::OK) {
        //Manage error here
      }
    }
  }
}

void setup() {

  Serial.begin(115200);

  Serial.println("SETUP START");
  
  patchugoLite.Init();

  //Change Bluetooth name
  patchugoLite.BT_Change_Name("CodeSampleBT");

  //Set transparent mode
  patchugoLite.BT_Set_Mode(BTMode::TRANSPARENT);
  
  delay(1000);

  //Set RX callback function
  patchugoLite.BT_Set_RXCallback(my_callback);

  Serial.println("SETUP DONE");
 
}

void loop() {

  patchugoLite.BT_Update();
}
  
