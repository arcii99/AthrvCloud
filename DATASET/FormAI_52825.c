//FormAI DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator
    int count = 0; // Keep track of user's score
    for (int i = 0; i < 10; i++) { // Play 10 rounds
        int num1 = rand() % 10 + 1; // Generate random numbers between 1 and 10
        int num2 = rand() % 10 + 1;

        printf("What is %d + %d? ", num1, num2);
        int answer;
        scanf("%d", &answer);

        if (answer == num1 + num2) { // If user answers correctly
            printf("Correct!\n");
            count++; // Increase user's score
        } else {
            printf("Incorrect. The answer is %d.\n", num1 + num2);
        }
    }

    printf("You got %d out of 10!\n", count);

    return 0;
}