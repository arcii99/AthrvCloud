//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); //Initializing random seed
    int alien_ships = rand() % 100 + 1; //Generating random number of alien ships from 1 to 100
    int defense_systems = rand() % 50 + 1; //Generating random number of defense systems from 1 to 50
    float probability = (float)defense_systems / alien_ships * 100; //Calculating invasion probability
    printf("Alien Invasion Probability Calculator\n");
    printf("-------------------------------------\n");
    printf("Number of Alien Ships: %d\n", alien_ships);
    printf("Number of Defense Systems: %d\n", defense_systems);
    printf("Probability of Invasion: %.2f%%\n", probability);
    if(probability < 50){
        printf("The probability of invasion is low. We can breathe easy for now.\n");
    }
    else if(probability >= 50 && probability < 75){
        printf("The probability of invasion is moderate. We need to prepare ourselves.\n");
    }
    else if(probability >= 75 && probability < 90){
        printf("The probability of invasion is high. We are in a dangerous situation.\n");
    }
    else{
        printf("The probability of invasion is very high. We must act quickly to protect ourselves.\n");
    }
    return 0;
}