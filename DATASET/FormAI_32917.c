//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    srand(time(0));

    printf("\n====== WELCOME TO THE GAME ======\n");
    printf("\nYou will be given 10 questions.");
    printf("You need to guess the correct number between 1 and 10.\n");

    for(int i=1; i<=10; i++) {
        int number = rand()%10 + 1;
        printf("\nQuestion %d: ", i);
        int guess;
        scanf("%d", &guess);

        if(guess == number) {
            printf("Congratulations, you guessed it right!");
            score++;
        } else {
            printf("Oops! The correct answer is %d.\n", number);
        }
    }

    printf("\n\n====== GAME OVER ======\n");
    printf("\nYour final score is %d/10", score);

    if(score >= 7) {
        printf("Congratulations! You won the game!\n");
    } else {
        printf("Better luck next time!\n");
    }

    return 0;
}