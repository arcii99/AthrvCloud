//FormAI DATASET v1.0 Category: Online Examination System ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure definition for question
struct Question {
    char question[200];//storing question
    char option[4][50];//storing options for each question
    char answer;//storing correct answer
};

//function to display the question and options
void displayQuestion(struct Question qn){
    printf("\n%s\n", qn.question);
    for(int i=0; i<4; i++){
        printf("%c. %s\n", 'A'+i, qn.option[i]);
    }
}

//main function
int main(){

    struct Question qn[5];//array to store 5 questions

    //question 1
    strcpy(qn[0].question, "What is the capital of India?");
    strcpy(qn[0].option[0], "Mumbai");
    strcpy(qn[0].option[1], "New Delhi");
    strcpy(qn[0].option[2], "Kolkata");
    strcpy(qn[0].option[3], "Chennai");
    qn[0].answer = 'B';

    //question 2
    strcpy(qn[1].question, "Who is the founder of Apple Inc.?");
    strcpy(qn[1].option[0], "Steve Jobs");
    strcpy(qn[1].option[1], "Bill Gates");
    strcpy(qn[1].option[2], "Mark Zuckerberg");
    strcpy(qn[1].option[3], "Jeff Bezos");
    qn[1].answer = 'A';

    //question 3
    strcpy(qn[2].question, "Which of the following is a primary color of light?");
    strcpy(qn[2].option[0], "Red");
    strcpy(qn[2].option[1], "Green");
    strcpy(qn[2].option[2], "Blue");
    strcpy(qn[2].option[3], "Yellow");
    qn[2].answer = 'C';

    //question 4
    strcpy(qn[3].question, "What does RAM stand for in a computer?");
    strcpy(qn[3].option[0], "Random Access Memory");
    strcpy(qn[3].option[1], "Read-Only Memory");
    strcpy(qn[3].option[2], "Hard Disk Drive");
    strcpy(qn[3].option[3], "Central Processing Unit");
    qn[3].answer = 'A';

    //question 5
    strcpy(qn[4].question, "Who is the current CEO of Tesla Inc.?");
    strcpy(qn[4].option[0], "Mark Zuckerberg");
    strcpy(qn[4].option[1], "Elon Musk");
    strcpy(qn[4].option[2], "Tim Cook");
    strcpy(qn[4].option[3], "Satya Nadella");
    qn[4].answer = 'B';

    int marks = 0;//variable to store marks obtained

    printf("Welcome to the Online Examination System!\n");

    //loop through the questions and get answers from the user
    for(int i=0; i<5; i++){
        printf("\nQuestion %d:\n", i+1);
        displayQuestion(qn[i]);

        char userAnswer;
        printf("\nEnter your answer (A/B/C/D): ");
        scanf("\n%c", &userAnswer);

        if(userAnswer == qn[i].answer){
            marks++;
        }
    }

    printf("\nYour score is: %d/5", marks);//display marks obtained

    return 0;
}