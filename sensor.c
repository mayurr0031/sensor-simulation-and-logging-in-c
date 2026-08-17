/*
synthetic random sensor value is genearted
and sensors values are validated and filtered
*/

#include<stdlib.h>
#include "sensor.h"

float read_sensor(void){
    int reading1=rand()%1000;  //generates values from 0 to 999
    return reading1/10.0f;    //generates values from 0 to 99.99
}

int validate_reading(double input){
    if(input>=0.0 && input <= 40.0)  //return 1 if input is in range  0.0 to 40.0
     return 1;
    else
     return 0;
}

float filter(float *input,int size){ //running avg of 10 valid readings
float sum=0;
  for(int i=0;i<size;i++){
    sum+=input[i];
  }
  return sum/(float)size;
}