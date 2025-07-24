//FormAI DATASET v1.0 Category: System event logger ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* message) { // function to log events with timestamp
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("%s - %s", asctime(timeinfo), message);
}

int main() {
    char message[100];
    int choice;
    do { // menu driven program for logging events
        printf("Enter your choice:\n");
        printf("1. Login successful\n");
        printf("2. Logout successful\n");
        printf("3. File saved successfully\n");
        printf("4. Error occurred\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                logEvent("Login successful\n");
                break;
            case 2:
                logEvent("Logout successful\n");
                break;
            case 3:
                logEvent("File saved successfully\n");
                break;
            case 4:
                printf("Enter the error message: ");
                scanf("%s", message);
                logEvent(message);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    } while(1);
}