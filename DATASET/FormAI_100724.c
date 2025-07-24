//FormAI DATASET v1.0 Category: Log analysis ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LogEntry{
    int id;
    char timestamp[25];
    char loglevel[10];
    char message[100];
};

//Initialize the Log file data
struct LogEntry logs[] = {
    {1, "2022-01-01 12:30:45", "INFO", "Starting application..."},
    {2, "2022-01-01 12:30:50", "DEBUG", "Debug message 1"},
    {3, "2022-01-01 12:30:55", "WARN", "Warning message 1"},
    {4, "2022-01-01 12:31:00", "ERROR", "Error message 1"},
    {5, "2022-01-01 12:31:05", "DEBUG", "Debug message 2"},
    {6, "2022-01-01 12:31:10", "DEBUG", "Debug message 3"},
    {7, "2022-01-01 12:31:15", "INFO", "Application started successfully."},
    {8, "2022-01-01 12:31:20", "WARN", "Warning message 2"},
    {9, "2022-01-01 12:31:25", "ERROR", "Error message 2"},
    {10, "2022-01-01 12:31:30", "INFO", "Stopping application..."},
    {11, "2022-01-01 12:35:45", "INFO", "Starting application..."},
    {12, "2022-01-01 12:35:50", "DEBUG", "Debug message 4"},
    {13, "2022-01-01 12:35:55", "DEBUG", "Debug message 5"},
    {14, "2022-01-01 12:36:00", "WARN", "Warning message 3"},
    {15, "2022-01-01 12:36:05", "ERROR", "Error message 3"},
    {16, "2022-01-01 12:36:10", "DEBUG", "Debug message 6"},
    {17, "2022-01-01 12:36:15", "INFO", "Application started successfully."},
    {18, "2022-01-01 12:36:20", "INFO", "Application stopped successfully."},
};

// Function to count log by timestamp and loglevel
void countLogsByTimeAndLevel(char timestamp[], char logLevel[]){
    int count = 0;
    for(int i=0;i<sizeof(logs)/sizeof(logs[0]);i++){
        if(strcmp(timestamp, logs[i].timestamp) == 0 && strcmp(logLevel,logs[i].loglevel) == 0){
            count++;
        }
    }
    printf("Logs count for Timestamp: %s and LogLevel: %s is : %d\n",timestamp, logLevel, count);
}

//Main function to read the above initialized logs data and count the logs by timestamp and loglevel
int main(){
    
    //Count the logs for timestamp="2022-01-01 12:30:45" and loglevel="INFO"
    countLogsByTimeAndLevel("2022-01-01 12:30:45", "INFO");

    //Count the logs for timestamp="2022-01-01 12:30:50" and loglevel="DEBUG"
    countLogsByTimeAndLevel("2022-01-01 12:30:50", "DEBUG");

    //Count the logs for timestamp="2022-01-01 12:31:00" and loglevel="WARN"
    countLogsByTimeAndLevel("2022-01-01 12:31:00", "WARN");

    //Count the logs for timestamp="2022-01-01 12:31:25" and loglevel="ERROR"
    countLogsByTimeAndLevel("2022-01-01 12:31:25", "ERROR");

    //Count the logs for timestamp="2022-01-01 12:36:15" and loglevel="INFO"
    countLogsByTimeAndLevel("2022-01-01 12:36:15", "INFO");

    return 0;
}