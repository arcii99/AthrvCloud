//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    printf("Welcome to the Alien Invasion Probability Calculator\n\n");
    printf("Please enter the number of planets in the galaxy: ");
    int planets;
    scanf("%d", &planets);
    printf("\n");
    
    printf("Please enter the number of intelligent life forms on these planets: ");
    int life_forms;
    scanf("%d", &life_forms);
    printf("\n");
    
    srand(time(NULL));
    int invasion_probability = rand() % 101; // Generate a random number between 0 and 100
    
    printf("Calculating invasion probability...\n\n");
    
    if (life_forms == 0) {
        printf("According to our calculations, there is a 0%% chance of an alien invasion.\n");
    }
    else {
        printf("According to our calculations, there is a %d%% chance of an alien invasion.\n", invasion_probability);
        
        if (invasion_probability < 30) {
            printf("This is a low probability, but caution is still recommended.\n");
        }
        else if (invasion_probability >= 30 && invasion_probability < 70) {
            printf("This is a moderate probability, and immediate preparations should be made.\n");
        }
        else {
            printf("This is a high probability, and an invasion may be imminent. All precautions should be taken!\n");
        }
    }
    
    return 0;
}