//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // Initialize random number generator
    int score = 0;
    printf("Welcome to the C Periodic Table Quiz!\n\n");
    printf("Instructions: You will be shown the symbol for an element, and you must enter the corresponding atomic number.\n");
    printf("You will have three chances per question. Good luck!\n\n");

    char elements[10][3] = {{"H"}, {"He"}, {"Li"}, {"Be"}, {"B"}, {"C"}, {"N"}, {"O"}, {"F"}, {"Ne"}};
    int correct_answers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++) {
        // Choose random element from array
        int random_index = rand() % 10;
        char element[3];
        strcpy(element, elements[random_index]);

        // Ask question
        printf("What is the atomic number of %s?\n", element);

        // Give user three chances to answer
        for (int j = 1; j <= 3; j++) {
            printf("\nChance %d: ", j);
            int user_answer;
            scanf("%d", &user_answer);

            if (user_answer == correct_answers[random_index]) {
                printf("Correct!\n");
                score++;
                break; // Exit loop when user answers correctly
            } else if (j < 3) {
                printf("Incorrect. Try again.\n");
            } else {
                printf("Incorrect. The correct answer is %d.\n", correct_answers[random_index]);
            }
        }

        printf("Your current score is %d.\n\n", score);
    }

    printf("Quiz finished! Your final score is %d out of 10.\n", score);

    return 0;
}