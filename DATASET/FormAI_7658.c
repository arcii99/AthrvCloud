//FormAI DATASET v1.0 Category: System event logger ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char *eventName, char *eventData)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    FILE *fp;
    fp = fopen("event.log", "a+");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(fp, "%d-%02d-%02d %02d:%02d:%02d - %s: %s\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, eventName, eventData);
    fclose(fp);
}

int main()
{
    logEvent("SYSTEM_START", "The system has started");
    logEvent("USER_LOGIN", "User 'JohnDoe' has logged in");
    logEvent("PAYMENT_RECEIVED", "Payment of $50 via credit card received");
    logEvent("FILE_UPLOAD", "File 'report.pdf' uploaded to server");
    logEvent("SYSTEM_SHUTDOWN", "The system is shutting down");

    return 0;
}