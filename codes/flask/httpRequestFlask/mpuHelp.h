#include <Arduino.h>
#include <Wire.h>

class mpuHelp{
public:
    mpuHelp();
    void read_mpu_6050_data();
    void setup_mpu_6050_registers();
    s32 getACC_X();
    s32 getACC_Y();
    s32 getACC_Z();

private:
    s32 acc_x; 
    s32 acc_y; 
    s32 acc_z; 
    s32 temperature; 
    s32 gyro_x;
    s32 gyro_y; 
    s32 gyro_z;    
};
