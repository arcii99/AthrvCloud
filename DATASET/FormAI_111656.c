//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // to initialize the random number generator
    double prob; //probability of alien invasion
    int min = 0, max = 100; //minimum and maximum values for probability
    int rand_num; //randomly generated number
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please answer the following questions to determine the probability of an alien invasion.\n\n");

    //ask user for input
    char answer;
    printf("Do you believe in aliens? (Y/N): ");
    scanf(" %c", &answer);

    if(answer == 'Y' || answer == 'y'){
        prob = (rand() % (max - min + 1)) + min; //generate random probability between 0 and 100
        printf("\nThe probability of an alien invasion is %.2f%%\n", prob);
    }else{
        printf("\nWell, if aliens don't exist, then the probability of an alien invasion is 0%%\n");
    }
    return 0;
}