//FormAI DATASET v1.0 Category: Online Examination System ; Style: complex
#include<stdio.h>

int main(){
    int numOfQuestions = 10;
    char answerKey[10] = {'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D', 'A', 'B'};
    char studentAnswers[10];
    int i, correctAnswers = 0, incorrectAnswers = 0, notAnswered = 0;

    printf("Welcome to the Online Examination System\n");
    printf("This test consists of %d multiple choice questions.\n", numOfQuestions);

    //get student's answers
    for(i=0; i<numOfQuestions; i++){
        printf("Enter your answer for Question %d: ", i+1);
        scanf(" %c", &studentAnswers[i]);
    }

    //evaluate the test
    for(i=0; i<numOfQuestions; i++){
        if(studentAnswers[i] == answerKey[i]){ //if student answers correctly
            printf("Question %d: Correct\n", i+1);
            correctAnswers++;
        }
        else if(studentAnswers[i] == ' '){ //if student did not answer
            printf("Question %d: Not Answered\n", i+1);
            notAnswered++;
        }
        else{ //if student answer is incorrect
            printf("Question %d: Incorrect\n", i+1);
            incorrectAnswers++;
        }
    }

    //print results
    printf("\nResults:\n");
    printf("Number of Correct Answers: %d\n", correctAnswers);
    printf("Number of Incorrect Answers: %d\n", incorrectAnswers);
    printf("Number of Not Answered: %d\n", notAnswered);

    return 0;
}