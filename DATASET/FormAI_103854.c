//FormAI DATASET v1.0 Category: Online Examination System ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question {
    int qid;
    char qstatement[100];
    char options[4][50];
    int correct_option;
};

int main() {
    struct question q[10];

    // Populate questions array
    q[0].qid = 1;
    strcpy(q[0].qstatement, "What is the capital of India?");
    strcpy(q[0].options[0], "Mumbai");
    strcpy(q[0].options[1], "Delhi");
    strcpy(q[0].options[2], "Kolkata");
    strcpy(q[0].options[3], "Chennai");
    q[0].correct_option = 1;

    q[1].qid = 2;
    strcpy(q[1].qstatement, "Who is the first President of USA?");
    strcpy(q[1].options[0], "George Washington");
    strcpy(q[1].options[1], "Thomas Jefferson");
    strcpy(q[1].options[2], "Abraham Lincoln");
    strcpy(q[1].options[3], "Franklin Roosevelt");
    q[1].correct_option = 0;

    // Add more questions to the array

    int score = 0;
    int response;

    printf("Welcome to the Online Exam System\n");
    printf("The exam contains 10 multiple choice questions with 4 options each.\n");
    printf("Please enter your response number (1-4) for each question:\n");

    // Ask questions one by one
    for(int i=0;i<10;i++) {
        printf("\nQ%d. %s\n", q[i].qid, q[i].qstatement);
        printf("1. %s\n", q[i].options[0]);
        printf("2. %s\n", q[i].options[1]);
        printf("3. %s\n", q[i].options[2]);
        printf("4. %s\n", q[i].options[3]);
        printf("Your answer (1-4): ");
        scanf("%d", &response);

        if(response == q[i].correct_option+1) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %d\n", q[i].correct_option+1);
        }
    }

    printf("\nYour final score is %d\n", score);

    return 0;
}