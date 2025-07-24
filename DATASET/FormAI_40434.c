//FormAI DATASET v1.0 Category: Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int min_num = 1, max_num = 100, user_num, rand_num, guess_count = 0;

    srand(time(0));
    rand_num = (rand() % (max_num - min_num + 1)) + min_num;

    printf("Welcome to the Guess the Number game!\n");
    printf("The random number has been generated between %d and %d.\n", min_num, max_num);

    do {
        printf("Enter your guess: ");
        scanf("%d", &user_num);
        guess_count++;

        if (user_num > rand_num) {
            printf("Your guess is too high. Try again!\n");
        } else if (user_num < rand_num) {
            printf("Your guess is too low. Try again!\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", guess_count);
        }
    } while (user_num != rand_num);

    return 0;
}