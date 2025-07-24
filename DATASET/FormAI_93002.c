//FormAI DATASET v1.0 Category: Online Examination System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int questionsArray[5][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}}; // An array to hold the questions and their values
    int answersArray[5][3] = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}, {20, 22, 24}, {26, 28, 30}}; // An array to hold the answers
    int userAnswers[5]; // An array to hold the user's answers
    int mark = 0; // A variable to hold the user's mark

    srand(time(NULL)); // Seeding the rand() function with the current time

    printf("\nWELCOME TO THE ONLINE EXAMINATION SYSTEM\n\n");

    for(int i = 0; i < 5; i++) { // A loop to iterate through each question
        printf("\n\nQuestion #%d: What is the sum of ", i+1);
        for(int j = 0; j < 3; j++) { // A loop to iterate through each value in the question
            printf("%d", questionsArray[i][j]);
            if(j != 2) { // If j is not the last value in the question, print a plus sign
                printf(" + ");
            } else { // If j is the last value in the question, print an equals sign
                printf(" = ");
            }
        }

        scanf("%d", &userAnswers[i]); // Get the user's answer for the current question

        if(userAnswers[i] == answersArray[i][rand() % 3]) { // If the user's answer matches the correct answer
            printf("Correct!\n");
            mark += 2;
        } else { // If the user's answer is incorrect
            printf("Incorrect.\n");
        }
    }

    printf("\n\nYour mark is %d out of 10.\n", mark); // Print the user's mark

    return 0;
}