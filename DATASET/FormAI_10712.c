//FormAI DATASET v1.0 Category: System event logger ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char *event_description, char *location, char *timestamp) {
    FILE *file_ptr;
    char filename[20] = "logfile.txt";
    file_ptr = fopen(filename, "a");

    if (file_ptr == NULL) {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }

    fprintf(file_ptr, "%s - %s - %s\n", event_description, location, timestamp);
    fclose(file_ptr);
}

int main() {
    char event_description[100], location[100], timestamp[30];
    time_t current_time;
    struct tm * time_info;

    printf("\n\n");
    printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("| Welcome to the Event Logger! |\n");
    printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    printf("Please describe the event: ");
    fgets(event_description, 100, stdin);

    printf("Where did the event occur?: ");
    fgets(location, 100, stdin);

    current_time = time(NULL);
    time_info = localtime(&current_time);
    strftime(timestamp, 30, "%m/%d/%Y %I:%M %p", time_info);

    printf("Event logged successfully!\n\n");

    log_event(event_description, location, timestamp);

    printf("Here are all the events that have occurred:\n\n");

    FILE *file_ptr;
    char filename[20] = "logfile.txt";
    file_ptr = fopen(filename, "r");

    if (file_ptr == NULL) {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }

    char buffer[200];

    while (fgets(buffer, 200, file_ptr) != NULL) {
        printf("%s", buffer);
    }

    fclose(file_ptr);

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Thank you for using the Event Logger. Have a great day!");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return 0;
}