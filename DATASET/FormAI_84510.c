//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int invasion_probability = 0;
    srand(time(0));

    // Get the probability of invasion
    invasion_probability = rand() % 101;

    printf("Alien Invasion Probability: %d%%\n", invasion_probability);

    // Determine the likelihood of invasion based on the probability
    if(invasion_probability >= 75){
        printf("There is a high likelihood of invasion.\n");
    } else if(invasion_probability >= 50){
        printf("There is a moderate likelihood of invasion.\n");
    } else if(invasion_probability >= 25){
        printf("There is a low likelihood of invasion.\n");
    } else {
        printf("There is a very low likelihood of invasion.\n");
    }

    return 0;
}