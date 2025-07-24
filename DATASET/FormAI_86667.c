//FormAI DATASET v1.0 Category: Weather simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WEATHER_MAX 3   // Maximum number of weather patterns
#define WEATHER_MIN 1   // Minimum number of weather patterns

int main(void){

    /* List of weather patterns */
    char weather[WEATHER_MAX][20] = { "Sunny", "Rainy", "Cloudy" };

    /* Random seed */
    srand(time(NULL));

    /* Randomly select a weather pattern */
    int random_num = rand() % (WEATHER_MAX - WEATHER_MIN + 1) + WEATHER_MIN;
    char *current_weather = weather[random_num - 1];

    /* Display current weather */
    printf("The current weather is: %s\n", current_weather);

    return 0;
}