//FormAI DATASET v1.0 Category: Weather simulation ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int temp, humidity, wind_speed, random_temp, random_humidity, random_wind_speed;
    srand(time(0));
    printf("Welcome to Weather Simulator!\n\n");

    printf("Enter the current temperature in Celsius: ");
    scanf("%d", &temp);
    printf("Enter the current humidity in percentage: ");
    scanf("%d", &humidity);
    printf("Enter the current wind speed in kmph: ");
    scanf("%d", &wind_speed);

    printf("\nSimulating weather conditions...\n\n");

    random_temp = rand() % 21 - 10;
    temp += random_temp;
    random_humidity = rand() % 21 - 10;
    humidity += random_humidity;
    random_wind_speed = rand() % 21 - 10;
    wind_speed += random_wind_speed;

    printf("Current temperature is %dC with a variation of %dC\n", temp, random_temp);
    printf("Current humidity is %d%% with a variation of %d%%\n", humidity, random_humidity);
    printf("Current wind speed is %dkmph with a variation of %dkmph\n", wind_speed, random_wind_speed);

    printf("\nSimulating weather forecast...\n\n");

    for(int i=0; i<5; i++){
        random_temp = rand() % 11 - 5;
        temp += random_temp;
        random_humidity = rand() % 11 - 5;
        humidity += random_humidity;
        random_wind_speed = rand() % 11 - 5;
        wind_speed += random_wind_speed;

        printf("Day %d: Temperature is %dC with a variation of %dC\n", i+1, temp, random_temp);
        printf("Day %d: Humidity is %d%% with a variation of %d%%\n", i+1, humidity, random_humidity);
        printf("Day %d: Wind speed is %dkmph with a variation of %dkmph\n", i+1, wind_speed, random_wind_speed);
        printf("\n");
    }

    return 0;
}