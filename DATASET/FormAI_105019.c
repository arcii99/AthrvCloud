//FormAI DATASET v1.0 Category: System event logger ; Style: light-weight
#include <stdio.h>
#include <time.h>

void log_event(char* event, char* type) {
    FILE *log_file = fopen("system.log", "a");
    time_t current_time;
    struct tm * time_info;
    time(&current_time);
    time_info = localtime(&current_time);
    char time_string[20];
    strftime(time_string, 20, "%Y-%m-%d %H:%M:%S", time_info);
    fprintf(log_file, "%s [%s] %s\n", time_string, type, event);
    fclose(log_file);
}

int main() {
    char event[100], type[10];
    printf("Enter event: ");
    fgets(event, 100, stdin);
    printf("Enter type (INFO, WARNING, ERROR): ");
    scanf("%s", type);
    log_event(event, type);
    printf("Event logged successfully!");
    return 0;
}