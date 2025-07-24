//FormAI DATASET v1.0 Category: System event logger ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE* logFile = fopen("eventLogger.txt", "a");
    if(logFile == NULL) {
        printf("Error opening file!");
        return 1;
    }
    
    time_t currentTime = time(NULL);
    char* timestamp = ctime(&currentTime);
    
    fprintf(logFile, "System Event: Application Started\nTimestamp: %s\n\n", timestamp);
    
    // Simulation of events for the sake of example
    int eventCount = 5;
    char* events[] = {"System Shutdown", "Critical Error Occurred", "Application Crashed", "Authentication Failure", "Resource Allocation Failure"};
    char* levels[] = {"Information", "Warning", "Error", "Critical"};
    srand(time(NULL));
    
    for(int i = 0; i < eventCount; i++) {
        int randomEventIndex = rand() % eventCount;
        int randomLevelIndex = rand() % 4; // We have 4 levels of events
        
        currentTime = time(NULL);
        timestamp = ctime(&currentTime);
        
        fprintf(logFile, "System Event: %s\nLevel: %s\nTimestamp: %s\n\n", events[randomEventIndex], levels[randomLevelIndex], timestamp);
        
        // Give the program some rest before the next loop iteration
        int waitTime = rand() % 5;
        printf("Waiting for %d seconds before the next event...\n", waitTime);
        sleep(waitTime);
    }
    
    fprintf(logFile, "System Event: Application Closed\nTimestamp: %s\n\n", ctime(&currentTime));
    fclose(logFile);
    return 0;
}