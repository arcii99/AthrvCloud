//FormAI DATASET v1.0 Category: System event logger ; Style: futuristic
#include<stdio.h>
#include<time.h>

// Function to log event
void logEvent(char *event){
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    FILE *fp = fopen("eventlog.txt", "a");
    fprintf(fp, "[%s] %s\n", c_time_string, event);
    fclose(fp);
}

int main(){
    printf("\nWelcome to the C System Event Logger!\n\n");

    // Get user input for event description
    char event[100];
    printf("Enter event description: ");
    fgets(event, 100, stdin);

    // Log the event
    logEvent(event);

    printf("\nEvent successfully logged!\n\n");
    return 0;
}