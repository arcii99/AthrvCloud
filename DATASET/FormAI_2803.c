//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>

int main() {
    printf("Welcome to the Mystery Game!\n");
    printf("The rules are simple: Guess the secret code consisting of 4 numbers between 1 and 6.\n");
    printf("You have 8 attempts to guess the correct code.\n");
    printf("Let's begin!\n\n");

    int secret_code[] = {3, 1, 2, 5};
    int guess[4];
    int attempts = 8;
    int i, j, correct_num, correct_pos;

    while (attempts > 0) {
        printf("Enter your guess (4 numbers between 1 and 6): ");
        scanf("%d %d %d %d", &guess[0], &guess[1], &guess[2], &guess[3]);

        correct_num = 0;
        correct_pos = 0;

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (secret_code[i] == guess[j]) {
                    correct_num++;
                    if (i == j) {
                        correct_pos++;
                    }
                    break;
                }
            }
        }

        if (correct_pos == 4) {
            printf("Congratulations, you guessed the secret code!\n");
            return 0;
        }
        else {
            printf("Correct numbers: %d\n", correct_num);
            printf("Correct positions: %d\n", correct_pos);
            attempts--;
            printf("You have %d attempts left.\n", attempts);
        }
    }

    printf("Game over. The secret code was: %d %d %d %d\n", secret_code[0], secret_code[1], secret_code[2], secret_code[3]);
    return 0;
}