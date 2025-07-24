//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerNum, randomNum, attempt = 1, maxAttempts;
    srand(time(0));
    randomNum = rand() % 101; // generates a random number between 0 to 100
    printf("Welcome to the Math Adventure Game!\n");

    do {
        printf("Enter a number between 0 to 100: ");
        scanf("%d", &playerNum);
        
        if (playerNum < randomNum) {
            printf("The number is greater than %d.\n", playerNum);
        } else if (playerNum > randomNum) {
            printf("The number is less than %d.\n", playerNum);
        } else {
            printf("You win the Game in %d attempt(s)!\n", attempt);
        }
        
        attempt++;
        maxAttempts++;
    } while (playerNum != randomNum && maxAttempts < 10);

    if (maxAttempts >= 10) {
        printf("Game Over! You have exceeded the maximum number of attempts.\n");
    }

    return 0;
}