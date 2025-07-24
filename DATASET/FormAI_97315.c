//FormAI DATASET v1.0 Category: Weather simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to return a random integer between two numbers
int random_int(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

//function to simulate weather conditions
void simulate_weather(int initial_temp, int initial_pressure)
{
    int temp = initial_temp;
    int pressure = initial_pressure;
    int humidity = random_int(50, 100);
    int wind_speed = random_int(0, 20);
    int cloud_cover = random_int(0, 100);

    printf("Initial Temperature: %d degrees Celsius\n", initial_temp);
    printf("Initial Pressure: %d pascals\n", initial_pressure);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d km/h\n", wind_speed);
    printf("Cloud Cover: %d%%\n", cloud_cover);

    //simulate weather changes
    int count = 1;
    while(count <= 3) //simulate weather changes for three days
    {
        temp += random_int(-5, 5); //temperature can fluctuate between -5 to +5 degrees Celsius
        pressure += random_int(-50, 50); //pressure can fluctuate between -50 to +50 pascals
        humidity += random_int(-10, 10); //humidity can fluctuate between -10% to +10%
        wind_speed += random_int(-5, 5); //wind speed can fluctuate between -5 to +5 km/h
        cloud_cover += random_int(-20, 20); //cloud cover can fluctuate between -20% to +20%
        
        //limit the values of weather variables within valid ranges
        if(temp < -20)
            temp = -20;
        else if(temp > 40)
            temp = 40;
        
        if(pressure < 80000)
            pressure = 80000;
        else if(pressure > 120000)
            pressure = 120000;
        
        if(humidity < 0)
            humidity = 0;
        else if(humidity > 100)
            humidity = 100;
        
        if(wind_speed < 0)
            wind_speed = 0;
        else if(wind_speed > 50)
            wind_speed = 50;
        
        if(cloud_cover < 0)
            cloud_cover = 0;
        else if(cloud_cover > 100)
            cloud_cover = 100;

        //print out the weather conditions for the current day
        printf("\nWeather Conditions - Day %d\n", count);
        printf("Temperature: %d degrees Celsius\n", temp);
        printf("Pressure: %d pascals\n", pressure);
        printf("Humidity: %d%%\n", humidity);
        printf("Wind Speed: %d km/h\n", wind_speed);
        printf("Cloud Cover: %d%%\n", cloud_cover);

        count++;
    }
}

int main()
{
    srand(time(NULL)); //initialize random number generator with current time

    int initial_temp = random_int(-10, 30);
    int initial_pressure = random_int(90000, 110000);

    simulate_weather(initial_temp, initial_pressure);

    return 0;
}