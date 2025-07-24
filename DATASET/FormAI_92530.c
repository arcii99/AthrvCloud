//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int prob;
    srand(time(NULL));  //initialize the seed for random number generation
    prob = rand()%101;   //generate a random number between 0 and 100 as probability of alien invasion

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("The current probability of an alien invasion is: %d%%\n\n", prob);

    if(prob >= 75){
        printf("It's highly likely that an alien invasion will occur in the near future.\n");
        printf("Please make sure to be prepared for any unexpected scenario!\n");
    }
    else if(prob < 75 && prob >= 50){
        printf("The probability of an alien invasion is moderate.\n");
        printf("It's always better to be safe than sorry, so keep an eye out for any suspicious activity!\n");
    }
    else{
        printf("The probability of an alien invasion is low.\n");
        printf("Phew! That's a relief. Let's just hope it stays that way.\n");
    }

    printf("\nThank you for using the Alien Invasion Probability Calculator!\n");

    return 0;
}