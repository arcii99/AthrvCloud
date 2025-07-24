//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_of_aliens, num_of_ships, num_of_planets, num_of_colonies, invasion_probability;
    
    // get user input
    printf("Enter the number of aliens: ");
    scanf("%d", &num_of_aliens);
    printf("Enter the number of ships: ");
    scanf("%d", &num_of_ships);
    printf("Enter the number of planets: ");
    scanf("%d", &num_of_planets);
    printf("Enter the number of colonies: ");
    scanf("%d", &num_of_colonies);

    // calculate invasion probability
    invasion_probability = ((num_of_aliens + num_of_ships) * num_of_planets) / num_of_colonies;

    // seed random number generator
    srand(time(NULL));

    // determine if invasion will occur
    if (invasion_probability > 50) {
        int random_num = rand() % 100;
        if (random_num < invasion_probability) {
            printf("Invasion successful!\n");
        } else {
            printf("Invasion failed.\n");
        }
    } else {
        printf("Probability of invasion is too low.\n");
    }

    return 0;
}