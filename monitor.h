#ifndef MONITOR_H
#define MONITOR_H
typedef enum status{ // status flag 
  NORMAL,       //0
  WARNING,     //1
  DANGER,     //2
  CRITICAL,  //3
}stat;

typedef struct data_saver{   //structure used to store reading and time_stamp and ect 
  char reading_time[26];
  float rawValue;
  float filteredValue;
  stat ALERT;
  char alertMessage[10];

}data;

stat sflag(double Value);

int saveReadings(data *d,float *avg,float input);

int print_readings(data *d);

#endif // MONITOR_H