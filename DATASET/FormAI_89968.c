//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_URL_LENGTH 100
#define NUM_OF_URLS 3

void checkUptime(char* url);
void displayStatus(char* url, int status);
void delay(int seconds);

int main()
{
    char urls[NUM_OF_URLS][MAX_URL_LENGTH] = {"https://www.google.com", 
                                               "https://www.facebook.com", 
                                               "https://www.amazon.com"};
    int i;

    for(i = 0; i < NUM_OF_URLS; i++)
    {
        checkUptime(urls[i]);
    }

    return 0;
}

void checkUptime(char* url)
{
    int status;
    printf("Checking uptime for %s...\n", url);

    // code to ping the website and check status
    // if website is down or giving errors, set status to 0
    // if website is up, set status to 1
    // assume status is 1 for now
    status = 1;

    displayStatus(url, status);
}

void displayStatus(char* url, int status)
{
    printf("%s is ", url);
    if(status)
    {
        printf("UP\n");
    }
    else
    {
        printf("DOWN\n");
    }
}

void delay(int seconds)
{
    sleep(seconds);
    // code to delay program execution for given number of seconds
    // to avoid overloading the website with too many requests
}