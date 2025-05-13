# PatchugoLite_Arduino_Manager
Arduino library to use the PatchugoLite board

## Prerequisites
To use this library the Innuvatech PatchugoBoards board manager is necessary. To do that add the following line to Arduino preferences **https://github.com/Innuvatech/BoardManagerFiles/raw/main/package_innuvatech_index.json**. Once that is done, an installation of the Patchugo boards platform must be done. To do that you can go in the Arduino boards manager and install it from there, look for a platform called **Patchugo Boards** by Innuvatech as shown in the image below

![Boards manager image](https://github.com/Innuvatech/PatchugoLite_Arduino_Manager/blob/main/docs/images/Patchugo_Boards.png)



## Library installation
To install this library into Arduino simply go in the library manager and look for a library called **PatchugoLite_Arduino_Manager**. Once installed you can include it in your sketches from the sketches section>Include Library

## Basic usage

Everything on the board is controlled by a class called PatchugoLite. The bare minium code to make anything work is to instantiate an object of PatchugoLite and call the Init function. That function is responsible to initialize all the peripherals on the board. **If manual initialization of peripherals is necessary the Init function can be bypassed but it's strongly encouraged to use the default library implementation** Below is the code in Arduino for basic setup of the PatchugoLite board:

```
#include <patchugo_lite.h>

PatchugoLite patchugoLite;

void setup() {

  //Initialize serial for debug prints
  Serial.begin(115200);
  
  //Initializes all peripherals on the board
  patchugoLite.Init();


}

void loop() {

}
```
