//FormAI DATASET v1.0 Category: System event logger ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event) {
    time_t current_time = time(NULL);
    FILE* log_file = fopen("event_log.txt", "a"); // open log file in append mode

    if(log_file != NULL) {
        fprintf(log_file, "%s: %s", ctime(&current_time), event);
        fclose(log_file); // close the log file
    }
}

int main(void) {
    printf("Welcome to the event logger!\n\n");
    char event[100];
    int choice;

    do {
        printf("What event would you like to log?\n");
        fgets(event, 100, stdin); // read input from user
        log_event(event);
        printf("\nEvent has been logged!\n\n");

        printf("Would you like to log another event?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d", &choice);
        while(getchar() != '\n'); // clear input buffer
    } while(choice == 1);

    printf("\nThank you for using the event logger. Goodbye!\n");
    return 0;
}