#ifndef  MQ3_Senor_ 
#define MQ3_Sensor_

#include "Arduino.h"

class MQ3 {
private: 
float R0 = 16000;                 //Ro is initialized to 16 kilo ohms
int R2 = 1000;                    //R2 in the module is 1 kilo ohms
int MQ_PIN=A0;                                      //define which analog input channel you are going to use
int RL_VALUE;                                     //define the load resistance on the board, in kilo ohms
float RO_CLEAN_AIR_FACTOR=60;                     //RO_CLEAR_AIR_FACTOR=(Sensor resistance in clean air)/RO,
                                                    //which is derived from the chart in datasheet
float sensor_volt; 
float RS_gas;
float ratio;
float alcohol;

float calculate_RS();          // calculate sensor resistance from voltage; 

public:
MQ3();
void setupMQ3(int pin,int R_2); 
float calibrateMQ3();               //update the R0 value in present environment; 
float getAlcohol();

};


#endif