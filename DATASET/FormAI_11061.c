//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    int alien_ships = rand() % 501; // generate a random number of alien ships between 0-500
    int space_stations = rand() % 51; // generate a random number of space stations between 0-50

    printf("Alien invasion probability calculator\n\n");
    printf("Number of alien ships detected: %d\n", alien_ships);
    printf("Number of space stations detected: %d\n\n", space_stations);

    float alien_prob = (float) alien_ships / 500.0; // calculate alien presence probability (assuming max of 500 ships)
    float station_prob = (float) space_stations / 50.0; // calculate space station presence probability

    bool is_invasion_possible = false;
    float invasion_prob = alien_prob * station_prob * 100.0; // calculate invasion probability as a percentage

    if (invasion_prob > 50.0) { // if invasion probability is greater than 50%, there is a high chance of invasion
        printf("WARNING: High possibility of alien invasion!\n");
        is_invasion_possible = true;
    }
    else {
        printf("Alien invasion probability is moderate.\n");
    }

    // output alien and space station probabilities
    printf("Chance of alien presence: %.2f%%\n", alien_prob * 100.0);
    printf("Chance of space station presence: %.2f%%\n\n", station_prob * 100.0);

    // output overall invasion probability
    printf("Overall invasion probability: %.2f%%\n", invasion_prob);

    if (is_invasion_possible) {
        // calculate maximum number of ships an Earth space station can destroy
        int max_destroyed_ships = (int) (space_stations * 10 * (1 - alien_prob)); // assuming 10 ships destroyed per space station
        printf("Maximum number of alien ships Earth space stations can destroy: %d\n", max_destroyed_ships);   
    }

    return 0;
}