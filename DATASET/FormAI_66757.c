//FormAI DATASET v1.0 Category: Online Examination System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    // Initialize variables
    int questions = 10;
    int correctAnswers = 0;
    char answer[10];
    int questionIndex;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Create and populate array of question numbers
    int questionArray[questions];
    for(int i = 0; i < questions; i++) {
        questionArray[i] = i+1;
    }
    
    // Shuffling of question numbers
    for(int i = 0; i < questions; i++) {
        int temp = questionArray[i];
        int randomIndex = rand() % questions;
        questionArray[i] = questionArray[randomIndex];
        questionArray[randomIndex] = temp;
    }
    
    // Ask questions and store user answers
    for(int i = 0; i < questions; i++) {
        questionIndex = questionArray[i];
        printf("Question %d:\n", i+1);
        switch(questionIndex) {
            case 1:
                printf("What is the value of pi (to 3 decimal places)?\n");
                scanf("%s", answer);
                if(strcmp(answer, "3.141") == 0) {
                    printf("Correct!\n\n");
                    correctAnswers++;
                }
                else {
                    printf("Incorrect.\n\n");
                }
                break;
            case 2:
                printf("What is the square root of 25?\n");
                scanf("%s", answer);
                if(strcmp(answer, "5") == 0) {
                    printf("Correct!\n\n");
                    correctAnswers++;
                }
                else {
                    printf("Incorrect.\n\n");
                }
                break;
            case 3:
                printf("What is the sum of 5 and 7?\n");
                scanf("%s", answer);
                if(strcmp(answer, "12") == 0) {
                    printf("Correct!\n\n");
                    correctAnswers++;
                }
                else {
                    printf("Incorrect.\n\n");
                }
                break;
            case 4:
                printf("What is the product of 3 and 4?\n");
                scanf("%s", answer);
                if(strcmp(answer, "12") == 0) {
                    printf("Correct!\n\n");
                    correctAnswers++;
                }
                else {
                    printf("Incorrect.\n\n");
                }
                break;
            case 5:
                printf("What is the reciprocal of 8?\n");
                scanf("%s", answer);
                if(strcmp(answer, "0.125") == 0) {
                    printf("Correct!\n\n");
                    correctAnswers++;
                }
                else {
                    printf("Incorrect.\n\n");
                }
                break;
            case 6:
                printf("What is the value of e (to 2 decimal places)?\n");
                scanf("%s", answer);
                if(strcmp(answer, "2.71") == 0) {
                    printf("Correct!\n\n");
                    correctAnswers++;
                }
                else {
                    printf("Incorrect.\n\n");
                }
                break;
            case 7:
                printf("What is the cube of 2?\n");
                scanf("%s", answer);
                if(strcmp(answer, "8") == 0) {
                    printf("Correct!\n\n");
                    correctAnswers++;
                }
                else {
                    printf("Incorrect.\n\n");
                }
                break;
            case 8:
                printf("What is the difference between 9 and 5?\n");
                scanf("%s", answer);
                if(strcmp(answer, "4") == 0) {
                    printf("Correct!\n\n");
                    correctAnswers++;
                }
                else {
                    printf("Incorrect.\n\n");
                }
                break;
            case 9:
                printf("What is the sine of 30 degrees (to 2 decimal places)?\n");
                scanf("%s", answer);
                if(strcmp(answer, "0.50") == 0) {
                    printf("Correct!\n\n");
                    correctAnswers++;
                }
                else {
                    printf("Incorrect.\n\n");
                }
                break;
            case 10:
                printf("What is the logarithm of 100 to the base 10 (to 2 decimal places)?\n");
                scanf("%s", answer);
                if(strcmp(answer, "2.00") == 0) {
                    printf("Correct!\n\n");
                    correctAnswers++;
                }
                else {
                    printf("Incorrect.\n\n");
                }
                break;
        }
    }
    
    // Display results to user
    printf("You got %d out of %d questions correct!\n", correctAnswers, questions);
    
    return 0;
}