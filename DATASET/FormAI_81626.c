//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Set seed for random number generator

    char name[20];
    printf("Hello! Welcome to the Automated Fortune Teller. What's your name?\n");
    scanf("%s", name);

    printf("Nice to meet you, %s! Let's begin.\n", name);

    int fortune = rand() % 8; // Generate random number between 0 and 7

    switch(fortune) { // Check the generated number and print a corresponding fortune
        case 0:
            printf("You will find love in the most unexpected place: the DMs of a bot on Twitter.\n");
            break;
        case 1:
            printf("Your next meal will be a delicious burrito, but you'll forget to ask for extra guac.\n");
            break;
        case 2:
            printf("Your future is looking bright, unless you're a vampire. In that case, it's looking pretty dark.\n");
            break;
        case 3:
            printf("You will soon receive news that will change your life. It will happen via a Facebook event invite.\n");
            break;
        case 4:
            printf("What is meant to be will find its way to you. Unfortunately, that thing is a cold.\n");
            break;
        case 5:
            printf("A great adventure is waiting for you ahead. That adventure is trying to find a public bathroom with no line in Times Square.\n");
            break;
        case 6:
            printf("You will receive an unexpected gift. Unfortunately, that gift is a subscription to Cat Fancy magazine.\n");
            break;
        case 7:
            printf("Life is full of surprises. Some of them are good, some of them are bad, and some of them are wondering why you're writing a fortune telling program in C.\n");
            break;
        default:
            printf("Oops! Something went wrong... try again later.\n");
            return 1;
    }

    printf("\nThank you for using the Automated Fortune Teller. See you again soon, %s!\n", name);
    return 0;
}