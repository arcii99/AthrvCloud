//FormAI DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int temperature, humidity, wind_speed, probability_of_rain;
    int i;
    srand(time(NULL)); // To provide unique number sequence for each simulation
    printf("Welcome to the Weather Simulation Program!\n\n");
    printf("Today's Weather:\n");
    printf("-----------------\n");
    printf("Temperature: ");
    temperature = rand()%50; // Generating temperature ranging from 0-49
    printf("%d degree Celsius\n",temperature);
    printf("Humidity: ");
    humidity = rand()%100; // Generating humidity ranging from 0-99
    printf("%d percent\n",humidity);
    printf("Wind Speed: ");
    wind_speed = rand()%50; // Generating wind speed ranging from 0-49
    printf("%d kmph\n",wind_speed);
    printf("Probability of Rain: ");
    probability_of_rain = rand()%101; // Generating probability of rain ranging from 0-100
    printf("%d percent\n\n",probability_of_rain);
    printf("Simulation for next 5 days:\n");
    printf("---------------------------------\n");
    for(i=1;i<=5;i++){
        printf("Day %d:\n",i);
        temperature += rand()%10-5; // Generating random temperature change of +/- 5 degree Celsius
        printf("Temperature: %d degree Celsius\n",temperature);
        humidity += rand()%10-5; // Generating random humidity change of +/- 5 percent
        printf("Humidity: %d percent\n",humidity);
        wind_speed += rand()%10-5; // Generating random wind speed change of +/- 5 kmph
        printf("Wind Speed: %d kmph\n",wind_speed);
        probability_of_rain += rand()%10-5; // Generating random probability of rain change of +/- 5 percent
        if(probability_of_rain<0) probability_of_rain=0; // If probability of rain turns out negative, setting it to 0
        if(probability_of_rain>100) probability_of_rain=100; // If probability of rain turns out greater than 100%, setting it to 100%
        printf("Probability of Rain: %d percent\n\n",probability_of_rain);
    }
    return 0;
}