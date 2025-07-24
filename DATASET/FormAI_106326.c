//FormAI DATASET v1.0 Category: Log analysis ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

struct LogEntry {
    //struct to store the log entry
    char timestamp[25];
    char message[100];
};

int main() {
    FILE *file_pointer;
    struct LogEntry log;
    int isAnyEntryFound = 0;

    //open the log file in read-only mode
    file_pointer = fopen("myLogFile.log","r");

    //check if the file exists or not
    if(file_pointer == NULL) {
        printf("Failed to open the log file.\n");
        exit(1);
    }

    //process every line in the log file
    while(fscanf(file_pointer,"%[^,],%[^\n]\n", log.timestamp, log.message) == 2) {
        if(strcmp(log.message,"ERROR") == 0) {
            //print timestamp and message
            printf("Timestamp: %s, Message: %s\n", log.timestamp, log.message);
            isAnyEntryFound = 1;
        }
    }

    //close the log file
    fclose(file_pointer);

    if(!isAnyEntryFound) {
        printf("No error found in the log file.\n");
    }

    return 0;
}