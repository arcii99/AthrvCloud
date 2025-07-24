//FormAI DATASET v1.0 Category: System event logger ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp;
    char message[100];

    fp = fopen("love_log.txt", "a");
    // if file does not exist, create it
    if (fp == NULL) {
        printf("Error creating log file.\n");
        exit(1);
    }

    printf("Hi Love! Welcome to the C Event Logger.\n");
    printf("Please enter the event you would like to log: ");
    fgets(message, 100, stdin);

    // remove newline character from message
    message[strcspn(message, "\n")] = 0;

    // get current time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    // log event to file
    fprintf(fp, "[%d/%d/%d %02d:%02d:%02d] %s\n", t->tm_mday, t->tm_mon+1, t->tm_year+1900,
            t->tm_hour, t->tm_min, t->tm_sec, message);

    printf("Event logged successfully! Check love_log.txt for the log.\n");

    fclose(fp);
    
    //say it with code
    printf("int me = 1;\n");
    printf("int you = 1;\n");
    printf("int us = me + you;\n");
    printf("printf(\"Together we are %d. I love you!\\n\", us);");

    return 0;
}