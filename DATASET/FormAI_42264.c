//FormAI DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber() {
    srand(time(NULL));
    return rand() % 100;
}

int main() {
    int numPlayers;
    printf("How many players are there? ");
    scanf("%d", &numPlayers);

    int scores[numPlayers];
    for(int i = 0; i < numPlayers; i++) {
        scores[i] = 0;
    }

    int answer = generateRandomNumber();
    int numRounds = 5;

    for(int i = 0; i < numRounds; i++) {
        printf("\nRound %d\n", i+1);
        printf("The target number is between 0 and 99.\n");

        for(int j = 0; j < numPlayers; j++) {
            printf("Player %d, enter your guess: ", j+1);
            int guess;
            scanf("%d", &guess);

            if(guess == answer) {
                scores[j] += 10;
                printf("Player %d guessed correctly and earned 10 points!\n", j+1);
            } else {
                int diff = abs(answer - guess);
                scores[j] += (100 - diff);
                printf("Player %d was %d away from the correct answer and earned %d points!\n", j+1, diff, (100-diff));
            }
        }
    }

    printf("\nFinal Scores:\n");
    for(int i = 0; i < numPlayers; i++) {
        printf("Player %d: %d points\n", i+1, scores[i]);
    }

    return 0;
}