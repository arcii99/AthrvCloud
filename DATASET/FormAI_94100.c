//FormAI DATASET v1.0 Category: System event logger ; Style: relaxed
#include <stdio.h>
#include <time.h>

/* Function to get the current date/time */
char* get_timestamp() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *timestamp = asctime(tm);
    timestamp[strlen(timestamp)-1] = '\0'; // Remove newline character
    return timestamp;
}

/* Function to log an event to a file */
void log_event(char* event) {
    char* timestamp = get_timestamp();
    FILE* fp = fopen("event_log.txt", "a");
    fprintf(fp, "%s - %s\n", timestamp, event);
    fclose(fp);
}

/* Example usage */
int main() {
    log_event("System started up");
    log_event("File saved successfully");
    log_event("Connection closed by remote host");
    return 0;
}