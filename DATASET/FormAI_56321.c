//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function to travel through time */
void travelTime(int year)
{
    int i;
    time_t now;
    struct tm future;

    /* get the current time */
    now = time(NULL);

    /* set the future time */
    future = *localtime(&now);
    future.tm_year = year - 1900;

    /* countdown until future time */
    for (i=10; i>=0; i--)
    {
        printf("Travelling to year %d in T-%d seconds...\n", year, i);
        sleep(1);
    }

    /* print message upon arrival */
    printf("We have arrived in the year %d!\n", year);
}

int main()
{
    int year;

    /* ask for input from user */
    printf("What year do you want to travel to? ");
    scanf("%d", &year);

    /* travel through time */
    travelTime(year);

    return 0;
}