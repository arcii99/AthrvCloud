//FormAI DATASET v1.0 Category: System event logger ; Style: imaginative
#include <stdio.h>
#include <time.h>

int main() {
    char event[100];
    FILE *file = fopen("event_log.txt", "a");
    time_t current_time;
    char* c_time_string;
    
    printf("Enter event: ");
    scanf("%[^\n]%*c", event);
    
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    fprintf(file, "%s: %s\n", c_time_string, event);
    fclose(file);
    
    printf("Event logged successfully.\n");
    
    return 0;
}