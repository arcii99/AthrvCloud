//FormAI DATASET v1.0 Category: System event logger ; Style: shocked
#include <stdio.h>
#include <time.h>

void log_event(char* event) {
    FILE *fp;
    time_t current_time;
    char* c_time_string;

    current_time = time(NULL);
    c_time_string = ctime(&current_time);

    fp = fopen("event_log.txt", "a");
    fprintf(fp, "%s - %s\n", c_time_string, event);
    fclose(fp);
}

int main() {
    char event[100];

    printf("Enter system event: ");
    scanf("%[^\n]", event);
    log_event(event);

    printf("Event Logged Successfully!\n");

    return 0;
}