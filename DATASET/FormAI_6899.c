//FormAI DATASET v1.0 Category: System event logger ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void write_log(char *event) {
    time_t timestamp;
    char log_entry[100];

    // Get current timestamp
    time(&timestamp);

    // Format log entry
    strftime(log_entry, sizeof(log_entry), "[%Y-%m-%d %H:%M:%S]", localtime(&timestamp));
    strcat(log_entry, " ");
    strcat(log_entry, event);
    strcat(log_entry, "\n");

    // Write log entry to file
    FILE *fp;
    fp = fopen("event_log.txt", "a");
    fprintf(fp, "%s", log_entry);
    fclose(fp);
}

int main() {
    char event[50];

    printf("Enter event: ");
    scanf("%s", event);

    write_log(event);
    printf("Event logged successfully!\n");

    return 0;
}