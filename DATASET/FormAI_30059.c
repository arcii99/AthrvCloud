//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random fortune
char* getFortune() {
    srand(time(NULL)); // seed the random number generator
    int num = rand() % 3; // generate a random number between 0-2
    char* fortune;
    switch(num) {
        case 0:
            fortune = "You will meet someone special today.";
            break;
        case 1:
            fortune = "A great opportunity is coming your way.";
            break;
        default:
            fortune = "You will encounter a challenge, but you will overcome it.";
    }
    return fortune;
}

int main() {
    printf("Welcome to the Automated Fortune Teller.\n");
    printf("Please think of a yes or no question and press enter to see your fortune.\n");
    getchar(); // wait for user input
    char* fortune = getFortune();
    printf("\nYour fortune is: %s\n", fortune);
    printf("Thank you for using the Automated Fortune Teller!\n");
    return 0;
}