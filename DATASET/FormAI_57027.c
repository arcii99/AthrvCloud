//FormAI DATASET v1.0 Category: Weather simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // set random seed based on current time
    
    int temperature = rand() % 41 - 10; // generate random temperature between -10 and 30 Celsius degrees
    float humidity = (rand() % 51) / 100.0; // generate random humidity between 0 and 0.5
    int windSpeed = rand() % 26; // generate random wind speed between 0 and 25 km/h
    char windDirection[4][10] = {"North", "East", "South", "West"}; // possible wind directions
    
    int randomDirectionIndex = rand() % 4; // generate random index for wind direction
    char windDir[10];
    strcpy(windDir, windDirection[randomDirectionIndex]);
    
    printf("Current weather condition:\n");
    printf("Temperature: %d Celsius degrees\n", temperature);
    printf("Humidity: %.2f\n", humidity);
    printf("Wind speed: %d km/h\n", windSpeed);
    printf("Wind direction: %s\n", windDir);
    
    // generate suggestions based on current weather conditions
    printf("\nWhat to wear:\n");
    if (temperature < 0) {
        printf("Be sure to dress in layers to stay warm\n");
        printf("Wear a thick jacket, a hat, gloves, and a scarf\n");
    } else if (temperature > 0 && temperature < 20) {
        printf("Jeans and a long-sleeved shirt will do\n");
        printf("Bring a light sweater in case it gets chilly\n");
    } else {
        printf("Wear shorts and a t-shirt\n");
        printf("Bring a hat and sunglasses to avoid sunburn\n");
    }
    
    printf("\nWhat to do:\n");
    if (humidity > 0.3) {
        printf("Go for a swim in the pool or at the beach\n");
        printf("Head to an air-conditioned place to cool off\n");
    } else {
        printf("Go for a hike or a bike ride\n");
        printf("Visit a park or a garden\n");
    }
    
    printf("\nWhat to eat and drink:\n");
    if (temperature < 0) {
        printf("Have some hot chocolate or tea\n");
        printf("Enjoy a bowl of soup or chili\n");
    } else if (temperature > 0 && temperature < 20) {
        printf("Grab a coffee or a latte\n");
        printf("Have a sandwich or a salad\n");
    } else {
        printf("Drink plenty of water to stay hydrated\n");
        printf("Have some ice cream or a cold drink\n");
    }
    
    return 0;
}