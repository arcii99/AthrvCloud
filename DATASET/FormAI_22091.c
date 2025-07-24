//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(0)); // seed for random generator based on current time
    
    int level, armies, ships, weapons, probability;
    
    printf("ALIEN INVASION PROBABILITY CALCULATOR\n\n");
    printf("Enter the current level of technology (1-10): ");
    scanf("%d", &level); // taking user input for technology level
    
    printf("\nEnter the number of armies currently available: ");
    scanf("%d", &armies); // taking user input for number of armies
    
    printf("\nEnter the number of ships currently available: ");
    scanf("%d", &ships); // taking user input for number of ships
    
    printf("\nEnter the number of advanced weapons currently available: ");
    scanf("%d", &weapons); // taking user input for number of advanced weapons
    
    probability = (level * armies * ships * weapons) / 10; // calculating probability
    
    // if probability is less than 50%, there is a low chance of invasion
    if(probability < 50) {
        printf("\nAlien invasion probability is %d%%. There is a low chance of invasion.\n", probability);
    }
    
    // if probability is greater than or equal to 50% but less than 80%, there is a moderate chance of invasion
    else if(probability >= 50 && probability < 80) {
        printf("\nAlien invasion probability is %d%%. There is a moderate chance of invasion.\n", probability);
    }
    
    // if probability is greater than or equal to 80%, there is a high chance of invasion
    else {
        printf("\nAlien invasion probability is %d%%. There is a high chance of invasion. Take immediate action!\n", probability);
    }
    
    return 0;
}