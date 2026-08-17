# Embedded Sensor Monitoring and Data Logging System in C

A modular C-based sensor monitoring system that generates synthetic
sensor readings, validates them, calculates the average of multiple
valid readings, classifies the sensor condition, and stores the results
in a text file.

## Project Objective

The main objective of this project is to practice C programming concepts
by building a small embedded-style monitoring system using multiple `.c`
and `.h` files.

## Features

-   Generates synthetic sensor readings using `rand()`
-   Validates sensor readings in the range of `0.0` to `40.0`
-   Collects 10 valid sensor readings
-   Calculates the average of the valid readings
-   Classifies the filtered reading into:
    -   NORMAL
    -   WARNING
    -   DANGER
    -   CRITICAL
-   Stores reading time, raw value, filtered value, status flag, and
    message
-   Displays sensor information in the terminal
-   Saves sensor data into `sensor_logger.txt`
-   Provides a menu to print/store readings, clear stored data, or exit
-   Uses separate header and source files for modular programming

## Project Structure

``` text
Embedded-Sensor-Monitoring/
│
├── main.c
├── sensor.c
├── sensor.h
├── monitor.c
├── monitor.h
├── logger.c
├── logger.h
└── sensor_logger.txt
```

## Working Flow

``` text
Synthetic Sensor Reading
          ↓
   Validate Reading
          ↓
   Collect 10 Valid Values
          ↓
      Filter / Average
          ↓
   Threshold Detection
          ↓
   NORMAL / WARNING /
   DANGER / CRITICAL
          ↓
      Display Result
          ↓
       Save to File
```

## Sensor Module

The `sensor.c` module generates a synthetic sensor value using `rand()`.

The generated value is validated to make sure it is within the allowed
range of `0.0` to `40.0`.

The filtering function calculates the average of the collected valid
readings.

## Monitor Module

The `monitor.c` module handles the monitoring logic.

The filtered value is classified using predefined thresholds:

  Range      Status
  ---------- ----------
  0--10      NORMAL
  \>10--20   WARNING
  \>20--30   DANGER
  \>30--40   CRITICAL

The module also stores the timestamp, raw value, filtered value, status
flag, and alert message inside a structure.

## Logger Module

The `logger.c` module manages the sensor log file.

It provides functions to:

-   Open the log file
-   Close the log file
-   Write the header
-   Save sensor readings
-   Clear previous sensor data

The log file is named:

``` text
sensor_logger.txt
```

## Menu

The program provides three options:

``` text
0. Print reading in terminal and store data in text file
1. Clear data
2. EXIT
```

## Example Output

``` text
Enter your choice
0.Print reading in terminal and store data in text file
1.clear data
2.EXIT

| TIME STAMP | RawV | Filteredvalue | sFlag | Message |
Mon Aug 17 14:21:29 2026    13.600000    14.240001    1    WARNING
```

## C Concepts Practiced

This project helped me practice:

-   Functions
-   Arrays
-   Pointers
-   Structures
-   Enumerations
-   Header files
-   Multiple source files
-   Modular programming
-   File handling
-   `rand()` and `srand()`
-   Time handling
-   Conditional statements
-   `switch` statements
-   Loops
-   Type casting
-   Basic data validation
-   Function parameters
-   Return values

## Compilation

Using GCC:

``` bash
gcc main.c sensor.c monitor.c logger.c -o program.exe
```

Run:

``` bash
program.exe
```

## Future Improvements

-   Replace synthetic sensor values with a real sensor
-   Add multiple sensor types
-   Add a moving-average window that can be changed by the user
-   Add better error handling for file operations
-   Add real-time sensor hardware using ESP32 or STM32
-   Add UART communication and embedded hardware support

## What I Learned

Through this project, I learned how to divide a C program into multiple
modules and connect them using header files. I also practiced
structures, enums, pointers, arrays, filtering, file handling, and basic
sensor-monitoring logic.

This project is my first step toward understanding how similar software
can be structured for embedded systems.
