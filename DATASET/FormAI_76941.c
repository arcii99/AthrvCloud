//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    // Initializing variables and random seed
    int alien_odds[10];
    int total_odds = 0;
    int invasion_probability = 0;
    time_t t;
    srand((unsigned) time(&t));

    // Generating random odds for 10 possible outcomes
    printf("Calculating alien invasion probability...\n");
    for(int i = 0; i < 10; i++){
        alien_odds[i] = rand() % 100 + 1;
        printf("Outcome %d: %d%%\n", i+1, alien_odds[i]);
        total_odds += alien_odds[i];
    }

    // Calculating probability of an alien invasion
    invasion_probability = total_odds / 10;
    printf("Total odds: %d%%\n", total_odds);
    printf("Invasion probability: %d%%\n", invasion_probability);
    
    // Determining outcome
    if(invasion_probability >= 50){
        printf("Based on the calculated probability, an alien invasion is likely.\n");
    }else{
        printf("Based on the calculated probability, an alien invasion is unlikely.\n");
    }

    return 0;
}