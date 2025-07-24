//FormAI DATASET v1.0 Category: Math exercise ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    int num1 = rand() % 10 + 1; // generate a random number between 1 and 10
    int num2 = rand() % 10 + 1; // generate another random number between 1 and 10

    printf("What is %d + %d? ", num1, num2);

    int answer;
    scanf("%d", &answer);

    int correct_answer = num1 + num2;
    if (answer == correct_answer) {
        printf("Correct! %d + %d = %d\n", num1, num2, correct_answer);
    } else {
        printf("Incorrect. %d + %d is not %d, it is %d\n", num1, num2, answer, correct_answer);
    }

    return 0;
}