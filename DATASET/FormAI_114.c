//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    time_t rawtime = time(NULL);
    struct tm * timeinfo = localtime(&rawtime);
    printf("Current time: %s", asctime(timeinfo));

    int years;
    printf("\nEnter number of years to travel: ");
    scanf("%d", &years);

    timeinfo->tm_year += years;
    mktime(timeinfo);

    printf("\nTime travel set to %d years from now: %s", years, asctime(timeinfo));

    return 0;
}