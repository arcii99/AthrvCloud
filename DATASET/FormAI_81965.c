//FormAI DATASET v1.0 Category: Math exercise ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //seed the random number generator with the current time

    int a = rand() % 10 + 1; //generate a random integer between 1 and 10
    int b = rand() % 10 + 1;
    int c = rand() % 10 + 1;

    printf("What is the cube of %d multiplied by the square of %d multiplied by %d?\n", a, b, c);

    int userAnswer;
    scanf("%d", &userAnswer); //get the user's answer

    int correctAnswer = a*a*a * b*b * c; //calculate the correct answer

    if (userAnswer == correctAnswer) {
        printf("Congratulations, you got the answer correct!\n");
    } else {
        printf("Sorry, the correct answer was %d.\n", correctAnswer);
    }

    return 0;
}