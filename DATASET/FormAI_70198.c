//FormAI DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int a = rand() % 10 + 1;
    int b = rand() % 10 + 1;
    int c = rand() % 10 + 1;
    
    printf("Welcome to our happy math exercise program!\n");
    printf("Today we are going to practice addition, subtraction, and multiplication!\n");
    printf("Are you ready?? Let's get started!!!\n\n");
    
    printf("Question 1: What is %d + %d?\n", a, b);
    int answer1;
    scanf("%d", &answer1);
    if (answer1 == a + b) {
        printf("Correct! Good job!\n\n");
    } else {
        printf("Oh no! The correct answer is %d. Better luck next time!\n\n", a+b);
    }
    
    printf("Question 2: What is %d - %d?\n", c, b);
    int answer2;
    scanf("%d", &answer2);
    if (answer2 == c - b) {
        printf("Awesome! You are doing great!\n\n");
    } else {
        printf("Oops! The correct answer is %d. Keep trying!\n\n", c-b);
    }
    
    printf("Question 3: What is %d * %d?\n", a, c);
    int answer3;
    scanf("%d", &answer3);
    if (answer3 == a * c) {
        printf("You are a math genius! Keep up the good work!\n\n");
    } else {
        printf("Sorry! The correct answer is %d. Don't give up! Try again!\n\n", a*c);
    }
    
    printf("Congratulations! You have finished all the questions!\n");
    printf("Now you are a math superstar! Keep practicing and keep smiling!\n");
    
    return 0;
}