//FormAI DATASET v1.0 Category: Online Examination System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int correct_answers = 0;
    double score;
    time_t t;

    // initialize random number generator
    srand((unsigned) time(&t));

    // generate 10 randomly generated questions
    for(int i = 1; i <= 10; i++) {
        int num1 = rand() % 100;
        int num2 = rand() % 100;

        printf("Question %d: What is %d + %d?\n", i, num1, num2);

        // read in user's answer
        int answer;
        scanf("%d", &answer);

        // check if answer is correct and increment correct_answers if so
        if(answer == num1 + num2) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect.\n");
        }
    }

    // calculate the user's score and display it
    score = (double) correct_answers * 10;
    printf("\nYou got %d out of 10 questions correct.\n", correct_answers);
    printf("Your score is: %.2f%%\n", score);

    return 0;
}