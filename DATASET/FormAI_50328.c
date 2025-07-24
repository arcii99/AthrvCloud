//FormAI DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* One morning, a group of animals decided to have a race to determine the fastest animal in the forest.
 * It was a beautiful day, and everyone was excited to see who would win. Each animal was given a unique
 * number, and the race was on!
 * The animals ran a distance of 500m. The time taken by each animal to complete the race was recorded.
 * Can you determine the winner? */

int main() {

    int animals[10]; // Array of unique animal numbers
    int times[10]; // Array to store times taken for the race
    int i;

    // Let's generate some random numbers for the animals
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        animals[i] = rand() % 100 + 1;
    }

    printf("List of animals and their numbers:\n");
    for (i = 0; i < 10; i++) {
        printf("Animal %d: %d\n", i+1, animals[i]);
    }

    // The race begins!
    printf("\nThe race is on! Go animals!\n");
    for (i = 0; i < 10; i++) {
        int time_taken = rand() % 30 + 10; // Generating random time taken, between 10 and 40 seconds
        times[i] = time_taken;
        printf("Animal %d completed the race in %d seconds!\n", i+1, time_taken);
    }

    // Let's find the winner
    int winner = 0; // The index of the winner
    int fastest_time = times[0];
    printf("\nFinding the winner...\n");
    for (i = 1; i < 10; i++) {
        if (times[i] < fastest_time) {
            fastest_time = times[i];
            winner = i;
        }
    }

    printf("\nAnd the winner is...\n");
    printf("Animal %d with a time of %d seconds!\n", winner+1, fastest_time);
    printf("Congratulations, Animal %d!\n", winner+1);

    return 0;
}