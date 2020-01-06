#include "Arduino.h"
#include "MQ3_alcohol.h"

MQ3::MQ3() {}

void MQ3::setupMQ3(int pin,int R_2) {
MQ_PIN = pin;
R2 = R_2;
}

float MQ3::calculate_RS(){
int value;
float RS;
value = analogRead(MQ_PIN);
sensor_volt = ((float) value / 1024 )* 5.0; 
RS = ((5.0 * R2)/sensor_volt) - R2; 
return RS;
}

float MQ3::calibrateMQ3() {  

RS_gas = calculate_RS();
R0 = RS_gas / RO_CLEAN_AIR_FACTOR;
return R0;                 
}


float MQ3::getAlcohol(){
RS_gas = calculate_RS();
ratio = RS_gas/R0;
double x = 0.4 * ratio;
alcohol = pow(x,-1.431);    ///alcohol in mg/L
return alcohol; 
}