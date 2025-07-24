//FormAI DATASET v1.0 Category: System event logger ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct {
    time_t timestamp;
    char* event;
} event_log;

event_log logs[MAX_EVENTS];
int log_count = 0;

void log_event(char* event) {
    if (log_count >= MAX_EVENTS) {
        printf("Error: Maximum log limit reached\n");
        return;
    }
    time_t current_time;
    time(&current_time);
    logs[log_count].timestamp = current_time;
    logs[log_count].event = event;
    log_count += 1;
}

void print_logs() {
    if(log_count == 0){
        printf("No logs available");
        return;
    }
    printf("%-25s %-50s\n", "Timestamp", "Event");
    for(int i=0; i<log_count; i++){
        struct tm* time_info = localtime(&logs[i].timestamp);
        char time_str[128];
        strftime(time_str, 128, "%Y-%m-%d %H:%M:%S", time_info);
        printf("%-25s %-50s\n", time_str, logs[i].event);
    }
}

int main() {
    printf("Welcome to Event Logger\n");
    while(1){
        printf("Enter the event to log (Q to quit): ");
        char input[256];
        fgets(input, 256, stdin);
        if(input[0] == 'Q' || input[0] == 'q'){
            printf("Exiting...\n");
            exit(0);
        }
        log_event(input);
        print_logs();
    }
    return 0;
}