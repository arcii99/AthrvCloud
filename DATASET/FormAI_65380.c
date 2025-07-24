//FormAI DATASET v1.0 Category: Weather simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    
    int temp = rand() % 50 - 10; // generate a random temperature between -10 and 40 degrees Celsius
    
    printf("Today's temperature is %d degrees Celsius.\n", temp);
    
    if (temp < 0) {
        printf("It's freezing cold outside!\n");
    } else if (temp >= 0 && temp < 10) {
        printf("It's a bit chilly, make sure to grab a jacket!\n");
    } else if (temp >= 10 && temp < 20) {
        printf("It's a nice day, perfect for a picnic.\n");
    } else if (temp >= 20 && temp < 30) {
        printf("It's getting quite warm, be sure to stay hydrated.\n");
    } else {
        printf("It's scorching outside, be careful not to get sunburned!\n");
    }
    
    int rainfall = rand() % 101; // generate a random rainfall percentage between 0 and 100
    
    printf("There is a %d%% chance of rain today.\n", rainfall);
    
    if (rainfall < 30) {
        printf("Looks like it's going to be a dry day.\n");
    } else if (rainfall >= 30 && rainfall < 60) {
        printf("There might be some scattered showers, bring an umbrella just in case.\n");
    } else if (rainfall >= 60 && rainfall < 80) {
        printf("It's going to be a wet day, make sure to wear a raincoat and boots!\n");
    } else {
        printf("Looks like it's going to be a complete washout, stay indoors if you can.\n");
    }
    
    return 0;
}