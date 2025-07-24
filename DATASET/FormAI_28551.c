//FormAI DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0)); //seeding random number generator using system time

    //Weather simulation variables
    int temperature = 25; //in Celsius
    int humidity = 60; //in percentage
    int wind_speed = 10; //in kmph
    int clouds = rand()%101; //random clouds coverage percentage 
    int is_rainy = 0; //binary flag to indicate rain status
    int is_snowy = 0; //binary flag to indicate snow status

    printf("Welcome to your own Weather Simulation Program!\n\n");

    //Running weather simulation for 7 days
    for(int day=1; day<=7; day++)
    {
        printf("Day %d Weather Report:\n",day);
        printf("Temperature: %d Celsius\n", temperature);
        printf("Humidity: %d %%\n", humidity);
        printf("Wind Speed: %d kmph\n", wind_speed);

        if(clouds >= 50 && rand()%2 == 0) //50% chance of rain if clouds coverage is over 50%
        {
            is_rainy = 1;
            printf("Looks like it's going to rain today!\n");
        }

        if(temperature <= 0 && clouds >= 50 && rand()%2 == 0) //50% chance of snow if temperature is below freezing and clouds coverage is over 50%
        {
            is_snowy = 1;
            printf("Looks like it's going to snow today!\n");
        }

        if(is_rainy || is_snowy)
        {
            humidity += rand()%26 + 5; //5-30% increase in humidity range during rainfall or snowfall
            wind_speed += rand()%11; //0-10 kmph increase in wind speed range during rainfall or snowfall
        }
        else
        {
            humidity -= rand()%26 + 5; //5-30% decrease in humidity range during sunny or cloudy weather
            wind_speed -= rand()%11; //0-10 kmph decrease in wind speed range during sunny or cloudy weather

            if(wind_speed < 0) //minimum wind speed should be 0
                wind_speed = 0;
        }

        //Re-setting binary flags to 0 for next day's weather simulation
        is_rainy = 0;
        is_snowy = 0;

        //Randomizing temperature change between -5 to 5 Celsius each day
        temperature += rand()%11 - 5;

        //Ensuring temperature remains within comfortable range of 10 to 35 Celsius
        if(temperature < 10)
            temperature = 10;
        else if(temperature > 35)
            temperature = 35;

        //Ensuring humidity remains within 0 to 100 percentage range
        if(humidity < 0)
            humidity = 0;
        else if(humidity > 100)
            humidity = 100;

        //Ensuring wind speed remains within 0 to 50 kmph range
        if(wind_speed > 50)
            wind_speed = 50;
        
        printf("Clouds Coverage: %d %%\n", clouds);
        printf("\n");
        clouds = rand()%101; //Randomizing clouds coverage for next day's weather simulation
    }

    printf("Thank you for using our Weather Simulation Program. Hope you enjoyed the weather variations!\n");

    return 0;
}