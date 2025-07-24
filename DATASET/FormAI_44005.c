//FormAI DATASET v1.0 Category: System event logger ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void log_event(char *event_type);

int main()
{
    printf("Welcome to the mysterious event logger\n");
    printf("Enter the event you want to log:\n");

    char event[50];

    fgets(event, 50, stdin);

    log_event(event);

    printf("Event logged successfully!\n");

    return 0;
}

void log_event(char *event_type)
{
    int secret_key = 983746;

    char *enc_event = (char *)malloc(sizeof(char) * 50);

    for (int i = 0; i < 50; i++)
    {
        enc_event[i] = event_type[i] ^ secret_key;
    }

    FILE *fp;

    fp = fopen("log.txt", "a+");

    if (fp == NULL)
    {
        printf("Log file could not be opened.\n");
        exit(1);
    }

    fprintf(fp, "Secret Code: %d, Event: %s\n", secret_key, enc_event);
    fclose(fp);

    printf("Logging event...Please wait...\n");
}