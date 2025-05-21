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

   - BT_Set_Mode function to set the Bluetooth operating mode(either COMMAND mode or TRANSPARENT mode). The default operating mode that is set inside the 
      library Init function is COMMAND mode so if the user does not change the mode after the Init function the bluetooth will keep operating in COMMAND mode.
      Example usage below
     
      ```
      //Sets Bluetooth to work in TRANSPARENT mode
      patchugoLite.BT_Set_Mode(BTMode::TRANSPARENT);
      ```

   - BT_Change_Name function to change the Bluetooth advertising name. To use this COMMAND the Bluetooth module must be in COMMAND mode. The maximum allowed            length for a name is 20 characters, if a name longer than 20 characters is provided the function will return an error and the Bluetooth name will not be           changed. An error will also be returned if the user tries to change Bluetooth name while in TRANSPARENT mode The default name set inside the library Init          function is "PatchugoLite". Example usage below
   - 
     ```
     //Changes Bluetooth name to "Apple"
     PatchugoStatusCode checkError = patchugoLite.BT_Change_Name("Apple");
     if(checkError != PatchugoStatusCode::OK) {
      //Manage error here
     }
     ```
     
     ```
      patchugoLite.BT_Set_Mode(BTMode::TRANSPARENT);

      //WRONG!! This will fail because Bluetooth is in TRANSPARENT mode!
      PatchugoStatusCode checkError = patchugoLite.BT_Change_Name("Apple");
      if(checkError != PatchugoStatusCode::OK) {
        //Manage error here
      }
      ```

   ### Bluetooth Transmitting data

   Data transmission with this library is very easy. To transmit any data the function BT_Write must be called. The function writes a buffer of the specified         length to the Bluetooth module serial to transmit data via Bluetooth. The function only works in TRANSPARENT mode and will return an error if used in COMMAND      mode. Example usage below 
   
  ```
  uint8_t writeData[3] = {0};

  writeData[0] = 1;
  writeData[1] = 2;
  writeData[2] = 3;

  //Transmits 3 bytes buffer with Bluetooth
  PatchugoStatusCode checkError = patchugoLite.BT_Write(writeData, 3);

  if(checkError != PatchugoStatusCode::OK) {
    //Manage error here
  }
  ```

  ```
 //WRONG!! The transmit will not work in COMMAND mode!
  patchugoLite.BT_Set_Mode(BTMode::COMMAND);

  uint8_t writeData[3] = {0};

  writeData[0] = 1;
  writeData[1] = 2;
  writeData[2] = 3;

  
  PatchugoStatusCode checkError = patchugoLite.BT_Write(writeData, 3);

  if(checkError != PatchugoStatusCode::OK) {
    //Manage error here
  }
  ```

### Bluetooth receiving data
Receiving data via Bluetooth with this library is fairly easy. First a function that takes a uint8_t buffer and a uint8_t length must be created. Then that function must be passed to the library BT_Set_RXCallback function, then every time the Bluetooth receives data the user function that was passed to the library will be called. It is also really important that in the Loop of the program the BT_Update function is called The example usage is provided below
  ```
  //Define user callback function
  void my_callback(uint8_t buf[], uint8_t len) {
    //Manage data here
  }

  void setup() {
  
    Serial.begin(115200);
  
    Serial.println("TEST");
    
    patchugoLite.Init();
  
    patchugoLite.BT_Set_Mode(BTMode::TRANSPARENT);

    //Sets user function as Bluetooth RX callback
    patchugoLite.BT_Set_RXCallback(my_callback);
  
    Serial.println("TEST DONE");
   
  }

  void loop() {
    //VERY IMPORTANT! It will not work without this
    patchugoLite.BT_Update();
  }
 ```

### Full usage example
A simple example of complete usage of the Bluetooth features is provided below. The firmware listens for a command of 3 bytes from the bluetooth and if the
first byte is 0x08 it responds with 105

 ```
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

 ```
### RS485
The board has a RS485 serial made available trough the J2 connector. The library provides a simple api to control it but it's really important to mention that the serial is half-duplex meaning that it can either transmit or receive at a given time but the library provides a simple API so that it's possible to switch modes when there's a need of back and forth communication with another device. The library provides the following functions to control RS485:
- RS485_Set_Baud sets the baudrate for the serial. This function is called in the library Init function with a default value of 115200 so RS485_Set_Baud can be skipped if there isn't a need to change the baudrate from 115200. Below is an example usage
```
 //Sets baudrate to 57600
 patchugoLite.RS485_Set_Baudrate(RS485_Baud::BAUD_57600);
```
- RS485_Set_Mode sets the mode of the serial(RX or TX). In TX mode data will be transmitted but nothing can be received while in RX mode data can be received but nothing can be transmitted. Below is an example usage
```
//Sets mode to TX
patchugoLite.RS485_Set_Mode(RS485_Mode::TX);
```
- RS485_Write writes trough the RS485 serial. It's important to note that the TX mode must be set before writing otherwise the function will return an error. Below is an example usage
```
  //Sets mode to TX
  patchugoLite.RS485_Set_Mode(RS485_Mode::TX);

  uint8_t test[5] = {0};

  test[0] = 'H';
  test[1] = 'E';
  test[2] = 'L';
  test[3] = 'L';
  test[4] = 'O';

  //Writes "HELLO" trough RS485 serial
  patchugoLite.RS485_Write(test, 5);
```

### RS485 Receive data

To receive data trough RS485 serial a few steps are needed. First the RX mode must be set with RS485_Set_Mode otherwise nothing will be receive. Another important thing is to make sure to call the RS485_Update funcion in the main loop to allow the RS485 serial to keep listening. Lastly a user provided function must be set as callback for RX events on the serial. Below is an example
```
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
```
## I2C Communication
The board has an I2C connection available on pins D16 and D17. The library allows to easily write and read data from I2C peripherals with a few lines of code.

### I2C Communication setup
The first thing to do to setup the communication with the I2C device is to call the I2C_Init providing the device address as parameter. This will initialize the I2C connection and save the provided address for future communication. A usage example is provided below
```
//Initializes I2C with slave address 0x23
pathcugoLite.I2C_Init(0x23);
```
### I2C Write
To write to the slave device the I2C_Write function must be called providing a pointer to the data to write with the length of the data. Example usage below
```
//Writes 0x01 to the slave device
uint8_t cmd = 0x01;
pathcugoLite.I2C_Write(&cmd, 1);

//Writes 0x01 and 0x02 to the slave device
uint8_t cmd[2] = {0x01, 0x02};
pathcugoLite.I2C_Write(&cmd, 2);
```

### I2C Read
To read from the slave device the I2C_Read function must be called providing the address of the slave device, the length of data to read and a pointer where the data will be stored. An example usage is provided below
```
//Reads 2 bytes from device with slave address 0x23 and stores them in data
uint8_t data[2] = {0};
pathcugoLite.I2C_Read(0x23, 2, data);
```

## SPI Communication
The board has a SPI available on pins D10, D11, D12, D13. The library allows to easily write and read data from SPI devices

## SPI Communication Setup
The first thing to do to setup the SPI communication is to call the SPI_Init function and specifying the clock speed, byte order and SPI mode. A usage example is provided below
```
//Initializes SPI with a clock of 5Mhz, MSBFIRST order and SPI MODE 1(CPOL = 0 CPHA = 1)
patchugoLite.SPI_Init(5000000, MSBFIRST, SPI_MODE1);
```

## SPI Write
To write to the SPI device the SPI_Write function must be called providing a pointer to the data to write and the length of data to write. An example usage is provided below
```
//Writes the bytes 0x80 and 0xD0 to the SPI slave device
cmd[0] = 0x80;
cmd[1] = 0xD0;
patchugoLite.SPI_Write(cmd, 2);
```

## SPI Read
To read from the SPI slave device the SPI_Read function must be called providing a register address to read(or 0x00 if there isn't any), the length of data to read and a pointer where the data will be stored. An example usage is provided below
```
//Reads 2 bytes from register 0x01 and stores them in rawVal
uint8_t rawVal[2] = {0};
patchugoLite.SPI_Read(0x01, 2, rawVal);
```

# Pin mappings table

Below is the table mapping for all pins and their functions

| STM32 Pin name | Arduino Pin name | Function | PCB Reference |
| -------------- | ---------------- | -------- | ------------- |
| PE7            | D0               | GPIO/USART RX | J5 RX |
| PE8            | D1               | GPIO/USART TX | J5 TX |
| PB9            | D2               | GPIO      | J5 D2 |
| PB8            | D3               | GPIO/PWM  | J5 D3 |
| PA4            | D4               | GPIO      | J5 D4 |
| PB7            | D5               | GPIO/PWM  | J5 D5 |
| PB6            | D6               | GPIO/PWM  | J5 D6 |
| PG0            | D7               | GPIO      | J5 D7 |
| PG1            | D8               | GPIO      | J5 D8 |
| PC8            | D9               | GPIO/PWM  | J5 D9 |
| PA15           | D10              | GPIO/SPI CS/PWM | J5 CS |
| PB5            | D11              | GPIO/ SPI MOSI/PWM | J5 MOSI |
| PB4            | D12              | GPIO/SPI MISO/PWM | J5 MISO |
| PG11           | D13              | GPIO/SPI SCK | J5 SCK |
| PC9            | D14              | GPIO/I2C SDA | J5 SDA |
| PA8            | D15              | GPIO/I2C SCL | J5 SCL |
| PC3_C          | D16              | GPIO | J1 OUT 1 |
| PC1            | D17              | GPIO | J1 OUT 2 |
| PF8            | D18              | GPIO | J1 OUT 3 |
| PF6            | D19              | GPIO | J1 OUT 4 |
| PF5            | D20              | GPIO | J1 OUT 5 |
| PF4            | D21              | GPIO | J1 OUT 6 |
| PF3            | D22              | GPIO | J1 OUT 7 |
| PF2            | D23              | GPIO | J1 OUT 8 |
| PF7            | D24              | GPIO | J3 IN 1  |
| PF1            | D25              | GPIO | J3 IN 2  |
| PF0            | D26              | GPIO | J3 IN 3  |
| PE6            | D27              | GPIO | J3 IN 4  |
| PE5            | D28              | GPIO | J3 IN 5  |
| PE4            | D29              | GPIO | J3 IN 6  |
| PE3            | D30              | GPIO | J3 IN 7  |
| PE2            | D31              | GPIO | J3 IN 8  |
| PB1            | A0/D32           | GPIO/ANALOG | J25 A0 |
| PC5            | A1/D33           | GPIO/ANALOG | J25 A1 |
| PC4            | A2/D34           | GPIO/ANALOG | J25 A2 |
| PA7            | A3/D35           | GPIO/ANALOG | J25 A3 |
| PA6            | A4/D36           | GPIO/ANALOG | J25 A4 |
| PA5            | A5/D37           | GPIO/ANALOG | J25 A5 |
| PC13           | D38              | NONE        | NC     |
| PC14           | D39              | NONE        | NC     |
| PC15           | D40              | NONE        | NC     |
| PF9            | D41              | FALLING INTERRUPT   | FAULT PIN OF PCB |
| PF10           | D42              | NONE        | NC     |
| PH0            | D43              | RESERVED    | RESERVED |
| PH1            | D44              | NONE        | NC |
| PC0            | D45              | NONE        | NC |
| PC2_C          | D46              | NONE        | NC |
| PA0            | D47              | NONE        | NC |
| PA1            | D48              | NONE        | NC |
| PA2            | D49              | NONE        | NC |
| PA3            | D50              | NONE        | NC |
| PB0            | D51              | NONE        | NC |
| PB2            | D52              | NONE        | NC |
| PF11           | D53              | NONE        | NC |
| PF12           | D54              | NONE        | NC |
| PF13           | D55              | NONE        | NC |
| PF14           | D56              | NONE        | NC |
| PF15           | D57              | GPIO        | USER LED |
| PE9            | D58              | NONE        | NC |
| PE10           | D59              | GPIO/RISING INTERRUPT | USER BTN |
| PE11           | D60              | NONE        | NC |
| PE12           | D61              | NONE        | NC |
| PE13           | D62              | NONE        | NC |
| PE14           | D63              | NONE        | NC |
| PE15           | D64              | NONE        | NC |
| PB10           | D65              | RS485 TX    |    |
| PB11           | D66              | RS485 RX    |    |
| PB12           | D67              | NONE        | NC |
| PB13           | D68              | FLASH SCK   |    |
| PB14           | D69              | FLASH MISO  |    |
| PB15           | D70              | FLASH MOSI  |    |
| PD8            | D71              | NONE        | NC |
| PD9            | D72              | NONE        | NC |
| PD10           | D73              | NONE        | NC |
| PD11           | D74              | NONE        | NC |
| PD12           | D75              | RS485 DE    |    |
| PD13           | D76              | NONE        | NC |
| PD14           | D77              | NONE        | NC |
| PD15           | D78              | NONE        | NC |
| PG2            | D79              | NONE        | NC |
| PG3            | D80              | FLASH CS    |    |
| PG4            | D81              | NONE        | NC |
| PG5            | D82              | NONE        | NC |
| PG6            | D83              | NONE        | NC |
| PG7            | D84              | NONE        | NC |
| PG8            | D85              | NONE        | NC |
| PC6            | D86              | NONE        | NC |
| PC7            | D87              | NONE        | NC |
| PA9            | D88              | NONE        | NC |
| PA10           | D89              | NONE        | NC |
| PA11           | D90              | DEBUG UART RX |  |
| PA12           | D91              | DEBUG UART TX |  |
| PA13           | D92              | NONE        | SWDIO |
| PA14           | D93              | NONE        | SWCLK |
| PC10           | D94              | NONE        | NC    |
| PC11           | D95              | NONE        | NC    |
| PC12           | D96              | NONE        | NC    |
| PD0            | D97              | NONE        | NC    |
| PD1            | D98              | NONE        | NC    |
| PD2            | D99              | GPIO        | BLE RESET |
| PD3            | D100             | NONE        | NC    |
| PD4            | D101             | NONE        | NC    |
| PD5            | D102             | NONE        | NC    |
| PD6            | D103             | GPIO        | BLE MODE |
| PD7            | D104             | NONE        | NC    |
| PG9            | D105             | BLE RX      |       |
| PG10           | D106             | NONE        | NC    | 
| PG12           | D107             | BLE CTS     |       |
| PG13           | D108             | BLE RTS     |       |
| PG14           | D109             | BLE TX      |       |
| PG15           | D110             | NONE        | NC    |
| PB3            | D111             | NONE        | SWO   |
| PE0            | D112             | NONE        | NC    |
| PE1            | D113             | NONE        | NC    |

# Additional considerations
As of right now the library only allows writing to a single fixed I2C address at a time and it only allows using a single CS pin for SPI that is D10(unless the user creates their own function with another OUT pin). In the near future this will change allowing users more flexibility during developement
