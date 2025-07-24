//FormAI DATASET v1.0 Category: Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
    int nums[10];
    int i, j;
    int num_guesses = 0;
    int guess[4];
    int bulls, cows;

    // Generate random 4-digit number
    srand(time(0));
    for (i = 0; i < 4; i++) {
        nums[i] = rand() % 10;
        // Make sure digits are unique
        for (j = 0; j < i; j++) {
            if (nums[j] == nums[i]) {
                i--;
                break;
            }
        }
    }

    while (1) {
        // Get guess from user
        printf("Enter a 4-digit number: ");
        scanf("%1d%1d%1d%1d", &guess[0], &guess[1], &guess[2], &guess[3]);

        // Check if guess is correct
        bulls = 0;
        cows = 0;
        for (i = 0; i < 4; i++) {
            if (guess[i] == nums[i]) {
                bulls++;
            } else {
                for (j = 0; j < 4; j++) {
                    if (guess[i] == nums[j]) {
                        cows++;
                        break;
                    }
                }
            }
        }
        num_guesses++;

        // Print results
        printf("%d bulls, %d cows\n", bulls, cows);
        if (bulls == 4) {
            printf("Congratulations! You guessed the number in %d tries.\n", num_guesses);
            break;
        }
    }

    return 0;
}