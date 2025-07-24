//FormAI DATASET v1.0 Category: System event logger ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp;
    fp=fopen("system_events.log", "a");
    time_t current_time;
    char* c_time_string;
    
    if (fp == NULL){
        printf("Error opening the file!\n");
        exit(1);
    }
    
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    
    fprintf(fp, "System Event: Program Started - %s", c_time_string);
    fclose(fp);
    
    /* Some code to simulate program executing */
    printf("Hello, World!\n");
    
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    
    fp=fopen("system_events.log", "a");
    fprintf(fp, "System Event: Program Executed Successfully - %s", c_time_string);
    fclose(fp);
    
    return 0;
}