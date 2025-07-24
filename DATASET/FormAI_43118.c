//FormAI DATASET v1.0 Category: System event logger ; Style: imaginative
//Welcome to the System Event Logger program!
//This program logs important events happening on your computer
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char event[100]; //to store the event description
    time_t t; //for current system time

    //open log file for writing
    FILE *log;
    log = fopen("event_log.txt", "a");

    printf("Welcome to the System Event Logger program!\n");
    printf("Please describe the event that occurred on your computer:\n");
    scanf("%[^\n]s", event); //take event description input from user

    //get current system time and format it
    time(&t);
    char* time_str = ctime(&t);
    time_str[strlen(time_str)-1] = '\0'; //remove newline

    //write event and timestamp to log file
    fprintf(log, "[%s] %s\n", time_str, event);

    printf("Thank you! The event has been logged.\n");

    fclose(log); //close log file

    return 0;
}