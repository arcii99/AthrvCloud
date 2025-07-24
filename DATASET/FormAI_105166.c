//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); // Initialize random seed
    int alienHealth = rand() % 100 + 1; // Generate random value for alien health (1-100)
    int alienAttack = rand() % 20 + 1; // Generate random value for alien attack (1-20)
    float alienAccuracy = ((float) rand() / (float) RAND_MAX); // Generate random value for alien accuracy (0-1)
    int humanHealth = rand() % 100 + 1; // Generate random value for human health (1-100)
    int humanAttack = rand() % 20 + 1; // Generate random value for human attack (1-20)
    float humanAccuracy = ((float) rand() / (float) RAND_MAX); // Generate random value for human accuracy (0-1)

    printf("ALIEN INVASION PROBABILITY CALCULATOR\n");
    printf("\n");
    printf("Alien Health: %d\n", alienHealth);
    printf("Alien Attack: %d\n", alienAttack);
    printf("Alien Accuracy: %.2f\n", alienAccuracy);
    printf("\n");
    printf("Human Health: %d\n", humanHealth);
    printf("Human Attack: %d\n", humanAttack);
    printf("Human Accuracy: %.2f\n", humanAccuracy);
    printf("\n");

    // Calculate probability of alien winning
    float alienWinProbability = alienAccuracy * alienHealth / (humanAttack * (1 - humanAccuracy) + alienAttack * alienAccuracy);
    printf("Probability of Alien Winning: %.2f%%\n", alienWinProbability * 100);

    // Calculate probability of human winning
    float humanWinProbability = (1 - alienAccuracy) * humanHealth / (alienAttack * alienAccuracy + humanAttack * (1 - humanAccuracy));
    printf("Probability of Human Winning: %.2f%%\n", humanWinProbability * 100);

    return 0;
}