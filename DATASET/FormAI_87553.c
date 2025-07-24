//FormAI DATASET v1.0 Category: System event logger ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* event, char* message);

int main(void) {
    char* event = "SYSTEM_LOG";
    srand(time(NULL));
    int randomNum = rand() % 2;
    
    if (randomNum == 0) {
        logEvent(event, "System started");
    } else {
        logEvent(event, "System crashed");
    }
    
    return 0;
}

void logEvent(char* event, char* message) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    FILE* file = fopen("system.log", "a");
    
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }
    
    fprintf(file, "%04d-%02d-%02d %02d:%02d:%02d [%s] %s\n", 
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, 
            tm.tm_hour, tm.tm_min, tm.tm_sec, event, message);
    fclose(file);
}