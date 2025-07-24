//FormAI DATASET v1.0 Category: Educational ; Style: retro
#include <stdio.h>

int main(void) {
    int year = 1984;
    char name[] = "RetroBot";
    char location[] = "Retro City";
    int age = 20;

    printf("Hello, I am %s and I was born in %d. I currently live in %s and I am %d years old.\n", name, year, location, age);

    printf("\nLet's play a game!\nI will think of a number between 1 and 100 and you will try to guess it.\n");

    int randomNumber = 77;
    int guess;

    do {
        printf("Guess a number: ");
        scanf("%d", &guess);

        if (guess > randomNumber) {
            printf("Too high!\n");
        } else if (guess < randomNumber) {
            printf("Too low!\n");
        } else {
            printf("Congratulations! You guessed the number!\n");
            break;
        }
    } while (guess != randomNumber);

    printf("Thanks for playing! Goodbye!");
    
    return 0;
}