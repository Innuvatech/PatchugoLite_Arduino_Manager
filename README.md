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

## IO Pins

The board has 8 digital OUTPUT pins and 8 digital INPUT pins both working at 24V logic level. The software sets their mode in the Init function of the library while to write and read the respective functions IO_Write and IO_Read must be called. The INPUT pins and OUTPUT pins have been divided into 2 enum classes for better clarity called InputPin and OutputPin respectively. Both enums range from 1 to 8(meaning the INPUT pins go from IN_1 to IN_8 while the OUTPUT pins go from OUT_1 to OUT_8). The IO_Write and IO_Read functions expect the respective enum of OutputPin or InputPin to be given as a parameter. The function calls to IO_Write and IO_Read look like this:
```
 //Writes to a single OUTPUT pin(OUT 4)
patchugoLite.IO_Write(OutputPin::OUT_4, SET);

 //Reads a single INPUT pin(IN 2)
 uint8_t readVal = patchugoLite.IO_Read(InputPin::IN_2);
```

Below is a complete example of writing and reading pins using the library:
```
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
```

## Bluetooth Management

The board provides the user with a Proteus-E ble module that is easily controllable with this library, with a few lines of code it's possible to completely set up the Bluetooth to send and receive data trough serial.

### Bluetooth setup

While the library Init function already initializes the Bluetooth in a basic way, functions are provided to the user to set the bluetooth up:
  - BT_Reset function to reset the Bluetooth module. This function is already called inside the library Init function so it can be skipped. Example usage below
     ```
     //Resets the bluetooth module
      patchugoLite.BT_Reset();
     ```
     ```
       patchugoLite.Init();

      //This is unnecessary because the Init function already does it
      patchugoLite.BT_Reset();

     ```
     


