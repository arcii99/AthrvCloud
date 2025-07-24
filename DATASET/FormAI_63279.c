//FormAI DATASET v1.0 Category: Weather simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temp = 0;
    int humidity = 0;
    int windSpeed = 0;
    int pressure = 0;
    float windChill;

    srand((unsigned) time(NULL));

    temp = (rand() % 60) - 20;
    humidity = rand() % 101;
    windSpeed = (rand() % 20) + 1;
    pressure = (rand() % 101) + 900;
    windChill = (float) (0.0817 * (3.71 * sqrt(windSpeed) + 5.81 - 0.25 * windSpeed) * (temp - 91.4) + 91.4);

    printf("Current Temperature: %d C\n", temp);
    printf("Humidity: %d%\n", humidity);
    printf("Wind Speed: %d km/h\n", windSpeed);
    printf("Pressure: %d kPa\n", pressure);
    printf("Wind Chill: %.2f C\n", windChill);

    if(temp <= 0){
        printf("\nIt's freezing out there! Stay warm!\n");
    } else if(temp > 0 && temp <= 10){
        printf("\nIt's cold out there! Get a jacket!\n");
    } else if(temp > 10 && temp <= 20){
        printf("\nIt's cool out there! Enjoy the weather!\n");
    } else if(temp > 20 && temp <=30){
        printf("\nIt's warm out there! Enjoy the sunshine!\n");
    } else if(temp > 30){
        printf("\nIt's hot out there! Drink plenty of water!\n");
    }

    if(windSpeed > 10){
        printf("\nBeware of strong winds! Hold on tight!\n");
    }

    if(humidity >= 80){
        printf("\nIt's quite humid out there! Expect some rain!\n");
    }
    
    return 0;
}