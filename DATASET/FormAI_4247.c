//FormAI DATASET v1.0 Category: System event logger ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* event) {
    FILE* logfile = fopen("system_events.txt", "a");
    time_t t = time(NULL);
    struct tm* now = localtime(&t);
    fprintf(logfile, "%d-%02d-%02d %02d:%02d:%02d   %s\n", 
        now->tm_year+1900, now->tm_mon+1, now->tm_mday, 
        now->tm_hour, now->tm_min, now->tm_sec, event);
    fclose(logfile);
    printf("[EVENT LOGGED] %s\n", event);
}

int main() {
    printf("=== SYSTEM EVENT LOGGER ===\n");
    printf("Enter 'exit' to quit the program.\n");
    
    char event[100];
    while (1) {
        printf("\nEnter an event: ");
        fgets(event, 100, stdin);
        event[strcspn(event, "\n")] = 0; // remove newline character
        
        if (strcmp(event, "exit") == 0) {
            printf("Exiting program...\n");
            break;
        }
        
        logEvent(event);
    }
    
    return 0;
}