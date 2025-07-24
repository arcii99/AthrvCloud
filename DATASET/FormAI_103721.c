//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0)); //Seed for random number generation.
    int alien_odds = rand() % 100 + 1; //Percentage chance of alien invasion.
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("According to our calculations, there is a %d percent chance of an alien invasion.\n\n", alien_odds);
    
    if(alien_odds >= 75){
        printf("WARNING: The probability of an alien invasion is high!\n");
        printf("Please take necessary precautions and stay alert.\n");
    }
    else if(alien_odds >= 50){
        printf("CAUTION: The probability of an alien invasion is moderate.\n");
        printf("Stay aware of the situation and be prepared.\n");
    }
    else {
        printf("ALERT: The probability of an alien invasion is low.\n");
        printf("While the possibility is slim, it is important to always be alert.\n");
    }
    return 0;
}