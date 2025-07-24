//FormAI DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 40
#define MIN_TEMP -10

int main() {
    // seed the random number generator with current time
    srand(time(NULL));
    
    int current_temp = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP; // generate a random temperature between MIN_TEMP and MAX_TEMP
    
    printf("The current temperature is %d degrees Celsius.\n", current_temp);
    
    if(current_temp <= 0) {
        printf("It's freezing outside. Better wear a heavy coat and boots.\n");
    } else if(current_temp > 0 && current_temp <= 10) {
        printf("It's pretty cold outside. Don't forget your jacket.\n");
    } else if(current_temp > 10 && current_temp <= 20) {
        printf("It's cool outside. A light jacket or sweater should do.\n");
    } else if(current_temp > 20 && current_temp <= 30) {
        printf("It's warm outside. Shorts and t-shirt weather!\n");
    } else {
        printf("It's scorching outside. Stay indoors or wear sunscreen and sunhat.\n");
    }
    
    return 0;
}