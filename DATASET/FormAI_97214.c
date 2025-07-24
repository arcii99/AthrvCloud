//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int fortune = rand() % 5;
    printf("Welcome to the Automated Fortune Teller. I am here to predict your future!\n");

    switch(fortune) {
        case 0:
            printf("You will have a successful career as a software engineer!\n");
            break;
        case 1:
            printf("You will meet the love of your life in the next 6 months!\n");
            break;
        case 2:
            printf("You will win the lottery within the next year!\n");
            break;
        case 3:
            printf("You will travel to a new country within the next year!\n");
            break;
        case 4:
            printf("You will complete a personal goal that has been important to you for a long time within the next 3 months!\n");
            break;
        default:
            printf("Oops, something went wrong. Please try again later.\n");
            break;
    }

    return 0;
}