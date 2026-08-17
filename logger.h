#ifndef LOGGER_H
#define LOGGER_H
#include "monitor.h"  //included because saveInFile(data *d) uses the structure datatype which is declared in monitor.h

int openFile();

int closeFile();

int clearFile();

int saveInFile(data *d);

int writeHeader();

#endif //LOGGER_H