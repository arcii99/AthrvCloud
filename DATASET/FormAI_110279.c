//FormAI DATASET v1.0 Category: System event logger ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(const char *event)
{
    // Get current time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Open log file
    FILE *log_file = fopen("events.log", "a");
    if (!log_file) {
        fprintf(stderr, "Error: Could not open log file\n");
        exit(1);
    }

    // Write event to file
    fprintf(log_file, "%04d-%02d-%02d %02d:%02d:%02d - %s\n",
            tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
            tm->tm_hour, tm->tm_min, tm->tm_sec, event);

    // Close log file
    fclose(log_file);

    printf("Event logged successfully!\n");
}

int main()
{
    const char *event1 = "User clicked the Login button";
    const char *event2 = "System started up";
    const char *event3 = "Database connection lost";
    const char *event4 = "File not found: config.ini";
    const char *event5 = "User clicked the Logout button";

    printf("Logging events...\n");

    log_event(event1);
    log_event(event2);
    log_event(event3);
    log_event(event4);
    log_event(event5);

    return 0;
}