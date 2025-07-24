//FormAI DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Math Exercise program!\n");
    printf("This program generates random addition questions for you to solve.\n");
    printf("You will be given 10 questions to answer. Good luck!\n\n");

    int correct_answers = 0; // initialize the correct answers counter to 0

    // seed the random number generator with the current time
    srand(time(NULL));

    for (int i = 1; i <= 10; i++) { // loop 10 times for 10 questions
        int num1 = rand() % 101; // generate a random number between 0 and 100
        int num2 = rand() % 101;
        int answer;

        printf("Question %d: %d + %d = ", i, num1, num2); // display the question

        scanf("%d", &answer); // get user's answer

        // check if the answer is correct
        if (answer == num1 + num2) {
            printf("Correct!\n");
            correct_answers++; // increment the correct answer counter
        } else {
            printf("Incorrect. The correct answer is %d.\n", num1 + num2);
        }

        printf("\n"); // print a blank line for readability
    }

    printf("You answered %d out of 10 questions correctly.\n", correct_answers);

    if (correct_answers == 10) { // if all answers are correct, congratulate the user
        printf("Congratulations! You got a perfect score!\n");
    } else if (correct_answers >= 7) { // if 7 or more answers are correct, encourage the user
        printf("Great job! You did well.\n");
    } else if (correct_answers >= 4) { // if 4 or more answers are correct, give some tips
        printf("Not bad, but you can do better. Practice more!\n");
    } else { // if less than 4 answers are correct, give some more tips
        printf("You need more practice. Keep trying!\n");
    }

    return 0;
}