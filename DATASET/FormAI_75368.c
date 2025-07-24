//FormAI DATASET v1.0 Category: Weather simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Simulate weather for 7 days
    printf("Simulating weather for 7 days...\n\n");
    for (int day = 1; day <= 7; day++) {
        int rain_chance = rand() % 100;
        
        // Determine the temperature range for the day
        int max_temp = rand() % 15 + 20;
        int min_temp = max_temp - (rand() % 10 + 5);
        
        // Output the weather for the day
        printf("Day %d:\n", day);
        printf("Temperature range: %d - %d degrees Celsius\n", min_temp, max_temp);
        if (rain_chance < 30) {
            printf("No rain expected.\n\n");
        } else if (rain_chance < 70) {
            // Determine the amount of rain for the day
            int rain_amount = rand() % 15 + 5;
            printf("Some scattered showers expected with a total of %dmm of rain.\n\n", rain_amount);
        } else {
            // Determine the amount of rain for the day
            int rain_amount = rand() % 30 + 20;
            printf("Heavy rain expected with a total of %dmm of rain.\n\n", rain_amount);
        }
    }
    
    return 0;
}