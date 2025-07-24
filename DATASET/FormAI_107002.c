//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int num, i;
    float probability;
    srand(time(0));
    printf("\nWelcome to the Alien Invasion Probability Calculator\n");
    printf("\nEnter the number of times you want to run the simulation: ");
    scanf("%d", &num);
    printf("\nCalculating Probability...\n");
    for(i=1; i<=num; i++) {
        int random = rand() % 10 + 1;
        if(random == 1) {
            probability += 0.2;
        }
        else if(random == 2) {
            probability += 0.1;
        }
        else if(random >=3 && random <= 5) {
            probability += 0.05;
        }
        else {
            probability += 0.01;
        }
    }
    probability = probability/num * 100;
    printf("\nThe probability of alien invasion is: %0.2f%%\n", probability);
    return 0;
}