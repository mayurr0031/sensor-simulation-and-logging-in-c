#ifndef SENSOR_H
#define SENSOR_H

float read_sensor(void);


int validate_reading(double input);


float filter(float *input,int size);

#endif // SENSOR_H
