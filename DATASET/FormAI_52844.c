//FormAI DATASET v1.0 Category: Weather simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(0));
    int temperature = (rand() % 50) - 10;
    char weather_condition[20];
    
    // Potential weather conditions
    char conditions[5][20] = {"sunny", "cloudy", "rainy", "snowy", "foggy"};

    // Determine the weather condition based on temperature
    if (temperature >= 30) {
        strcpy(weather_condition, "scorching");
    } else if (temperature >= 20 && temperature < 30) {
        strcpy(weather_condition, "hot");
    } else if (temperature >= 10 && temperature < 20) {
        strcpy(weather_condition, "warm");
    } else if (temperature >= 0 && temperature < 10) {
        strcpy(weather_condition, "chilly");
    } else {
        strcpy(weather_condition, "freezing");
    }

    // Randomly select a weather condition from the potential options
    int random_index = rand() % 5;
    strcpy(weather_condition, conditions[random_index]);
    
    // Print out the weather report in the style of Sherlock Holmes
    printf("It was a %s day with a temperature of %d degrees Celsius.\n", weather_condition, temperature);
    printf("The sky was %s with patches of gray clouds.\n", weather_condition);
    printf("The air was thick with the smell of wet pavement and approaching rain.\n");
    printf("I knew it was time to head back to Baker Street before I got caught in the downpour.\n");
    
    return 0;
}