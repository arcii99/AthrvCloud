//FormAI DATASET v1.0 Category: System event logger ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void logEvent(char* event){
    FILE* fp;
    time_t currentTime;
    struct tm* timeInfo;
    char timestamp[20];

    time(&currentTime);
    timeInfo = localtime(&currentTime);
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", timeInfo);

    fp = fopen("event_log.txt", "a");
    fprintf(fp, "[%s]: %s\n", timestamp, event);
    fclose(fp);
}

int main(){
    printf("Welcome to My Event Logger!\n");
    char event[100];

    while(1){
        printf("Enter your event or press q to exit: ");
        fgets(event, sizeof(event), stdin);

        // Check if user wants to quit
        if(event[0] == 'q' && event[1] == '\n'){
            printf("Exiting Event Logger...\n");
            break;
        }
        
        // Add event to log
        logEvent(event);
    }

    return 0;
}