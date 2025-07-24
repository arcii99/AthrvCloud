//FormAI DATASET v1.0 Category: System event logger ; Style: brave
#include <stdio.h>
#include <time.h>

int main()
{
    printf("System Event Logger\n\n");

    time_t t = time(NULL);
    struct tm *tm_struct = localtime(&t);
    char date_time[100];
    strftime(date_time, sizeof(date_time), "%Y-%m-%d %H:%M:%S", tm_struct);

    char event_details[100];
    printf("Enter event details: ");
    fgets(event_details, sizeof(event_details), stdin);

    FILE *fp;
    fp = fopen("event_logs.txt", "a+");

    if(fp == NULL)
    {
        printf("Error: Could not open file.");
        return 1;
    }
    
    fprintf(fp, "[%s] EVENT LOGGED: %s", date_time, event_details);

    fclose(fp);

    printf("\nEvent successfully logged to file event_logs.txt!\n");

    return 0;
}