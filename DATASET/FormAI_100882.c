//FormAI DATASET v1.0 Category: Weather simulation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));
    int temp = rand()%50;
    int windSpeed = rand()%100;
    int humidity = rand()%100;
    char weatherCondition[10];
   
    if(temp > 30 && humidity > 70)
        strcpy(weatherCondition,"Thunderstorm");
    else if(temp > 25 && humidity > 80)
        strcpy(weatherCondition,"Rainy");
    else if(temp < 10 && windSpeed > 60)
        strcpy(weatherCondition,"Blizzard");
    else if(temp < 0)
        strcpy(weatherCondition,"Freezing");
    else if(temp > 30)
        strcpy(weatherCondition,"Hot");
    else if(temp > 20 && humidity > 70)
        strcpy(weatherCondition,"Cloudy");
    else
        strcpy(weatherCondition,"Sunny");

    printf("\n\n ======== Current Weather Report ======= \n\n");
    printf("\tTemperature : %d °C\n",temp);
    printf("\tWind Speed  : %d km/hr\n",windSpeed);
    printf("\tHumidity    : %d percent\n",humidity);
    printf("\tCondition   : %s\n\n",weatherCondition);
    return 0;
}