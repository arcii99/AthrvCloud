//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //Setting seed of rand() function
    srand(time(NULL));
    
    int total_planets = rand()%100 + 1;  //Random number between 1 to 100
    
    printf("There are %d planets in the galaxy.\n", total_planets);
    
    int invaded_planets = rand()%total_planets + 1;  //Random number between 1 to total number of planets
    
    printf("%d planets have already been invaded by the aliens.\n", invaded_planets);
    
    float invasion_probability = (float)invaded_planets/(float)total_planets;  //Calculating probability
    
    printf("The probability of invasion of the next planet is %.2f.\n", invasion_probability);
    
    if(invasion_probability < 0.3) {
        printf("The chances of alien invasion are low. You can relax for a while.\n");
    }
    else if(invasion_probability >= 0.3 && invasion_probability <= 0.7) {
        printf("The chances of alien invasion are moderate. Keep an eye on the sky.\n");
    }
    else {
        printf("The chances of alien invasion are high. Be prepared to fight.\n");
    }
    
    return 0;
}