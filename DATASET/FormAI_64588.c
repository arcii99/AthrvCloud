//FormAI DATASET v1.0 Category: System event logger ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char *event_type, char *description);

int main()
{
    log_event("INFO", "Program started");

    int num1, num2;
    srand(time(NULL));
    num1 = rand() % 100;
    num2 = rand() % 100;

    log_event("DEBUG", "Generated random numbers");

    int result = num1 * num2;

    log_event("INFO", "Calculation completed");

    printf("The result of multiplying %d and %d is %d\n", num1, num2, result);

    log_event("INFO", "Program terminated");

    return 0;
}

void log_event(char *event_type, char *description)
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", t);

    FILE *log_file = fopen("event_log.txt", "a");
    if (log_file != NULL)
    {
        fprintf(log_file, "[%s] [%s] %s\n", timestamp, event_type, description);
        fclose(log_file);
    }
}