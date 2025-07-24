//FormAI DATASET v1.0 Category: System event logger ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random numbers
int generateRandomNumber() {
    return rand() % 1000;
}

//Function to get current time
char* getCurrentTime() {
    time_t currentTime = time(NULL);
    char* formattedTime = asctime(localtime(&currentTime));
    formattedTime[strlen(formattedTime) - 1] = '\0';
    return formattedTime;
}

//Function to write events to file
void writeLogToFile(const char* event, const char* severity) {
    FILE* logFile = fopen("systemEventLog.txt", "a");
    fprintf(logFile, "[%s] %s: %s\n", getCurrentTime(), severity, event);
    fclose(logFile);
    printf("Event logged to file.\n");
}

int main() {
    printf("Welcome to the System Event Logger!\n");
    while(1) {
        printf("Enter the event description: ");
        char eventDescription[100];
        fgets(eventDescription, 100, stdin);
        printf("Enter the severity (info, warning, error): ");
        char severity[10];
        fgets(severity, 10, stdin);
        if(strcmp(severity, "info\n")==0 || strcmp(severity, "warning\n")==0 || strcmp(severity, "error\n")==0) {
            writeLogToFile(eventDescription, severity);
        } else {
            printf("Invalid severity level entered.\n");
        }
        printf("Press any key to log another event or 'q' to quit.\n");
        char input;
        scanf("%c", &input);
        if(input == 'q') {
            break;
        }
    }
    return 0;
}