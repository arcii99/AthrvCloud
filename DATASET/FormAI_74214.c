//FormAI DATASET v1.0 Category: Weather simulation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float temperature[24] = {25.5, 24.3, 23.1, 22.7, 22.9, 22.8, 22.9, 22.7, 22.3, 22.5, 22.7, 23.3, 24.1, 25.5, 26.2, 26.7, 27.1, 26.9, 26.5, 26.1, 25.7, 25.3, 25.1, 24.9};

int humidity[24] = {60, 62, 63, 63, 62, 61, 62, 63, 64, 64, 63, 61, 60, 60, 58, 57, 56, 55, 55, 54, 54, 54, 54, 55};

char* weatherType[3] = {"Sunny", "Cloudy", "Rainy"};

int main(){

    srand(time(NULL));

    printf("Welcome to Weather Simulation Program!\n");

    printf("Today's Weather Simulation:\n");

    for(int i = 0; i < 24; i++){
        printf("%d:00 Temperature: %.1fC, Humidity: %d%%, Weather Type: %s\n", i, temperature[i], humidity[i], weatherType[rand() % 3]);
    }
    return 0;
}