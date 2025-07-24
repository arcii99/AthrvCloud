//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Get the current time and date
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    // Generate a random temperature between -5 and 35 degrees Celsius
    srand(time(NULL));
    int temperature = rand() % 41 - 5;

    // Print the temperature and current date/time in scientific notation
    printf("Temperature Measurement\n");
    printf("------------------------------\n");
    printf("Date/time: %04d-%02d-%02d %02d:%02d:%02d\n",
           tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday,
           tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
    printf("Temperature: %d Degrees Celsius\n", temperature);

    // Determine if the temperature is within range
    if (temperature >= 20 && temperature <= 25) {
        printf("Temperature is within acceptable range\n");
    } else {
        printf("Temperature is outside of acceptable range\n");
    }

    return 0;
}