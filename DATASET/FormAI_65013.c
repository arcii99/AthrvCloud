//FormAI DATASET v1.0 Category: Date and time ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *printDate(void *arg);
void *printTime(void *arg);

int main() 
{
    pthread_t thread1,thread2;
    if(pthread_create(&thread1, NULL, printDate, NULL) != 0) 
    {
        fprintf(stderr, "Error creating date thread\n");
        exit(1);
    }
    if(pthread_create(&thread2, NULL, printTime, NULL) != 0) 
    {
        fprintf(stderr, "Error creating time thread\n");
        exit(1);
    }
    if(pthread_join(thread1, NULL) != 0) 
    {
        fprintf(stderr, "Error joining date thread\n");
    }
    if(pthread_join(thread2, NULL) != 0) 
    {
        fprintf(stderr, "Error joining time thread\n");
    }
    return 0;
}

void *printDate(void *arg) 
{
    time_t rawtime;
    struct tm *timeinfo;
    char datestr[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(datestr, 80, "Today is %A, %B %d, %Y", timeinfo);
    printf("%s\n", datestr);

    pthread_exit(NULL);
}

void *printTime(void *arg) 
{
    time_t rawtime;
    struct tm *timeinfo;
    char timestr[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timestr, 80, "The current time is %I:%M:%S %p", timeinfo);
    printf("%s\n", timestr);

    pthread_exit(NULL);
}