//FormAI DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int get_random_num(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

int main(void) {
    srand(time(NULL));   // Seed the random number generator with current time

    int temperature = get_random_num(10, 40);   // Generate random temperature between 10 and 40
    int humidity = get_random_num(50, 100);     // Generate random humidity between 50 and 100
    int wind_speed = get_random_num(0, 30);     // Generate random wind speed between 0 and 30
    int wind_direction = get_random_num(0, 360);  // Generate random wind direction between 0 and 360

    // Print the weather simulation details
    printf("*** Weather Simulation Details ***\n");
    printf("Temperature: %d C\n", temperature);
    printf("Humidity: %d %%\n", humidity);
    printf("Wind Speed: %d km/h\n", wind_speed);
    printf("Wind Direction: %d degree\n", wind_direction);

    // Determine the weather conditions based on the simulation details
    if (temperature >= 30 && humidity >= 70 && wind_speed < 15) {
        printf("Weather conditions: Hot and Humid\n");
    }
    else if (temperature < 20 && humidity < 40 && wind_speed >= 20) {
        printf("Weather conditions: Cold and Windy\n");
    }
    else if (wind_direction >= 0 && wind_direction <= 90) {
        printf("Weather conditions: Wind is coming from North East\n");
    }
    else if (wind_direction > 90 && wind_direction <= 180) {
        printf("Weather conditions: Wind is coming from South East\n");
    }
    else if (wind_direction > 180 && wind_direction <= 270) {
        printf("Weather conditions: Wind is coming from South West\n");
    }
    else {
        printf("Weather conditions: Wind is coming from North West\n");
    }
  
    return 0;
}