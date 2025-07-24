//FormAI DATASET v1.0 Category: Weather simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random temperature value in Celsius
float generateTemp() {
    return ((float)rand()/(float)(RAND_MAX)) * 30.0 - 10.0;
}

// function to get the corresponding weather description based on temperature
char* getWeatherDescription(float temperature) {
    if (temperature < -5.0) {
        return "extremely cold";
    } else if (temperature < 5.0) {
        return "very cold";
    } else if (temperature < 15.0) {
        return "cold";
    } else if (temperature < 25.0) {
        return "moderate";
    } else if (temperature < 35.0) {
        return "warm";
    } else {
        return "hot";
    }
}

// main function
int main() {
    // seed the random number generator
    srand(time(NULL));
    
    // generate a random temperature value
    float temperature = generateTemp();
    
    // print the temperature
    printf("Temperature: %.2f Celsius\n", temperature);
    
    // get the weather description
    char* description = getWeatherDescription(temperature);
    
    // print the weather description
    printf("The weather is %s\n", description);
    
    // exit the program
    return 0;
}