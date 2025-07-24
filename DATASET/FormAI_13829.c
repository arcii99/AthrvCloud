//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int num, guess, tries = 0;

    printf("\nWelcome to the Exciting Adventure Game!\n");
    printf("\nYou are stranded on a mysterious island and have to find your way back home.\n");

    num = rand() % 100 + 1; //generating random number between 1 and 100

    printf("\nThere is a cave in front of you. Shall you go in?\n");
    printf("\nType 1 for Yes and 0 for No: ");
    scanf("%d", &guess);

    while(guess){
        printf("\nYou enter the cave and find yourself in a room with three doors.\n");
        printf("\nBehind one door is the way out of the island, behind others are deadly traps.\n");
        printf("\nWhich door will you choose? (1, 2 or 3): ");
        scanf("%d", &guess);
        tries++;

        if(guess == num){
            printf("\nCongratulations! You have found the way out of the island in %d tries.\n", tries);
            return 0;
        }
        else{
            printf("\nSorry, behind this door is a deadly trap.\n");
        }
    }

    printf("\nOh no! You have chickened out and lost the game!\n");
    return 0;
}