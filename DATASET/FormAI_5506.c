//FormAI DATASET v1.0 Category: System event logger ; Style: post-apocalyptic
#include <stdio.h>
#include <time.h>

int main()
{
    time_t t = time(NULL);
    struct tm *local_time = localtime(&t);
    char time_buffer[80];
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", local_time);
    
    FILE *logfile = fopen("event.log", "a");
    if (logfile == NULL) {
        fprintf(stderr, "Could not open log file.\n");
        return 1;
    }
    
    fprintf(logfile, "[%s] System event detected: ", time_buffer);
    
    int event_type = rand() % 3;
    switch (event_type) {
        case 0:
            fprintf(logfile, "power outage.\n");
            break;
        case 1:
            fprintf(logfile, "malfunctioning hardware.\n");
            break;
        case 2:
            fprintf(logfile, "security breach.\n");
            break;
    }
    
    fclose(logfile);
    
    printf("System event logged successfully.\n");
    
    return 0;
}