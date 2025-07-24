//FormAI DATASET v1.0 Category: Weather simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random temperature
float generate_temperature()
{
    float temperature = 0.0;
    // Generating Temperature between -10°C to 40°C randomly
    temperature = (float)(rand() % 51) - 10.0;
    return temperature;
}

// Function to generate random humidity
int generate_humidity()
{
    int humidity = 0;
    // Generating Humidity between 0% to 100% randomly
    humidity = rand() % 101;
    return humidity;
}

// Function to generate random wind speed
float generate_wind_speed()
{
    float wind_speed = 0.0;
    // Generating Wind Speed between 0 m/s to 50 m/s randomly
    wind_speed = (float)(rand() % 51);
    return wind_speed;
}

// Function to print weather on screen
void print_weather(int day, float temperature, int humidity, float wind_speed)
{
    printf("Day %d's Weather Report:\n", day);
    printf("Temperature: %.2f °C\n", temperature);
    printf("Humidity: %d %%\n", humidity);
    printf("Wind Speed: %.2f m/s\n", wind_speed);
    printf("\n");
}

int main()
{
    srand(time(0)); // Seeding the random function to generate truly random numbers
    int no_of_days = 7; // Number of days to simulate weather for
    int i;
    float temperature;
    int humidity;
    float wind_speed;

    // Looping for number of days to generate weather report
    for(i = 1; i <= no_of_days; i++)
    {
        temperature = generate_temperature();
        humidity = generate_humidity();
        wind_speed = generate_wind_speed();

        // Displaying Weather Report
        print_weather(i, temperature, humidity, wind_speed);
    }

    return 0;
}