//FormAI DATASET v1.0 Category: Random ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_grateful_msg(int num) {
    if (num == 0) {
        printf("Wow, this is incredible! You chose the number 0, and I couldn't be more grateful.\n");
    } else if (num < 0) {
        printf("You're really going above and beyond here by picking a negative number. Thank you so much for choosing %d!\n", num);
    } else if (num < 10) {
        printf("Thank you for picking %d. You're helping me stretch my legs a bit and try something new.\n", num);
    } else if (num < 50) {
        printf("You're making this game a blast for me with your choice of %d. Thanks for being a part of this.\n", num);
    } else {
        printf("My level of gratitude is reaching the stratosphere with you picking the number %d. Thank you so, so much.\n", num);
    }
}

int main() {
    int num, guess, tries = 0;

    srand(time(0));
    num = rand() % 100 + 1;

    printf("---Welcome to the Grateful Random Game!---\n");
    printf("\nI have a random number between 1 and 100. Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > num) {
            printf("Oops! That's too high. ");
            print_grateful_msg(guess);
        } else if (guess < num) {
            printf("Nope! That's too low. ");
            print_grateful_msg(guess);
        } else {
            printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
        }

    } while (guess != num);

    return 0;
}