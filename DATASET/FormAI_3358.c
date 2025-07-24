//FormAI DATASET v1.0 Category: System event logger ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

/* Event structure to hold the event details */
typedef struct event {
    char time_stamp[30];
    char description[100];
} Event;

/* Function to return the current system time */
void get_time(char* str_time) {
    time_t raw_time;
    time(&raw_time);
    struct tm* time_info = localtime(&raw_time);
    strftime(str_time, 30, "[%Y-%m-%d %H:%M:%S]", time_info);
}

/* Function to write the event to the log file */
void log_event(Event event) {
    FILE* log_file = fopen("event_log.txt", "a");
    fprintf(log_file, "%s %s\n", event.time_stamp, event.description);
    fclose(log_file);
}

int main() {
    char choice = 'y';
    Event event;

    printf("\n*** WELCOME TO SYSTEM EVENT LOGGER ***\n\n");

    while (choice == 'y' || choice == 'Y') {
        printf("Enter event description: ");
        fflush(stdin);
        fgets(event.description, 100, stdin);
        event.description[strcspn(event.description, "\n")] = 0;
        get_time(event.time_stamp);
        log_event(event);
        
        printf("Do you want to log another event? (Y/N): ");
        scanf(" %c", &choice);
    }

    printf("\nThank you for using the System Event Logger!\n\n");
    return 0;
}