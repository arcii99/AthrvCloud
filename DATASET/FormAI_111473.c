//FormAI DATASET v1.0 Category: System event logger ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    FILE *fileptr;
    char filename[50];
    char time_str[50];
    time_t log_time;
    struct tm *log_info;
    char event[200];
    int success = 0;

    printf("Enter filename to save the log data: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strlen(filename)-1] = '\0';

    fileptr = fopen(filename, "a");
    if(fileptr == NULL) {
        perror("Error while opening the file.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the event description: ");
    fgets(event, sizeof(event), stdin);
    event[strlen(event)-1] = '\0';

    time(&log_time);
    log_info = localtime(&log_time);
    strftime(time_str, sizeof(time_str), "%c", log_info);

    fprintf(fileptr, "[%s] %s\n", time_str, event);
    success = fclose(fileptr);

    if(success != 0) {
        perror("Error while closing the file.\n");
        return EXIT_FAILURE;
    }

    printf("Event logged successfully.\n");

    return EXIT_SUCCESS;
}