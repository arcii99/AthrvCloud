//FormAI DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator

    int num1 = rand() % 100 + 1; // generate a random number between 1 and 100
    int num2 = rand() % 100 + 1;
    int answer;

    printf("What is the sum of %d and %d?\n", num1, num2);
    scanf("%d", &answer); // get the user's answer

    if (answer == num1 + num2) { // check if the answer is correct
        printf("Congratulations! You got it right!\n");
    } else {
        printf("Oops, the correct answer is %d.\n", num1 + num2);
    }

    return 0;
}