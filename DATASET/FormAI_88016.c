//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 100
#define MAX_EVENTS 100
#define MAX_TIME_DIFF 10

typedef struct{
    char* event_name;
    time_t timestamp;
    int event_code;
} event;

int main(){
    char input[MAX_INPUT_LEN];
    int event_count = 0;
    event events[MAX_EVENTS];

    while(1){
        printf("Enter event name: ");
        fgets(input, MAX_INPUT_LEN, stdin);
        input[strcspn(input, "\n")] = 0;

        if(strcmp(input, "exit") == 0){
            break;
        }

        time_t current_time = time(NULL);
        
        int event_code = rand() % 100;
        
        if(event_count > 0){
            time_t last_time = events[event_count - 1].timestamp;
            if(difftime(current_time, last_time) < MAX_TIME_DIFF){
                printf("Intrusion detected!\n");
                exit(0);
            }
        }

        events[event_count].event_name = strdup(input);
        events[event_count].timestamp = current_time;
        events[event_count].event_code = event_code;

        event_count++;
    }

    printf("Program exited\n");
    return 0;
}