//FormAI DATASET v1.0 Category: Weather simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature = 0; // variable to store temperature
    srand(time(NULL)); // seed for random number generation
    
    printf("Welcome to the happy weather simulator!\n");
    printf("----------------------------------------\n");
    
    printf("Today's temperature is %d degrees Celsius.\n", temperature);
    
    // Loop to simulate weather conditions
    for (int i = 0; i < 7; i++) {
        printf("Day %d:\n", i+1);
        
        // Randomly generate temperature increase or decrease 
        int rand_num = rand() % 10 + 1; // generate random integer between 1 and 10
        if (rand_num <= 5) {
            temperature -= 2;
            printf("The temperature has decreased by 2 degrees Celsius and is now %d degrees Celsius.\n", temperature);
        } else {
            temperature += 3;
            printf("The temperature has increased by 3 degrees Celsius and is now %d degrees Celsius.\n", temperature);
        }
        
        // Print happy message depending on temperature
        if (temperature <= 0) {
            printf("Brrr! It's freezing cold outside! Better bundle up to stay warm.\n");
        } else if (temperature > 0 && temperature <= 15) {
            printf("It's a bit chilly outside, but not too bad. Put on a light jacket and you'll be good to go!\n");
        } else if (temperature > 15 && temperature <= 25) {
            printf("It's a lovely day outside! Perfect weather for a picnic or a stroll in the park.\n");
        } else {
            printf("Wow! It's scorching hot outside! Stay hydrated and avoid prolonged exposure to the sun.\n");
        }
        
        printf("\n"); // Print blank line for spacing
    }
    
    printf("Thanks for using the happy weather simulator! We hope you have a great day!\n");
    
    return 0;
}