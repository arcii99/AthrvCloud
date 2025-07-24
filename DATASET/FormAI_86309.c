//FormAI DATASET v1.0 Category: Weather simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for temperature and humidity
const int MAX_TEMP = 40;
const int MIN_TEMP = -10;
const int MAX_HUMIDITY = 100;
const int MIN_HUMIDITY = 0;

// Function to generate a random temperature within the range
int generateTemperature(){
    srand(time(NULL));
    return (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
}

// Function to generate a random humidity within the range
int generateHumidity(){
    srand(time(NULL));
    return (rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1)) + MIN_HUMIDITY;
}

// Function to simulate a weather condition
void simulateWeather(){
    int temperature, humidity;
    temperature = generateTemperature();
    humidity = generateHumidity();
    
    printf("The current temperature is %d degrees Celsius.\n", temperature);
    printf("The current humidity is %d percent.\n", humidity);
    
    if(temperature > 30 && humidity > 60){
        printf("It is hot and humid outside. Stay hydrated.\n");
    } else if(temperature > 30){
        printf("It is hot outside. Stay cool.\n");
    } else if(temperature < 0){
        printf("It is cold outside. Bundle up.\n");
    } else{
        printf("The weather is pleasant today.\n");
    }
}

// Main function to run the simulation
int main(){
    simulateWeather();
    return 0;
}