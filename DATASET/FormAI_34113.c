//FormAI DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 40
#define MIN_TEMPERATURE -10
#define MAX_HUMIDITY 100
#define MIN_HUMIDITY 0

int main()
{
    srand(time(NULL)); // seed the random number generator with current time
    int temperature = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE; // generate a random temperature between MIN_TEMPERATURE and MAX_TEMPERATURE
    int humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY; // generate a random humidity between MIN_HUMIDITY and MAX_HUMIDITY
    
    printf("Today's weather conditions:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d %%\n", humidity);
    
    if (temperature > 30 && humidity > 60) // it's hot and humid
    {
        printf("It's hot and humid today, make sure to stay hydrated.\n");
    }
    else if (temperature < 0) // it's freezing
    {
        printf("It's freezing outside, make sure to bundle up.\n");
    }
    else if (humidity > 80) // it's very humid
    {
        printf("It's very humid today, you might want to stay indoors.\n");
    }
    else if (temperature > 25 && temperature <= 30 && humidity <= 60) // it's warm and dry
    {
        printf("It's warm and dry today, what a perfect day for outdoor activities.\n");
    }
    else if (temperature > 20 && temperature <= 25 && humidity <= 60) // it's mild and dry
    {
        printf("It's mild and dry today, a great day for a picnic.\n");
    }
    else // it's neither hot nor cold, neither dry nor humid
    {
        printf("It's just an average day, enjoy it.\n");
    }
    
    return 0;
}