//FormAI DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    //Initialize random seed
    srand(time(NULL));

    //Create a table with fruits
    char fruits[4][6] = {{"apple"}, {"banana"}, {"orange"}, {"grape"}};

    //Set initial score to 0
    int score = 0;

    //Print game instructions
    printf("Welcome to Happy Fruits!\n");
    printf("The goal of the game is to guess the hidden fruit.\n");
    printf("You have 5 chances to guess correctly.\n");

    //Pick a random fruit from the table
    int randomIndex = rand() % 4;
    char* hiddenFruit = fruits[randomIndex];

    //Loop for 5 chances
    for(int i=0; i<5; i++) {

        //Ask user for a guess
        printf("Guess #%d: ", i+1);
        char guess[10];
        scanf("%s", guess);

        //Check if guess is correct
        if(strcmp(guess, hiddenFruit) == 0) {
            printf("Congratulations! You guessed %s.\n", hiddenFruit);
            score += 10; //Add 10 to score for correct guess
            break; //End game
        } else {
            printf("Sorry, that is not the hidden fruit.\n");
        }
    }

    //Print final score
    printf("Your final score is %d.\n", score);

    return 0;
}