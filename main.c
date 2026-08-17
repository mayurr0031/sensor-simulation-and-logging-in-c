/*
Synthetic sensor reading generation + validation + filtering + sensor data logging using C

This project is a modular C based system

*******Objective******
1.use rand() to produce random sensor reading.
2.create sensor.h to read sensor,validate readings and take running average 
3.create monitor.h to save reading in structure and add status flag based on filtered readings.
4.create logger.h to save the structer in file.

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "sensor.h"
#include<stdint.h>
#include "monitor.h"
#include "logger.h"

int const SIZE = 10; //max size to take moving average

data d;             //structure used to store sensor reading
float input[50]; 
float AvgReading; 
int count=0;
float sensor_reading;

//three choices are given to user 

typedef enum choice{
    PRINT_READING,             //0.print sensor reading in terminal and store in txt file
    CLEAR_DATA,               //1.data stored in txt file
    EXIT                     //2.terminate the programm
}ch;

//save 10 validate readings in array

int valid_reading_array(float *input,int size){
    int8_t validCount = 0;
    while(validCount < size){
        sensor_reading = read_sensor();                //sensor data is read
        if(validate_reading((double) sensor_reading)){ //checks whether valid or not
            input[validCount] = sensor_reading;        //valid reading is assigned to valid index
            validCount++;                              //validCount is incremented only if sensor reading is valid
        }
    }
}

int main(){
    ch c;                                               //choice
    openFile();                                         //opens the file sensor_logger.txt in "a" mode
    writeHeader();                                      //write header (column name)
    srand(time(NULL));                                  //random seed is given to srand()

    while(1){ //loop

    printf("Enter your choice\n 0.Print reading in terminal and store data in text file\n 1.clear data \n 2.EXIT\n");
    scanf("%d",&c);
    switch(c){
        case PRINT_READING:
            valid_reading_array(input,SIZE);           //function is called with parameter input(array) and SIZE =10
            AvgReading = filter(input,SIZE);           //those 10 readings are filtered (running avg)
            saveReadings(&d,&AvgReading,input[0]);     //AVGreading is saved in structure data d,Rawdata=input[0]
            print_readings(&d);                        //prints the structur members in terminal
            saveInFile(&d);                            //saves structure members in file 
            break;

        case CLEAR_DATA:
            if(clearFile()){                       //clears data stored in file and checks whether successfully deleted
                openFile();                        //if cleared opens file again
                writeHeader();                     //write header which is also cleared
            }
            break;

        case EXIT:
            closeFile();                         //close file
            return 0;                            //teminates program
        
        default:
            printf("Invalid choice!\n");
            break;

    }
 }
    closeFile();                            //if invalid choice is added close file and return 0
    return 0;
}