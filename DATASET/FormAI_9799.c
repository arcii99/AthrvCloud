//FormAI DATASET v1.0 Category: System event logger ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOGFILE "events.log"

void logEvent(char* event, char* level);

int main(){
    char* event = "Program started";
    logEvent(event, "INFO");

    // Simulating some program execution
    srand(time(NULL));
    int r;
    for(int i=0; i<10; i++){
        r = rand() % 100;
        if(r < 50){
            logEvent("Random number is less than 50", "DEBUG");
        }else{
            logEvent("Random number is greater or equal to 50", "DEBUG");
        }
    }

    // Simulating an error
    char* errMsg = "Could not open file";
    logEvent(errMsg, "ERROR");

    return 0;
}

void logEvent(char* event, char* level){
    time_t now = time(NULL);
    char* timestamp = ctime(&now);
    timestamp[strlen(timestamp)-1] = '\0'; // removing newline character from timestamp

    // Opening logfile
    FILE *fp = fopen(LOGFILE, "a");
    if(fp == NULL){
        printf("Error opening logfile!\n");
        exit(1);
    }

    // Writing event to logfile
    fprintf(fp, "%s %s %s\n", timestamp, level, event);

    // Closing logfile
    fclose(fp);
}