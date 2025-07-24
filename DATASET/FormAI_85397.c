//FormAI DATASET v1.0 Category: Weather simulation ; Style: safe
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define MAX_CITIES 10 // Maximum number of cities in the simulation
#define MAX_READINGS 1440 // Maximum number of weather readings in a day (one reading every minute)

typedef struct{
    int temperature;
    int humidity;
} Reading;

typedef struct{
    char name[20];
    Reading readings[MAX_READINGS];
} City;

int main(){
    srand(time(NULL)); // seed random number generator with current time

    City cities[MAX_CITIES]; // array of cities in the simulation
    int num_cities; // number of cities in the simulation
    int num_days; // number of days to simulate
    int i, j, k; // loop variables

    // Get input from user
    printf("Enter the number of cities to simulate (maximum %d): ", MAX_CITIES);
    scanf("%d", &num_cities);
    num_cities = num_cities > MAX_CITIES ? MAX_CITIES : num_cities; // enforce maximum number of cities

    printf("Enter the number of days to simulate: ");
    scanf("%d", &num_days);

    // Initialize city names
    for(i=0; i<num_cities; i++){
        printf("Enter the name of city #%d: ", i+1);
        scanf("%s", cities[i].name);
    }
    
    // Generate temperature and humidity readings for each city for each day
    for(i=0; i<num_cities; i++){
        for(j=0; j<num_days; j++){
            for(k=0; k<MAX_READINGS; k++){
                cities[i].readings[k].temperature = rand() % 61 - 20; // Temperature range: -20 to 40 degrees Celsius
                cities[i].readings[k].humidity = rand() % 101; // Humidity range: 0 to 100%
            }
        }
    }

    // Print weather report for each city for each day
    for(i=0; i<num_cities; i++){
        printf("\nWeather report for %s:\n", cities[i].name);
        for(j=0; j<num_days; j++){
            printf("\nDay %d:\n", j+1);
            for(k=0; k<MAX_READINGS; k++){
                printf("Time %02d:%02d - Temperature: %2dC - Humidity: %2d%%\n", k/60, k%60, cities[i].readings[k].temperature, cities[i].readings[k].humidity);
            }
        }
    }

    return 0;
}