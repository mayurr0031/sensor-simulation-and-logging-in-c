#include<stdlib.h>
#include "logger.h"
#include "monitor.h"
#include <stdio.h>

static FILE *fptr;     //gobal FILE pointer to pass the same FILE pointer to every function

int openFile(){
    if(fptr==NULL){
        fptr=fopen("sensor_logger.txt","a");  //opens sensor_logger.txt in append mode
        if(fptr==NULL)
            return 1;        //returns 1 if file can't open
        else
            return 0;       //return 0 if file open
    }
        return 0;
}

int closeFile(){
    if(fptr==NULL){  //if fptr is already closed it simply returns 0
        return 0;
    }else{
        fclose(fptr);
        fptr=NULL;  //set fptr to NULL
        return 0;
    }
}

int writeHeader(){
    if(fptr!=NULL){
        fprintf(fptr,"|      TIME STAMP      |      |   RawV   |  |Filteredvalue| | sFlag |  |Message|\n"); //header is to maintain neatness
        closeFile();  //close file instantly because the header should save first
        return 1;     //return 1 is file is closed
    }else {
        return 0;
    }
}


int clearFile(){
    fptr = fopen("sensor_logger.txt", "w"); //by opening the file in write mode automatically delete last data stored
    if (fptr == NULL)
    {
        return 0;
    }
    printf("Cleared!\n");
    closeFile();

    return 1;
}

int saveInFile(data *d){        
    if(fptr==NULL){              //checks fptr == null then assign value
        openFile();
        fprintf(fptr,"%s      %f       %f       %d        %s\n",d->reading_time,d->rawValue,d->filteredValue,d->ALERT,d->alertMessage);
    }else{
        fprintf(fptr,"%s      %f       %f       %d        %s\n",d->reading_time,d->rawValue,d->filteredValue,d->ALERT,d->alertMessage);
    }
    return 0;
}