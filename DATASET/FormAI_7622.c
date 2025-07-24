//FormAI DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    printf("Welcome to the peaceful math exercise program!\n\n");
    
    printf("Instructions:\n");
    printf("Choose a math operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Random operation\n\n");
    
    int operation;
    printf("Enter the number of the operation you want to choose: ");
    scanf("%d", &operation);
    
    srand(time(NULL)); // initialize random seed
    
    int num1 = rand() % 50; // generate random number between 0 and 49
    int num2 = rand() % 50;
    int answer; // variable for user's answer
    
    switch(operation) {
        case 1:
            printf("\nWhat is %d + %d? ", num1, num2);
            scanf("%d", &answer);
            if(answer == num1 + num2) {
                printf("Congratulations! You answered correctly.\n");
            } else {
                printf("Oops! The correct answer is %d.\n", num1 + num2);
            }
            break;
        case 2:
            printf("\nWhat is %d - %d? ", num1, num2);
            scanf("%d", &answer);
            if(answer == num1 - num2) {
                printf("Congratulations! You answered correctly.\n");
            } else {
                printf("Oops! The correct answer is %d.\n", num1 - num2);
            }
            break;
        case 3:
            printf("\nWhat is %d * %d? ", num1, num2);
            scanf("%d", &answer);
            if(answer == num1 * num2) {
                printf("Congratulations! You answered correctly.\n");
            } else {
                printf("Oops! The correct answer is %d.\n", num1 * num2);
            }
            break;
        case 4:
            printf("\nWhat is %d / %d? ", num1, num2);
            scanf("%d", &answer);
            if(answer == num1 / num2) {
                printf("Congratulations! You answered correctly.\n");
            } else {
                printf("Oops! The correct answer is %d.\n", num1 / num2);
            }
            break;
        case 5:
            int rand_op = rand() % 4 + 1; // generate random number between 1 and 4
            switch(rand_op) {
                case 1:
                    printf("\nWhat is %d + %d? ", num1, num2);
                    scanf("%d", &answer);
                    if(answer == num1 + num2) {
                        printf("Congratulations! You answered correctly.\n");
                    } else {
                        printf("Oops! The correct answer is %d.\n", num1 + num2);
                    }
                    break;
                case 2:
                    printf("\nWhat is %d - %d? ", num1, num2);
                    scanf("%d", &answer);
                    if(answer == num1 - num2) {
                        printf("Congratulations! You answered correctly.\n");
                    } else {
                        printf("Oops! The correct answer is %d.\n", num1 - num2);
                    }
                    break;
                case 3:
                    printf("\nWhat is %d * %d? ", num1, num2);
                    scanf("%d", &answer);
                    if(answer == num1 * num2) {
                        printf("Congratulations! You answered correctly.\n");
                    } else {
                        printf("Oops! The correct answer is %d.\n", num1 * num2);
                    }
                    break;
                case 4:
                    printf("\nWhat is %d / %d? ", num1, num2);
                    scanf("%d", &answer);
                    if(answer == num1 / num2) {
                        printf("Congratulations! You answered correctly.\n");
                    } else {
                        printf("Oops! The correct answer is %d.\n", num1 / num2);
                    }
                    break;
            }
            break;
        default:
            printf("Invalid operation number.\n");
            break;
    }
    
    printf("\nThanks for playing!\n");
    
    return 0;
}