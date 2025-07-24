//FormAI DATASET v1.0 Category: System event logger ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char *event_msg){
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    c_time_string[strlen(c_time_string) - 1] = '\0';
    FILE *fptr;

    fptr = fopen("system_event_log.txt", "a");

    if(fptr == NULL){
        printf("Error opening file");
        exit(1);
    }
    fprintf(fptr, "[%s] %s\n", c_time_string, event_msg);

    fclose(fptr);
}

int main(){
    logEvent("System started successfully");
    logEvent("Data has been transferred to the backup server");
    return 0;
}