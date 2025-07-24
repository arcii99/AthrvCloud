//FormAI DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct User {
    char name[50];
    int score;
};

struct Question {
    char question[200];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    char correctOption;
};

struct Exam {
    char title[50];
    struct Question questions[20];
    int numOfQuestions;
};

void loginUser(struct User *user) {
    printf("\nEnter your name: ");
    fgets(user->name, 50, stdin);
    user->score = 0;
}

void displayQuestion(struct Question *ques) {
    printf("\n%s\nA. %s\nB. %s\nC. %s\nD. %s\n", 
           ques->question, ques->optionA, ques->optionB, 
           ques->optionC, ques->optionD);
}

void startExam(struct Exam *exam, struct User *user) {
    printf("\n\n*** Exam: %s ***\n\n", exam->title);
    int i, choice;
    for(i=0; i<exam->numOfQuestions; i++) {
        printf("\nQuestion %d:\n", i+1);
        displayQuestion(&exam->questions[i]);
        printf("\nEnter your choice (A/B/C/D): ");
        do {
            choice = getchar();
        } while(choice == '\n');
        if(choice == exam->questions[i].correctOption) {
            user->score++;
        }
    }
}

void displayScore(struct User *user) {
    printf("\n\n*** Scores ***\n\n%s - %d/20\n\n", 
           user->name, user->score);
}

int main() {
    struct Exam exam;
    struct User user;
    
    strcpy(exam.title, "C Programming Test");
    exam.numOfQuestions = 5;
    
    // Question1
    strcpy(exam.questions[0].question, "What is the output of printf(\"%d\", sizeof(int))?");
    strcpy(exam.questions[0].optionA, "int");
    strcpy(exam.questions[0].optionB, "4");
    strcpy(exam.questions[0].optionC, "4.0");
    strcpy(exam.questions[0].optionD, "Error");
    exam.questions[0].correctOption = 'B';
    
    // Question2
    strcpy(exam.questions[1].question, "Which of the following is a valid C identifier?");
    strcpy(exam.questions[1].optionA, "_abc");
    strcpy(exam.questions[1].optionB, "*abc");
    strcpy(exam.questions[1].optionC, "123abc");
    strcpy(exam.questions[1].optionD, "@abc");
    exam.questions[1].correctOption = 'A';
    
    // Question3
    strcpy(exam.questions[2].question, "What is the output of the following code?\nint i=0; while(i<5) { i++; } printf(\"%d\", i);");
    strcpy(exam.questions[2].optionA, "0");
    strcpy(exam.questions[2].optionB, "1");
    strcpy(exam.questions[2].optionC, "4");
    strcpy(exam.questions[2].optionD, "5");
    exam.questions[2].correctOption = 'D';
    
    // Question4
    strcpy(exam.questions[3].question, "What is the output of the following code?\nint x=5; printf(\"%d\", ++x);");
    strcpy(exam.questions[3].optionA, "5");
    strcpy(exam.questions[3].optionB, "6");
    strcpy(exam.questions[3].optionC, "4");
    strcpy(exam.questions[3].optionD, "Error");
    exam.questions[3].correctOption = 'B';
    
    // Question5
    strcpy(exam.questions[4].question, "What is the output of the following code?\nint x=3; printf(\"%d\", x++ + ++x);");
    strcpy(exam.questions[4].optionA, "5");
    strcpy(exam.questions[4].optionB, "6");
    strcpy(exam.questions[4].optionC, "7");
    strcpy(exam.questions[4].optionD, "Error");
    exam.questions[4].correctOption = 'C';
    
    loginUser(&user);
    startExam(&exam, &user);
    displayScore(&user);
    
    return 0;
}