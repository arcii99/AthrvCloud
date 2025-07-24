//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Automated Fortune Teller!\n\n");

    srand(time(NULL)); //initialize random seed

    int fortune = rand() % 10 + 1; //generate random number from 1 to 10

    printf("Think of a question that you want to ask the fortune teller and press enter when you are ready...\n\n");
    getchar(); //wait for user input

    printf("Hmmm, let me consult the spirits for your answer...\n\n");

    switch(fortune) { //determine fortune based on random number generated
        case 1:
            printf("The answer lies within yourself. Look within.\n");
            break;
        case 2:
            printf("The stars say that success is in your future!\n");
            break;
        case 3:
            printf("Beware of those who are not what they seem...\n");
            break;
        case 4:
            printf("Your kind deeds will be rewarded in due time.\n");
            break;
        case 5:
            printf("The road ahead may be difficult, but don't give up!\n");
            break;
        case 6:
            printf("Something unexpected will happen soon... be prepared!\n");
            break;
        case 7:
            printf("A new opportunity is coming. Seize it when it arrives!\n");
            break;
        case 8:
            printf("The answer you seek is not a simple one. Take time to ponder.\n");
            break;
        case 9:
            printf("Beware of taking risks... they may not pay off in the end.\n");
            break;
        case 10:
            printf("The future is uncertain, but that is what makes life exciting!\n");
            break;
        default:
            printf("Oops, something went wrong. Please try again later.\n");
            break;
    }

    printf("\nThank you for visiting the Automated Fortune Teller!\n");

    return 0;
}