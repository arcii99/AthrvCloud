//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, ans, user_ans, i;
    int score = 0;
    srand(time(0)); // to generate random numbers each time the program runs
    printf("Welcome to the Math Quizzer!\n");
    printf("You will be given 10 addition problems to solve.\n");
    printf("Please enter your answer and press enter.\n");
    for(i=1; i<=10; i++) {
        a = rand() % 100;
        b = rand() % 100;
        ans = a + b;
        printf("\n");
        printf("Problem %d: %d + %d = ? ", i, a, b);
        scanf("%d", &user_ans);
        if(user_ans == ans) {
            printf("Correct! Well done.\n");
            score++; // increment score for correct answer
        }
        else {
            printf("Incorrect. The correct answer is %d.\n", ans);
        }
    }
    printf("\n");
    printf("Quiz complete! Your score is %d out of 10.\n", score);
    return 0;
}