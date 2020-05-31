#include "mpuHelp.h"
#include <ESP8266WiFi.h>

mpuHelp::mpuHelp(){
    this->acc_x = 0; 
    this->acc_y = 0; 
    this->acc_z = 0; 
    this->temperature = 0; 
    this->gyro_x = 0;
    this->gyro_y = 0; 
    this->gyro_z = 0;
}

void mpuHelp::setup_mpu_6050_registers(){
   // Activate the MPU-6050
    Wire.beginTransmission(0x68);  // Start communicating with the MPU-6050
    Wire.write(0x6B);              // Send the requested starting register
    Wire.write(0x00);              // Set the requested starting register
    Wire.endTransmission();        // End the transmission
    // Configure the accelerometer (+/-8g)
    Wire.beginTransmission(0x68);  // Start communicating with the MPU-6050
    Wire.write(0x1C);              // Send the requested starting register
    Wire.write(0x10);              // Set the requested starting register
    Wire.endTransmission();        // End the transmission
    // Configure the gyro (500dps full scale)
    Wire.beginTransmission(0x68);  // Start communicating with the MPU-6050
    Wire.write(0x1B);              // Send the requested starting register
    Wire.write(0x08);              // Set the requested starting register
    Wire.endTransmission();        // End the transmission 
}

void mpuHelp::read_mpu_6050_data(){
    Wire.beginTransmission(0x68);  // Start communicating with the MPU-6050
    Wire.write(0x3B);              // Send the requested starting register
    Wire.endTransmission();        // End the transmission
    Wire.requestFrom(0x68, 14);    // Request 14 bytes from the MPU-6050
    while (Wire.available() < 14)
        ;  // Wait until all the bytes are received
    this->acc_x = Wire.read() << 8 |
            Wire.read();  // Add the low and high byte to the acc_x variable
    this->acc_y = Wire.read() << 8 |
            Wire.read();  // Add the low and high byte to the acc_y variable
    this->acc_z = Wire.read() << 8 |
            Wire.read();  // Add the low and high byte to the acc_z variable
    this->temperature =
        Wire.read() << 8 |
        Wire.read();  // Add the low and high byte to the temperature variable
    this->gyro_x = Wire.read() << 8 |
             Wire.read();  // Add the low and high byte to the gyro_x variable
    this->gyro_y = Wire.read() << 8 |
             Wire.read();  // Add the low and high byte to the gyro_y variable
    this->gyro_z = Wire.read() << 8 |
             Wire.read();  // Add the low and high byte to the gyro_z variable
}

s32 mpuHelp::getACC_X(){
    return this->acc_x;
}

s32 mpuHelp::getACC_Y(){
    return this->acc_y;
}

s32 mpuHelp::getACC_Z(){
    return this->acc_z;
}