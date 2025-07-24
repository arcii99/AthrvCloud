//FormAI DATASET v1.0 Category: Math exercise ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;
    int answer, user_answer;
    char operator;
    
    if (rand() % 2 == 0) {
        operator = '+';
        answer = num1 + num2;
    } else {
        operator = '-';
        answer = num1 - num2;
    }
    
    printf("Welcome to the Math Challenge!\n");
    printf("Solve the following problem to prove your math skills:\n");
    printf("%d %c %d = ", num1, operator, num2);
    scanf("%d", &user_answer);
    
    if (user_answer == answer) {
        printf("Well done! You are truly a master of mathematics!\n");
    } else {
        printf("Incorrect! Your skills are lacking. The correct answer is %d.\n", answer);
    }
    
    return 0;
}