//FormAI DATASET v1.0 Category: Weather simulation ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
        int temp, humidity, wind_speed, pressure;
        srand(time(0)); //Seed the random number generator
        temp = rand() % 50; //Generate random temperature between 0 to 50 degrees Celsius
        humidity = rand() % 100; //Generate random humidity between 0 to 100 percent
        wind_speed = rand() % 30; //Generate random wind speed between 0 to 30 km/hr
        pressure = rand() % 1000 + 90000; //Generate random pressure between 90000 to 91000 Pascal

        printf("Today's weather:\n");
        printf("Temperature: %dC\n", temp);
        printf("Humidity: %d%%\n", humidity);
        printf("Wind Speed: %dkm/hr\n", wind_speed);
        printf("Pressure: %dPa\n", pressure);

        if(temp >= 30 && humidity >= 80) //If temperature is over 30C and humidity over 80 percent, then there will likely be a thunderstorm

                printf("Thunderstorm warning! Stay inside and avoid any outdoor activity.");

        else if(temp >= 25 && temp < 30 && humidity >= 70) //If temperature is between 25C and 30C and humidity over 70 percent, there might be a rainfall

                printf("Light rainfall may occur. Carry an umbrella if you are going out.");

        else if(temp >= 10 && temp < 25 && wind_speed >= 20) //If temperature is between 10C and 25C and wind speed over 20 km/hr, there might be a dust storm

                printf("Warning: Dust storm! Close the windows and doors of your house.");

        else if(temp <= 0) //If temperature is below 0C, then there will likely be snowfall

                printf("Heavy snowfall may occur. Take precautions while driving on roads.");

        else if(temp >= 35) //If temperature is over 35C, then there will likely be a heatwave

                printf("Heatwave warning! Stay hydrated and avoid direct sunlight.");

        else //If none of the above conditions apply, then the weather is normal

                printf("Normal weather. Enjoy your day.");

        return 0;
}