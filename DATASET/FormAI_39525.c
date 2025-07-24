//FormAI DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/* This program generates a set of multiplication problems involving numbers raised to various powers. 
The user can select the maximum exponent and the maximum base value to be used in the problems. */

int main() {

    int max_exp, max_base;
    printf("Enter the maximum exponent to be used in the problems: ");
    scanf("%d", &max_exp);
    printf("Enter the maximum base to be used in the problems: ");
    scanf("%d", &max_base);

    // Set the seed for the random number generator
    srand(time(NULL));

    int num_problems = 5;
    for(int i = 0; i < num_problems; i++) {
        // Generate random values for the base and exponent for each problem
        int base = rand() % max_base + 1;
        int exp = rand() % max_exp + 1;

        // Calculate the correct answer to the problem
        double correct_answer = pow(base, exp);

        // Print the problem and get the user's answer
        printf("%d raised to the %d power is: ", base, exp);
        double user_answer;
        scanf("%lf", &user_answer);

        // Check if the user's answer is equal to the correct answer
        if(fabs(user_answer - correct_answer) < 0.0001) { // allow for small rounding errors
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is: %.2f\n", correct_answer);
        }
    }

    return 0;
}