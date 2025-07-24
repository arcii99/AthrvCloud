//FormAI DATASET v1.0 Category: Online Examination System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between 1 to 10
int generateRandomNumber() {
    srand(time(0));
    int num = (rand() % 10) + 1;
    return num;
}

// Function to ask questions and get answers from user
int askQuestion(char* question, int answer) {
    int userAnswer;
    printf("%s\n", question);
    scanf("%d", &userAnswer);

    if(userAnswer == answer) {
        printf("Correct! You earned 1 point.\n");
        return 1;
    } else {
        printf("Wrong! The correct answer is %d.\n", answer);
        return 0;
    }
}

int main() {
    int numQuestions = 5;
    int questionsAnswered = 0;
    int score = 0;

    printf("Welcome to the C Online Examination System!\n");
    printf("You will be given %d questions and you have to answer them correctly to earn points.\n", numQuestions);

    while(questionsAnswered < numQuestions) {
        int a = generateRandomNumber();
        int b = generateRandomNumber();
        int answer = a + b;
        char question[50];
        sprintf(question, "What is %d + %d?", a, b);

        score += askQuestion(question, answer);
        questionsAnswered++;
    }

    printf("Congratulations! You have completed the exam and earned %d points out of %d.", score, numQuestions);

    return 0;
}