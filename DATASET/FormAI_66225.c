//FormAI DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed for random number generator

    int a = rand() % 101; // get random number between 0 and 100
    int b = rand() % 101; // get another random number between 0 and 100
    int result = a * b; // multiply the two random numbers

    printf("Get ready for a math surprise!\n");
    printf("What is %d multiplied by %d? ", a, b);

    int guess;
    scanf("%d", &guess); // get user's guess

    if (guess == result) {
        printf("Wow, you are a math genius! Your answer is correct! :D\n");
        printf("Congratulations, you have won a surprise prize!\n");
        printf("Please send an email to surprisemath@gmail.com to claim your prize.\n");
    } else {
        printf("Oops, sorry, your answer is incorrect. :(\n");
        printf("The correct answer is %d. Don't worry, you can try again!\n", result);
    }

    return 0;
}