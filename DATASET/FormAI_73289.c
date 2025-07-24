//FormAI DATASET v1.0 Category: System event logger ; Style: creative
#include <stdio.h>
#include <time.h>

void log_event(const char* event)
{
    time_t current_time;
    char* c_time_string;
    char filename[20];
    FILE *fp;
    
    time(&current_time);
    c_time_string = ctime(&current_time);
    c_time_string[strlen(c_time_string) - 1] = '\0'; // remove newline character
    
    strftime(filename, 20, "%Y-%m-%d.log", localtime(&current_time));
    
    fp = fopen(filename, "a");
    if(fp == NULL)
    {
        fprintf(stderr, "Error: could not open log file %s\n", filename);
        return;
    }
    
    fprintf(fp, "[%s] %s\n", c_time_string, event);
    fclose(fp);
}

int main()
{
    // log some events
    log_event("Program started");
    log_event("User logged in");
    log_event("User clicked on menu item");
    log_event("User logged out");
    log_event("Program ended");
    
    return 0;
}