//FormAI DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char question[200];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int answer;
} Question;

int main() {
    Question questions[5];
    int score = 0;

    // Set up questions
    strcpy(questions[0].question, "What is the output of this code? int x = 5; printf('%d', ++x);");
    strcpy(questions[0].option1, "5");
    strcpy(questions[0].option2, "6");
    strcpy(questions[0].option3, "4");
    strcpy(questions[0].option4, "7");
    questions[0].answer = 2;

    strcpy(questions[1].question, "What is the data type of the variable 'a' in this code? char a = 'A';");
    strcpy(questions[1].option1, "int");
    strcpy(questions[1].option2, "char");
    strcpy(questions[1].option3, "float");
    strcpy(questions[1].option4, "double");
    questions[1].answer = 2;

    strcpy(questions[2].question, "What is the keyword used to declare a function in C?");
    strcpy(questions[2].option1, "function");
    strcpy(questions[2].option2, "define");
    strcpy(questions[2].option3, "main");
    strcpy(questions[2].option4, "void");
    questions[2].answer = 4;

    strcpy(questions[3].question, "What is the result of the expression 3 + 4 * 7?");
    strcpy(questions[3].option1, "49");
    strcpy(questions[3].option2, "31");
    strcpy(questions[3].option3, "25");
    strcpy(questions[3].option4, "29");
    questions[3].answer = 2;

    strcpy(questions[4].question, "What is the output of this code? int i; for(i=0; i<3; i++) { printf('%d', i); }");
    strcpy(questions[4].option1, "012");
    strcpy(questions[4].option2, "123");
    strcpy(questions[4].option3, "210");
    strcpy(questions[4].option4, "0123");
    questions[4].answer = 1;

    // Start exam
    printf("Welcome to the C Programming Language Online Examination System!\n");
    printf("Answer the following questions to test your knowledge.\n");
    printf("Enter 1, 2, 3, or 4 to select your answer.\n");

    for (int i = 0; i < 5; i++) {
        printf("\nQuestion %d: %s\n", i+1, questions[i].question);
        printf("1. %s\n", questions[i].option1);
        printf("2. %s\n", questions[i].option2);
        printf("3. %s\n", questions[i].option3);
        printf("4. %s\n", questions[i].option4);

        int answer;
        printf("Enter your answer: ");
        scanf("%d", &answer);

        if (answer == questions[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("\nThank you for taking the exam.\n");
    printf("Your score is: %d/5\n", score);

    return 0;
}