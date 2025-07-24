//FormAI DATASET v1.0 Category: System event logger ; Style: Cyberpunk
#include<stdio.h>
#include<time.h>

void log_message(char* event, char* message){
    FILE *f;
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    f = fopen("event_log.txt", "a");
    fprintf(f, "%s - %s: %s\n", c_time_string, event, message);
    fclose(f);
}

int main(){
    char event[50];
    char message[150];
    printf("Enter event: ");
    fgets(event, 50, stdin);
    printf("Enter message: ");
    fgets(message, 150, stdin);
    log_message(event, message);
    printf("Logging successful.\n");
    return 0;
}