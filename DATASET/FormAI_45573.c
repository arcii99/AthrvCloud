//FormAI DATASET v1.0 Category: Weather simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between min and max (inclusive)
int randomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Initialize variables for temperature and precipitation
    int temperature = randomInt(0, 100);
    int precipitation = randomInt(0, 100);
    
    // Print the initial weather report
    printf("Today's weather report:\n");
    printf("Temperature: %d degrees Fahrenheit\n", temperature);
    printf("Precipitation: %d percent\n\n", precipitation);
    
    // Ask the user if they want to change the weather
    char answer;
    printf("Do you want to change the weather? (Y/N): ");
    scanf(" %c", &answer);
    
    // If the user wants to change the weather, prompt them for new values
    if (answer == 'Y' || answer == 'y') {
        printf("Enter the new temperature- ");
        scanf("%d", &temperature);
        printf("Enter the new precipitation percentage- ");
        scanf("%d", &precipitation);
    }
    
    // Print the updated weather report
    printf("\nUpdated weather report:\n");
    printf("Temperature: %d degrees Fahrenheit\n", temperature);
    printf("Precipitation: %d percent\n", precipitation);
    
    return 0;
}