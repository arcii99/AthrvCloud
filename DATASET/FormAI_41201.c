//FormAI DATASET v1.0 Category: Math exercise ; Style: rigorous
#include <stdio.h> // Standard input/output library
#include <stdlib.h> // Standard library
#include <time.h> // Time library 

int main() {
    int a, b, c, d, e, f;
    int score = 0;
    int answer;
    int i = 0;

    srand(time(NULL)); // Set the seed for random number generation

    printf("Welcome to the C Math Exercise Game!\n");

    while (i < 5) {
        a = rand() % 100; // Generate random integer between 0 and 99
        b = rand() % 100; // Generate another random integer between 0 and 99
        c = rand() % 100; // Generate yet another random integer between 0 and 99

        printf("\nQuestion %d\n", i+1);
        printf("%d + %d * %d = ? ", a, b, c); // Print the question in the format of a * b + c
        scanf("%d", &answer); // Read the user's input

        d = b * c; // Calculate the result of b * c
        e = a + d; // Calculate the final result of a * b + c

        if (e == answer) {
            printf("Correct!\n");
            score++; // Increase score by one if the answer is correct
        } else {
            printf("Wrong!\n");
            printf("The correct answer is %d\n", e); // Print the correct answer if the user's answer is wrong
        }

        i++; // Increment the counter for number of questions
    }

    printf("\nGame Over!\n");
    printf("Your final score is %d out of 5.\n", score);

    return 0; // Indicate successful program execution
}