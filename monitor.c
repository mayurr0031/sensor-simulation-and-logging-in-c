#include<time.h>
#include "monitor.h"
#include<stdio.h>
#include<string.h>

stat sflag(double Value){   //function of return type stat to return const status flags
   
  if( (double)Value<=10.0 &&(double)Value>=0.0){
  return NORMAL;
  }else if((double)Value<=20.0 &&(double)Value>10.0)
   return WARNING;
   else if((double)Value<=30.0 &&(double)Value>20.0)
   return DANGER;
   else if((double)Value<=40.0 &&(double)Value>30.0)
   return CRITICAL;

}

int saveReadings(data *d,float *avg,float input){  //saves the reading in structure (pointer of data is passed)
    time_t time_in_sec;                            //time_t is a special data type in <time.h>
    time(&time_in_sec);                            //time in seconds is loaded
    strcpy(d->reading_time,ctime(&time_in_sec));   //ctime() is the time in string which is copied to reading_time
    d->reading_time[strcspn(d->reading_time,"\n")]=0; //last index of reading_time has "\n" so last index is assign as 0
    d->filteredValue = *avg;                         //values are assigned structer members
    d->rawValue = input;
    d->ALERT = sflag(d->filteredValue);           //status flag is assignd
    switch (d->ALERT) {
    case NORMAL:   
        strcpy(d->alertMessage,"NORMAL");       //alert messege is assigned
        break;
    case WARNING:  
        strcpy(d->alertMessage,"WARNING");  
        break;
    case DANGER:   
        strcpy(d->alertMessage,"DANGER");   
        break;
    case CRITICAL: 
        strcpy(d->alertMessage, "CRITICAL"); 
        break;
    default:       
        strcpy(d->alertMessage, "UNKNOWN");  
        break;
}
    return 0;
}


//print values in terminal 

int print_readings(data *d){
    printf("|      TIME STAMP      |      |   RawV   |  |Filteredvalue| | sFlag |  |Message|\n");
    printf("%s\t",d->reading_time);
    printf("%f\t",d->rawValue);                                
    printf("%f\t",d->filteredValue);
    printf("%d\t",d->ALERT);
    printf("%s\n\n",d->alertMessage);
}