//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); //initialize random seed

    printf("Welcome to the automated Fortune Teller!\n");

    int fortune = rand() % 10 + 1; //generate random number from 1 to 10
    
    switch(fortune){
        case 1:
            printf("Outlook hazy, try again.\n");
            break;
        case 2:
            printf("Things aren't looking good for you.\n");
            break;
        case 3:
            printf("You will face challenges, but you will come out stronger.\n");
            break;
        case 4:
            printf("Luck is on your side today.\n");
            break;
        case 5:
            printf("Watch out for unexpected surprises.\n");
            break;
        case 6:
            printf("You will soon be visited by a stranger.\n");
            break;
        case 7:
            printf("You will find success in your next endeavor.\n");
            break;
        case 8:
            printf("Your fortune will be determined by the flip of a coin.\n");
            break;
        case 9:
            printf("The stars are aligning in your favor.\n");
            break;
        case 10:
            printf("Your future is uncertain, but that makes it more exciting.\n");
            break;
    }
    return 0;
}