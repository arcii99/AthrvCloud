//FormAI DATASET v1.0 Category: Online Examination System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Question {
    char question[100];
    char options[4][50];
    int answer;
};

struct Exam {
    char examName[50];
    int numOfQuestions;
    struct Question *questions;
};

void displayInstructions() {
    printf("\n\t*** Welcome to our Online Examination Portal ***\n");
    printf("\tINSTRUCTIONS:");
    printf("\n\t1. Answer all the questions within the given time period.");
    printf("\n\t2. Each question carries 1 mark.");
    printf("\n\t3. There is no negative marking.");
    printf("\n\t4. Once you submit the exam, you cannot take it again.");
    printf("\n\t------------------------------------------------------------\n\n");
}

void displayQuestion(struct Question question) {
    printf("\n%s\n", question.question);

    for(int i=0; i<4; i++) {
        printf("\t%d. %s\n", i+1, question.options[i]);
    }

    printf("\nEnter your answer: ");
}

int startExam(struct Exam exam) {
    int score = 0;
    time_t startTime = time(NULL);

    for(int i=0; i<exam.numOfQuestions; i++) {
        printf("Question %d:\n", i+1);
        displayQuestion(exam.questions[i]);

        int userAnswer;
        scanf("%d", &userAnswer);

        if(userAnswer == exam.questions[i].answer) {
            score++;
        }
    }

    time_t endTime = time(NULL);
    int duration = (int)difftime(endTime, startTime);

    printf("\n*** Results ***\n");
    printf("Exam Name: %s\n", exam.examName);
    printf("Duration: %d seconds\n", duration);
    printf("Score: %d/%d\n", score, exam.numOfQuestions);

    return score;
}

void viewLeaderboard() {
    printf("\n*** Leaderboard ***\n");
    printf("1. John Doe - 8/10\n");
    printf("2. Jane Doe - 7/10\n");
    printf("3. Jack Smith - 6/10\n");
}

int main() {
    displayInstructions();

    struct Exam exam;
    strcpy(exam.examName, "C Programming Exam");
    exam.numOfQuestions = 5;
    exam.questions = malloc(exam.numOfQuestions * sizeof(struct Question));

    // sample questions
    strcpy(exam.questions[0].question, "Which header file is needed for file operations?");
    strcpy(exam.questions[0].options[0], "stdio.h");
    strcpy(exam.questions[0].options[1], "string.h");
    strcpy(exam.questions[0].options[2], "math.h");
    strcpy(exam.questions[0].options[3], "stdlib.h");
    exam.questions[0].answer = 1;

    strcpy(exam.questions[1].question, "What is the result of 4+7%3?");
    strcpy(exam.questions[1].options[0], "3");
    strcpy(exam.questions[1].options[1], "4");
    strcpy(exam.questions[1].options[2], "5");
    strcpy(exam.questions[1].options[3], "6");
    exam.questions[1].answer = 4;

    strcpy(exam.questions[2].question, "Which of the following cannot be a variable name in C?");
    strcpy(exam.questions[2].options[0], "myVariable");
    strcpy(exam.questions[2].options[1], "_myVariable");
    strcpy(exam.questions[2].options[2], "123myVariable");
    strcpy(exam.questions[2].options[3], "myVariable123");
    exam.questions[2].answer = 3;

    strcpy(exam.questions[3].question, "What is the size of a char data type in bytes?");
    strcpy(exam.questions[3].options[0], "1");
    strcpy(exam.questions[3].options[1], "2");
    strcpy(exam.questions[3].options[2], "3");
    strcpy(exam.questions[3].options[3], "4");
    exam.questions[3].answer = 1;

    strcpy(exam.questions[4].question, "Which operator is used for pointer access?");
    strcpy(exam.questions[4].options[0], "&");
    strcpy(exam.questions[4].options[1], "*");
    strcpy(exam.questions[4].options[2], "+");
    strcpy(exam.questions[4].options[3], "/");
    exam.questions[4].answer = 2;

    startExam(exam);
    viewLeaderboard();

    return 0;
}