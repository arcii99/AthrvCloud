//FormAI DATASET v1.0 Category: System event logger ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(const char* event)
{
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char datetime[20];
    strftime(datetime, 20, "%Y-%m-%d %H:%M:%S", t);
    
    FILE* f = fopen("event_log.txt", "a");
    if(f == NULL){
        printf("Error opening the file\n");
        return;
    }
    
    fprintf(f, "%s - %s\n", datetime, event);
    fclose(f);
}

int main()
{
    printf("Welcome to the Genius System Event Logger!\n");
    printf("Enter the event you want to log (max 100 characters):\n");
    char event[101];
    fgets(event, 101, stdin);
    
    // remove the newline character from the string
    int length = strlen(event);
    if(length > 0 && event[length-1] == '\n'){
        event[length-1] = '\0';
    }
    
    log_event(event);
    
    printf("Event logged successfully!\n");
    return 0;
}