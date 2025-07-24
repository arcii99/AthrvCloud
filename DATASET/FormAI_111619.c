//FormAI DATASET v1.0 Category: System event logger ; Style: mind-bending
#include <stdio.h>
#include <time.h>

void logEvent(char* description, char* level){
    time_t now = time(NULL);
    char* timeStr = ctime(&now);
    timeStr[strlen(timeStr) - 1] = '\0';
    char* message = malloc(sizeof(char) * (strlen(description) + strlen(level) + 30));
    sprintf(message, "[%s] %s: %s\n", timeStr, level, description);
    FILE* fptr = fopen("event_log.txt", "a");
    fprintf(fptr, "%s", message);
    fclose(fptr);
    free(message);
}

void main() {
    printf("Welcome to the Mind-Bending System Event Logger!\n\n");

    while(1){
        printf("Please enter the description of the event:\n");
        char description[100];
        scanf("%[^\n]%*c", description);

        printf("Please enter the severity level of the event (info, warning, error):\n");
        char level[10];
        scanf("%s", level);

        logEvent(description, level);

        printf("Event logged successfully! Do you want to log another event? (Y/N): ");
        char input;
        scanf(" %c", &input);
        if (input == 'N' || input == 'n'){
            break;
        }
    }

    printf("\nThank you for using the Mind-Bending System Event Logger. Goodbye!\n");
}