//FormAI DATASET v1.0 Category: System event logger ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    FILE *logFile; 
    char logEntry[50];
    time_t currentTime;
    struct tm *timeInfo;

    // Open log file for writing
    logFile = fopen("logFile.txt", "w");

    if (logFile == NULL) {
        printf("Error opening log file!\n");
        exit(1);
    }

    // Get current time
    currentTime = time(NULL);
    timeInfo = localtime(&currentTime);
  
    printf("Greetings worthy traveler. What event shall I record for thee?\n");
    printf("> ");
    fgets(logEntry, sizeof(logEntry), stdin);
  
    printf("Verily, %s hath occurred at %s", logEntry, asctime(timeInfo));
  
    fprintf(logFile, "AN EVENT HATH OCCURRED: %s at %s", logEntry, asctime(timeInfo));
  
    fclose(logFile);
  
    return 0;
}