//FormAI DATASET v1.0 Category: System event logger ; Style: visionary
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define EVENT_LOG_FILENAME "event.log"

/* Function prototypes */
void log_event(const char* event_message);

/* Global variables */
FILE* event_log_file;

int main(int argc, char** argv) 
{
    /* Open event log file */
    event_log_file = fopen(EVENT_LOG_FILENAME, "a");
    if (event_log_file == NULL) 
    {
        printf("Failed to open event log file: %s\n", EVENT_LOG_FILENAME);
        return EXIT_FAILURE;
    }

    /* Log an event */
    log_event("Program started.");

    /* Simulate program running for some time */
    srand(time(NULL));
    for (int i = 0; i < 10; i++) 
    {
        int random_num = rand() % 100;
        if (random_num < 50) 
        {
            log_event("Random event occurred.");
        } 
        else 
        {
            log_event("Another random event occurred.");
        }
        printf("Program running... (%d/10)\n", i+1);
        sleep(1);
    }

    /* Log another event */
    log_event("Program ended.");

    /* Close event log file */
    fclose(event_log_file);
    return EXIT_SUCCESS;
}

void log_event(const char* event_message) 
{
    /* Get current timestamp */
    time_t now = time(NULL);
    struct tm* now_tm = localtime(&now);
    char timestamp_str[20];
    strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", now_tm);

    /* Write event to file */
    fprintf(event_log_file, "[%s] %s\n", timestamp_str, event_message);
}