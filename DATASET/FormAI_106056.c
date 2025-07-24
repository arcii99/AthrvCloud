//FormAI DATASET v1.0 Category: Memory Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // seed the random number generator with the current time

    int sequence[100]; // maximum sequence length is 100
    int length = 1; // start with a sequence length of 1
    int score = 0; // keep track of the player's score

    while(1) { // loop indefinitely

        // generate the sequence
        for(int i=0; i<length; i++) {
            sequence[i] = rand() % 10 + 1; // generate a random number between 1 and 10
        }

        // display the sequence to the player
        printf("Sequence: ");
        for(int i=0; i<length; i++) {
            printf("%d ", sequence[i]);
        }
        printf("\n");

        // allow the player to enter the sequence
        printf("Your turn: ");
        for(int i=0; i<length; i++) {
            int guess;
            scanf("%d", &guess);
            if(guess != sequence[i]) { // if the guess is wrong, end the game
                printf("Wrong! Your final score is: %d\n", score);
                return 0;
            }
        }
        printf("Correct!\n");
        score++; // increase the player's score

        // increase the length of the sequence every five rounds
        if(score % 5 == 0) {
            length++;
            printf("Sequence length increased to %d!\n", length);
        }

    }

    return 0;
}