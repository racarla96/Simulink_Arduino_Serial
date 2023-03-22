//SerialDriver.cpp 
#include "SerialDriver.h"   

#include <Arduino.h>

HardwareSerial * _HardSerial; // member within class

#define BAUDRATE 115200

const int8_t sID0 = 0;
const int8_t sID1 = 1;
const int8_t sID2 = 2;
const int8_t sID3 = 3;

extern "C" void SerialDriver_Init(int8_t serialID)
{ 
    if(serialID == sID0) {
        Serial.begin(BAUDRATE);
        _HardSerial = &Serial;
    }
    if(serialID == sID1) {
        Serial1.begin(BAUDRATE);
        _HardSerial = &Serial1;
    }
    if(serialID == sID2) {
        Serial2.begin(BAUDRATE);
        _HardSerial = &Serial2;
    }
    if(serialID == sID3) {
        Serial3.begin(BAUDRATE);
        _HardSerial = &Serial3;
    }    
} 
extern "C" void SerialDriver_Step(int8_t data_length, uint8_t *data, int8_t *status) 
{ 
    *status = 0;
    if(_HardSerial->available() >= data_length){
        *status = 1;
        for(int i=0; i<data_length; i++) *(data + i) = _HardSerial->read();
    }
    /*
    if(hedge.getRawDistancesFromMarvelmindHedge(true, &rDistancesP)){
        *status = 1;
        *d1 = (uint32_t) (rDistancesP.distances[0] * 1000.f);
        *d2 = (uint32_t) (rDistancesP.distances[1] * 1000.f);
        *d3 = (uint32_t) (rDistancesP.distances[2] * 1000.f);
        *d4 = (uint32_t) (rDistancesP.distances[3] * 1000.f);
    }
    */
} 
extern "C" void SerialDriver_Terminate() 
{ 
}