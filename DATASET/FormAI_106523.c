//FormAI DATASET v1.0 Category: System event logger ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char *eventDesc, char *filePath) {
    FILE *file;
    time_t epoch_time;
    struct tm *tm_p;
    char timestamp[25];

    epoch_time = time(NULL);
    tm_p = localtime(&epoch_time);
    strftime(timestamp, 25, "%Y-%m-%d %H:%M:%S", tm_p);

    file = fopen(filePath, "a");
    if (file == NULL) {
       printf("Error opening file!\n");
       exit(1);
    }

    fprintf(file, "%s - %s\n", timestamp, eventDesc);

    fclose(file);
}

int main() {
    char eventDescription[100];
    char filePath[100];

    printf("Enter event description: ");
    fgets(eventDescription, 100, stdin);

    printf("Enter file path for log: ");
    fgets(filePath, 100, stdin);

    logEvent(eventDescription, filePath);

    return 0;
}