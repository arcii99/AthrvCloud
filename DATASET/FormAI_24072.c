//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_ships = rand() % 31 + 20; // generates a random number of alien ships from 20 to 50
    int num_days = rand() % 11 + 1; // generates a random number of days from 1 to 10

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Based on our calculations, there are currently %d alien ships en route to Earth.\n", num_ships);
    printf("Assuming they maintain their current speed, the invasion will arrive in %d days.\n\n", num_days);

    float day_chance = (float)num_ships / (float)num_days; // calculates the chance of an invasion on any given day
    float overall_chance = 1 - pow((1 - day_chance), num_days); // calculates the overall chance of an invasion within the given timeframe

    printf("The probability of an alien invasion on any given day is %.2f%%.\n", day_chance * 100);
    printf("The probability of an alien invasion within the next %d days is %.2f%%.\n", num_days, overall_chance * 100);

    if (overall_chance >= 0.5) {
        printf("\nWARNING: High probability of an alien invasion! Take appropriate precautions.\n");
    } else {
        printf("\nLow probability of an alien invasion. Carry on with daily activities as usual.\n");
    }

    return 0;
}