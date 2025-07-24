//FormAI DATASET v1.0 Category: Math exercise ; Style: minimalist
#include <stdio.h> // include standard input and output library
#include <stdlib.h> // include standard library
#include <time.h> // include time library

int main() {

    srand(time(NULL)); // initialize random seed
    int a = rand() % 10; // generate random number between 0 - 9
    int b = rand() % 10; // generate random number between 0 - 9
    int c = rand() % 10; // generate random number between 0 - 9

    int d = (a * b) + c; // calculate value of d based on a, b and c

    printf("Solve the following equation: %d * x + %d = %d\n", a, c, d); // print equation for user to solve

    int answer; // variable to store user's answer
    scanf("%d", &answer); // read user's answer from input

    int solution = (d - c) / a; // calculate actual solution of the equation

    if (answer == solution) { // check if user's answer is correct
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("Sorry, your answer is wrong. The correct answer is %d.\n", solution);
    }

    return 0; // exit program
}