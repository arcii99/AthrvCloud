//FormAI DATASET v1.0 Category: Math exercise ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PROBLEMS 10
#define MAX_NUM 20

int main() {
    int num1, num2, answer, userAnswer;
    int numCorrect = 0;
    char operator;
    srand(time(NULL)); // Seed random number generator
    
    printf("*** Welcome to the Math Problem Generator! ***\n\n");
    
    for (int i = 0; i < NUM_PROBLEMS; i++) {
        num1 = rand() % MAX_NUM + 1;
        num2 = rand() % MAX_NUM + 1;
        operator = rand() % 3;
        
        switch(operator) {
            case 0:
                answer = num1 + num2;
                printf("%d + %d = ", num1, num2);
                break;
            case 1:
                answer = num1 - num2;
                printf("%d - %d = ", num1, num2);
                break;
            case 2:
                answer = num1 * num2;
                printf("%d * %d = ", num1, num2);
                break;
        }
        
        scanf("%d", &userAnswer);
        
        if (userAnswer == answer) {
            printf("Correct!\n");
            numCorrect++;
        } else {
            printf("Wrong! The correct answer is %d\n", answer);
        }
    }
    
    printf("You got %d out of %d problems correct. Good job!\n", numCorrect, NUM_PROBLEMS);
    
    return 0;
}