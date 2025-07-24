//FormAI DATASET v1.0 Category: Weather simulation ; Style: mathematical
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int days,i;
    float temperature, humidity, pressure;

    printf("Enter the number of days to simulate weather: ");
    scanf("%d",&days);

    for(i = 1; i <= days; i++)
    {
        temperature = (float)rand()/RAND_MAX * 50; //Generate a random temperature between 0-50 degrees Celsius
        humidity = (float)rand()/RAND_MAX * 100; //Generate a random humidity between 0-100%
        pressure = pow((float)rand()/RAND_MAX, 2) * 1000 + 900; //Generate a random pressure using the ideal gas law

        printf("Day %d: Temperature = %.2f C, Humidity = %.2f %%, Pressure = %.2f hPa\n", i, temperature, humidity, pressure);
    }

    return 0;
}