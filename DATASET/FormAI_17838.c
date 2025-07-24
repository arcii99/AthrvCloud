//FormAI DATASET v1.0 Category: Online Examination System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int questionNumber;
    char question[1000];
    char options[4][100];
    int answer;
} Question;

int main() {
    int numOfQuestions = 3;
    Question questions[numOfQuestions];

    // First question
    questions[0].questionNumber = 1;
    strcpy(questions[0].question, "What is the capital of Australia?");
    strcpy(questions[0].options[0], "A. Sydney");
    strcpy(questions[0].options[1], "B. Melbourne");
    strcpy(questions[0].options[2], "C. Perth");
    strcpy(questions[0].options[3], "D. Canberra");
    questions[0].answer = 3;

    // Second question
    questions[1].questionNumber = 2;
    strcpy(questions[1].question, "What is the largest continent in the world?");
    strcpy(questions[1].options[0], "A. Africa");
    strcpy(questions[1].options[1], "B. Europe");
    strcpy(questions[1].options[2], "C. Asia");
    strcpy(questions[1].options[3], "D. North America");
    questions[1].answer = 2;

    // Third question
    questions[2].questionNumber = 3;
    strcpy(questions[2].question, "What is the smallest country in the world?");
    strcpy(questions[2].options[0], "A. Vatican City");
    strcpy(questions[2].options[1], "B. Monaco");
    strcpy(questions[2].options[2], "C. San Marino");
    strcpy(questions[2].options[3], "D. Liechtenstein");
    questions[2].answer = 0;

    int score = 0;
    int choice;

    printf("***Welcome to the online examination system!***\n");
    printf("You will be asked %d questions.\n", numOfQuestions);
    printf("Each question has four options, choose the correct one!\n");

    for(int i = 0; i < numOfQuestions; i++) {
        printf("\n\nQuestion %d\n", questions[i].questionNumber);
        printf("%s\n", questions[i].question);
        for(int j = 0; j < 4; j++) {
            printf("%s\n", questions[i].options[j]);
        }
        printf("Enter your choice (A=0, B=1, C=2, D=3): ");
        scanf("%d", &choice);
        if(choice == questions[i].answer) {
            printf("Correct answer!\n");
            score++;
        } else {
            printf("Wrong answer.\n");
        }
    }

    printf("\n\nYour score is %d out of %d.\n", score, numOfQuestions);
    printf("Thank you for using the online examination system!\n");

    return 0;
}