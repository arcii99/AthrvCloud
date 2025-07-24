//FormAI DATASET v1.0 Category: Random ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // Seed for random numbers

    int x = rand() % 10; // Generate random number between 0 and 9
    printf("Feeling lucky? Your lucky number is: %d\n", x);

    if (x == 7) { // If lucky number is 7
        printf("Congratulations! You won the jackpot!\n");
        printf("Here's a random quote to celebrate your luck: ");
        switch (rand() % 5) { // Generate random quote
            case 0:
                printf("\"Luck is when preparation meets opportunity.\"\n");
                break;
            case 1:
                printf("\"The only thing that overcomes hard luck is hard work.\"\n");
                break;
            case 2:
                printf("\"Luck is what happens when the preparation meets the opportunity.\"\n");
                break;
            case 3:
                printf("\"Luck is a dividend of sweat. The more you sweat, the luckier you get.\"\n");
                break;
            case 4:
                printf("\"Luck is not chance, it's toil. Fortune's expensive smile is earned.\"\n");
                break;
        }
    } else { // If not lucky number 7
        printf("Better luck next time! Don't give up, keep trying.\n");
        printf("Here's a random pick-me-up line to cheer you up: ");
        switch (rand() % 5) { // Generate random pick-me-up line
            case 0:
                printf("\"You are a work of art. Don't let anyone tell you differently.\"\n");
                break;
            case 1:
                printf("\"You're doing great! Keep up the good work.\"\n");
                break;
            case 2:
                printf("\"Believe in yourself and all that you are. Know that there is something inside you that is greater than any obstacle.\"\n");
                break;
            case 3:
                printf("\"I believe in you!\"\n");
                break;
            case 4:
                printf("\"You are amazing and don't let anyone tell you different.\"\n");
                break;
        }
    }

    return 0;
}