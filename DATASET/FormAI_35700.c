//FormAI DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

/**
 * This program generates a random math exercise that involves addition, subtraction, or multiplication.
 * The user is asked to solve the exercise and the program checks whether the answer is correct.
 */

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    int a = rand() % 11; // First random number between 0 and 10
    int b = rand() % 11; // Second random number between 0 and 10
    int operation = rand() % 3; // Randomly select 0 (addition), 1 (subtraction), or 2 (multiplication)
    
    int answer = 0; // Placeholder for the user's answer
    
    switch(operation) {
        case 0:
            printf("What is %d + %d? ", a, b);
            answer = a + b;
            break;
        case 1:
            printf("What is %d - %d? ", a, b);
            answer = a - b;
            break;
        case 2:
            printf("What is %d * %d? ", a, b);
            answer = a * b;
            break;
        default:
            printf("Unexpected error\n");
            return 1;
    }
    
    int user_answer = 0;
    scanf("%d", &user_answer);
    
    if(user_answer == answer) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The answer is %d\n", answer);
    }
    
    return 0;
}