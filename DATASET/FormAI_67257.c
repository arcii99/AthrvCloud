//FormAI DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int weatherType; // variable to store weather type
    int temperature; // variable to store temperature
    int i; // counter for loop
    srand(time(NULL)); // seed random generator
    
    printf("*** Weather Simulation Program ***\n\n");
    
    // loop for generating 7 days worth of weather data
    for(i = 1; i <= 7; i++){
        printf("Day %d:\n", i);
        weatherType = rand() % 4; // generate random weather type between 0 and 3
        temperature = rand() % 51 - 10; // generate random temperature between -10 and 40
        
        printf("Weather type: ");
        switch(weatherType) {
            case 0:
                printf("Sunshine\n");
                break;
            case 1:
                printf("Cloudy\n");
                break;
            case 2:
                printf("Rainy\n");
                break;
            case 3:
                printf("Snowy\n");
                break;
        }
        
        printf("Temperature: %dC\n\n", temperature);
    }
    
    printf("*** End of Weather Simulation ***\n");
    return 0;
}