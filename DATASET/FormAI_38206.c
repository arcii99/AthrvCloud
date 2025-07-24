//FormAI DATASET v1.0 Category: System event logger ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function to generate random numbers for the event id and priority */
int random_number(int min_num, int max_num) {
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num) {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    srand(time(NULL)); // seed the random number generator
    result = ( rand() % (hi_num - low_num) ) + low_num;
    return result;
}

int main() {
    /* define and initialize variables */
    int event_id = 0;
    int priority = 0;
    char timestamp[30];
    time_t rawtime;
    struct tm *timeinfo;
    
    /* get current time */
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
    
    /* generate random event id and priority */
    event_id = random_number(1000, 9999);
    priority = random_number(1, 5);
    
    /* print the event information to the console */
    printf("System Event\n");
    printf("-------------\n");
    printf("Event ID: %d\n", event_id);
    printf("Priority: %d\n", priority);
    printf("Timestamp: %s\n", timestamp);
    
    /* write the event information to a log file */
    FILE *logfile = fopen("syslog.txt", "a");
    if (logfile == NULL) {
        printf("Error: Could not open logfile.\n");
        exit(1);
    }
    fprintf(logfile, "System Event\n");
    fprintf(logfile, "-------------\n");
    fprintf(logfile, "Event ID: %d\n", event_id);
    fprintf(logfile, "Priority: %d\n", priority);
    fprintf(logfile, "Timestamp: %s\n", timestamp);
    fclose(logfile);

    return 0;
}