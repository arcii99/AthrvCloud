//FormAI DATASET v1.0 Category: System event logger ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void log_event(char *event){
    FILE *log_file;
    log_file = fopen("system_logs.txt", "a");
    if(log_file == NULL){
        printf("Could not open log file!");
        exit(1);
    }
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    fprintf(log_file, "[%s] %s\n", c_time_string, event);
    fclose(log_file);
}

int main(){
    printf("Starting system logger...\n\n");
    log_event("System logger started");
    //simulate some events
    int i;
    for(i=0;i<10;i++){
        int event_type = rand()%3;
        char* event;
        switch(event_type){
            case 0:
                event = "Network disconnected";
                break;
            case 1:
                event = "File saved successfully";
                break;
            case 2:
                event = "Memory allocation failed";
                break;
        }
        log_event(event);
        printf("%s\n", event);
        sleep(1);
    }
    log_event("System logger stopped");
    printf("\nSystem logger stopped");
    return 0;
}