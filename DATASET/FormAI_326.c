//FormAI DATASET v1.0 Category: System event logger ; Style: Alan Touring
#include <stdio.h>
#include <time.h>

void logEvent(char* event) {
    time_t currentTime;
    struct tm* timeInfo;
    char timeString[9];
    char dateString[11];

    time(&currentTime);
    timeInfo = localtime(&currentTime);

    strftime(timeString, sizeof(timeString), "%X", timeInfo); // HH:MM:SS format
    strftime(dateString, sizeof(dateString), "%Y-%m-%d", timeInfo); // YYYY-MM-DD format

    FILE* f = fopen("system.log", "a");

    if (f != NULL) {
        fprintf(f, "[%s %s]: %s\n", dateString, timeString, event);
        fclose(f);
    }
}

int main() {
    printf("Welcome to the System Event Logger!\n");

    while (1) {
        printf("\nType an event to log (or type 'exit' to quit): ");

        char input[100];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // remove trailing newline character

        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            logEvent(input);
            printf("Event logged.\n");
        }
    }

    return 0;
}