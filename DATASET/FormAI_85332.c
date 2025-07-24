//FormAI DATASET v1.0 Category: System event logger ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event, char* message) {
    FILE* file = fopen("system_log.txt", "a");
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    fprintf(file, "[%s] %s: %s\n", asctime(timeinfo), event, message);
    fclose(file);
}

int main() {
    printf("Welcome to our System Event Logger!\n\n");

    char event[50];
    char message[256];

    printf("Please enter the event name: ");
    fgets(event, 50, stdin);

    printf("Please enter the event message: ");
    fgets(message, 256, stdin);

    log_event(event, message);

    printf("\nEvent logged successfully!\n");

    return 0;
}