//FormAI DATASET v1.0 Category: Weather simulation ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int weather, temperature, humidity, wind_speed;
    
    srand(time(NULL)); //Seeding the random number generator
    
    weather = rand() % 4; //0 - Sunny, 1 - Rainy, 2 - Cloudy, 3 - Stormy
    
    printf("Welcome to our Weather Simulation Program!\n\n");
    
    if(weather == 0)
    {
        printf("Today's weather is Sunny!\n");
        temperature = rand() % 30 + 20; //Assigning a temperature between 20 and 50
        humidity = rand() % 30 + 30; //Assigning a humidity between 30 and 60
        wind_speed = rand() % 10 + 5; //Assigning a wind speed between 5 and 15
        
        printf("Temperature: %d°C\n", temperature);
        printf("Humidity: %d%%\n", humidity);
        printf("Wind Speed: %d km/h\n", wind_speed);
        
        printf("\nEnjoy the sunshine and have a great day!\n");
    }
    else if(weather == 1)
    {
        printf("Today's weather is Rainy!\n");
        temperature = rand() % 10 + 15; //Assigning a temperature between 15 and 25
        humidity = rand() % 60 + 80; //Assigning a humidity between 80 and 140
        wind_speed = rand() % 10 + 5; //Assigning a wind speed between 5 and 15
        
        printf("Temperature: %d°C\n", temperature);
        printf("Humidity: %d%%\n", humidity);
        printf("Wind Speed: %d km/h\n", wind_speed);
        
        printf("\nDon't forget to bring an umbrella and stay dry!\n");
    }
    else if(weather == 2)
    {
        printf("Today's weather is Cloudy!\n");
        temperature = rand() % 15 + 10; //Assigning a temperature between 10 and 25
        humidity = rand() % 20 + 60; //Assigning a humidity between 60 and 80
        wind_speed = rand() % 10 + 5; //Assigning a wind speed between 5 and 15
        
        printf("Temperature: %d°C\n", temperature);
        printf("Humidity: %d%%\n", humidity);
        printf("Wind Speed: %d km/h\n", wind_speed);
        
        printf("\nIt might rain later, so be prepared!\n");
    }
    else
    {
        printf("Today's weather is Stormy!\n");
        temperature = rand() % 10 + 15; //Assigning a temperature between 15 and 25
        humidity = rand() % 50 + 80; //Assigning a humidity between 80 and 130
        wind_speed = rand() % 30 + 20; //Assigning a wind speed between 20 and 50
        
        printf("Temperature: %d°C\n", temperature);
        printf("Humidity: %d%%\n", humidity);
        printf("Wind Speed: %d km/h\n", wind_speed);
        
        printf("\nStay indoors and be safe!\n");
    }
    
    return 0;
}