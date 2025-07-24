//FormAI DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * This program generates two random numbers between 1 to 100 and asks the user to
 * input the correct answer to their sum. If the user inputs the correct answer,
 * the program prints "Correct" and generates a new set of random numbers. If the user inputs
 * the incorrect answer, the program prints "Incorrect" and terminates.
 */

int get_random_number() {
    srand(time(NULL)); // seed the random number generator
    return rand() % 100 + 1; // generate a random number between 1 to 100
}

int get_sum(int num1, int num2) {
    return num1 + num2;
}

void main() {
    int num1 = get_random_number();
    int num2 = get_random_number();

    while(1) {
        printf("What is the sum of %d and %d: ", num1, num2);
        int answer;
        scanf("%d", &answer);

        if(answer == get_sum(num1, num2)) {
            printf("Correct!\n");
            num1 = get_random_number();
            num2 = get_random_number();
        } else {
            printf("Incorrect, the correct answer is %d\n", get_sum(num1, num2));
            break;
        }
    }
}