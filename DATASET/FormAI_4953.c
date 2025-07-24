//FormAI DATASET v1.0 Category: Weather simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Generate random temperature and weather conditions
    srand(time(NULL));
    int temperature = rand() % 21 + 10; // Range: 10 - 30 degrees Celsius
    int weather = rand() % 5; // 0 - Sunny, 1 - Cloudy, 2 - Rainy, 3 - Snowy, 4 - Foggy
    
    // Switch statement to determine string output based on weather code
    char *weatherString;
    switch (weather) {
        case 0:
            weatherString = "Sunny";
            break;
        case 1:
            weatherString = "Cloudy";
            break;
        case 2:
            weatherString = "Rainy";
            break;
        case 3:
            weatherString = "Snowy";
            break;
        case 4:
            weatherString = "Foggy";
            break;
        default:
            weatherString = "Unknown";
            break;
    }
    
    // Print out weather report
    printf("Today's weather report:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Weather condition: %s\n", weatherString);
    
    return 0;
}