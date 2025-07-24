//FormAI DATASET v1.0 Category: Temperature monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float temp = 0.0;
    int count = 0;
    float total = 0.0;
    float avg;

    printf("Welcome to the Temperature Monitor Program\n\n");
    printf("How many temperature readings would you like to input today? ");
    scanf("%d", &count);

    for(int i = 1; i <= count; i++)
    {
        printf("Enter temperature reading %d: ", i);
        scanf("%f", &temp);
        total += temp;
    }

    avg = total/count;
    printf("\nAverage temperature for the day: %.2f degrees Celsius\n\n", avg);

    if(avg >= 25)
    {
        printf("It's pretty hot today! Make sure to stay hydrated and keep yourself cool.\n");
    }
    else if(avg < 25 && avg >= 15)
    {
        printf("Today's temperature is comfortable. Enjoy your day!\n");
    }
    else
    {
        printf("It's pretty cold today! Make sure to dress warmly and stay indoors if possible.\n");
    }

    // records date and time for monitoring purposes
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    printf("\nDate and time recorded: %s", asctime(timeinfo));

    return 0;
}