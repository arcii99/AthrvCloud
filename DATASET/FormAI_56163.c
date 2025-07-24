//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game();

int main() {
    srand(time(NULL));
    printf("Welcome to the Procedural Space Adventure Game!\n\n");
    printf("Press 'p' to play or 'q' to quit.\n");
    char choice = getchar();
    if(choice == 'p' || choice == 'P')
        play_game();
    else
        printf("Game Over!\n");
    return 0;
}

void play_game() {
    int num, guess, tries = 0;
    num = rand() % 10 + 1; // Selecting a random planet between 1 to 10
    printf("Welcome to planet %d!\n", num);
    printf("Can you find your way back to Earth?\n");
    printf("You have to select the correct path to reach the next planet,\n");
    printf("Or you'll be lost in the unknown vastness of space.\n");
    printf("Enter a number between 1 to 5 to select a path or 0 to quit the game.\n");

    do {
        scanf("%d", &guess);
        tries++;
        if(guess == 0) {
            printf("You Quit the game!");
            break;
        }
        else if(guess != num)
            printf("Sorry, that's the wrong path. Try again.\n");
        else
            printf("Congratulations! You found the correct path to the next planet.\n");
    } while(guess != num);

    printf("You completed the game in %d tries. Thanks for playing.\n", tries);
}