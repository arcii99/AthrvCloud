//FormAI DATASET v1.0 Category: System event logger ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp;
    fp = fopen("system_events.txt", "w");
    
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    
    time_t current_time;
    struct tm * time_info;
    char time_string[30];
    
    time(&current_time);
    time_info = localtime(&current_time);
    
    strftime(time_string, sizeof(time_string), "%d-%m-%Y %H:%M:%S", time_info);
    
    fprintf(fp, "System event recorded on %s\n", time_string);
    
    // Simulate some events and log them
    
    int i;
    for(i = 0; i < 10; i++) {
        time(&current_time);
        time_info = localtime(&current_time);
        
        strftime(time_string, sizeof(time_string), "%d-%m-%Y %H:%M:%S", time_info);
        
        fprintf(fp, "Event %d occurred on %s\n", i, time_string);
    }
    
    fclose(fp);
    
    printf("System events have been logged to system_events.txt\n");
    
    return 0;
}