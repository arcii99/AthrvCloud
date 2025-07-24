//FormAI DATASET v1.0 Category: Math exercise ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));
    int num1, num2, product, answer;
    int correct = 0, incorrect = 0;
    printf("Welcome to the multiplication exercise program!\n\n");
    for (int i = 0; i < 10; i++) {
        num1 = rand() % 13; 
        num2 = rand() % 13;
        product = num1 * num2;
        printf("Question %d: What is %d x %d?\n", i + 1, num1, num2);
        scanf("%d", &answer);
        if (answer == product) {
            printf("Correct answer!\n\n");
            correct++;
        }
        else {
            printf("Incorrect answer, the correct answer is: %d\n\n", product);
            incorrect++;
        }
    }
    printf("You answered %d questions correctly and %d questions incorrectly.\n", correct, incorrect);
    printf("Thanks for playing the multiplication exercise program!\n");
    return 0;
}