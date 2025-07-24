//FormAI DATASET v1.0 Category: Weather simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Declare variables
    int season, temperature;
    char* season_name;
    srand(time(0)); // Initialize random number generator

    // Loop through 4 seasons
    for (season = 1; season <= 4; season++) {

        // Set season name and temperature range
        switch(season) {
            case 1:
                season_name = "Spring";
                temperature = rand() % 20 + 10; // Temperature range: 10°C to 29°C
                break;
            case 2:
                season_name = "Summer";
                temperature = rand() % 30 + 20; // Temperature range: 20°C to 49°C
                break;
            case 3:
                season_name = "Fall";
                temperature = rand() % 20 + 5; // Temperature range: 5°C to 24°C
                break;
            case 4:
                season_name = "Winter";
                temperature = rand() % 25 - 10; // Temperature range: -10°C to 14°C
                break;
        }

        // Display season name and average temperature
        printf("%s season: Average temperature is %d°C\n", season_name, temperature);
    }

    return 0;
}