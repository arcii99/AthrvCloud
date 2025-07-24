//FormAI DATASET v1.0 Category: Weather simulation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//struct to define weather properties
typedef struct{
    int temperature;
    int humidity;
    char* skyCondition;
}Weather;

int main()
{
    //initialize random seed
    srand(time(0));
    printf("Welcome to Weather Simulation\n\n");

    //initialize weather object
    Weather currentWeather;

    //set initial weather condition
    currentWeather.temperature = 75 + (rand() % 15);
    currentWeather.humidity = 50 + (rand() % 10);

    //set initial sky condition
    int skyConditionNum = rand()%3;
    if(skyConditionNum == 0)
        currentWeather.skyCondition = "Clear";
    else if(skyConditionNum == 1)
        currentWeather.skyCondition = "Partly Cloudy";
    else
        currentWeather.skyCondition = "Mostly Cloudy";

    //display initial weather condition
    printf("Current Weather:\nTemperature: %d degrees\nHumidity: %d%%\nSky Condition: %s\n\n", currentWeather.temperature, currentWeather.humidity, currentWeather.skyCondition);

    //simulate weather changes for the next 24 hours
    for(int i=1; i<=24; i++)
    {
        //randomly increase or decrease temperature and humidity
        int tempChange = rand()%5;
        int humChange = rand()%3;

        //make the changes negative for half the day
        if(i<=12){
            tempChange = -tempChange;
            humChange = -humChange;
        }

        //update weather properties using random changes
        currentWeather.temperature += tempChange;
        currentWeather.humidity += humChange;

        //update sky condition
        skyConditionNum = rand()%3;
        if(skyConditionNum == 0)
            currentWeather.skyCondition = "Clear";
        else if(skyConditionNum == 1)
            currentWeather.skyCondition = "Partly Cloudy";
        else
            currentWeather.skyCondition = "Mostly Cloudy";

        //display updated weather condition
        printf("Hour %d:\nTemperature: %d degrees\nHumidity: %d%%\nSky Condition: %s\n\n", i, currentWeather.temperature, currentWeather.humidity, currentWeather.skyCondition);
    }

    printf("Thanks for using Weather Simulation! Have a nice day.\n");
    return 0;
}