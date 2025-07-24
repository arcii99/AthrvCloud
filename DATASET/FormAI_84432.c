//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL));
    int num_aliens = rand() % 1000 + 1; //Randomly generates number of aliens
    int num_days = rand() % 30 + 1; //Randomly generates number of days

    float invasion_probability = ((float)num_aliens / 1000) * ((float)num_days / 30) * 100; //Calculates probability of invasion
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Based on our calculations, there are approximately %d aliens headed towards Earth.\n", num_aliens);
    printf("Assuming they arrive in %d days, the probability of an alien invasion is %.2f%%\n", num_days, invasion_probability);
    
    if(invasion_probability >= 50.0) { //If probability of invasion is greater than or equal to 50%
        printf("The chances of an alien invasion are high. We must prepare for the worst.\n");
    }
    else {
        printf("The chances of an alien invasion are low. We can breathe a sigh of relief for now.\n");
    }
    
    return 0;
}