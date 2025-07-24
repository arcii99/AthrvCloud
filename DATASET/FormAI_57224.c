//FormAI DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question{
    char question_statement[200];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int correct_option;
}questions[10]; // limit of 10 questions

int score = 0; // initial score is 0
int question_number = 0; // start at question 1

// function to display question and options
void display_question(){
    printf("\n%s\n", questions[question_number].question_statement);
    printf("1. %s\n", questions[question_number].option1);
    printf("2. %s\n", questions[question_number].option2);
    printf("3. %s\n", questions[question_number].option3);
    printf("4. %s\n", questions[question_number].option4);
}

// function to take user input for answer and check if it's correct
void answer_question(){
    int answer;
    printf("\nEnter your answer: ");
    scanf("%d", &answer);

    if(answer == questions[question_number].correct_option){
        printf("\nCorrect answer!\n");
        score++; // increase score if answer is correct
    }
    else{
        printf("\nIncorrect answer\n");
    }
}

// function to display final score after all questions are answered
void display_score(){
    printf("\n\nYour final score is %d out of 10", score);
}

int main(){
    // sample questions
    strcpy(questions[0].question_statement, "What is the largest planet in our solar system?");
    strcpy(questions[0].option1, "Earth");
    strcpy(questions[0].option2, "Mars");
    strcpy(questions[0].option3, "Jupiter");
    strcpy(questions[0].option4, "Venus");
    questions[0].correct_option = 3;

    strcpy(questions[1].question_statement, "What is the capital of France?");
    strcpy(questions[1].option1, "Berlin");
    strcpy(questions[1].option2, "London");
    strcpy(questions[1].option3, "Paris");
    strcpy(questions[1].option4, "Tokyo");
    questions[1].correct_option = 3;

    strcpy(questions[2].question_statement, "What is the currency of Japan?");
    strcpy(questions[2].option1, "Yen");
    strcpy(questions[2].option2, "Dollar");
    strcpy(questions[2].option3, "Euro");
    strcpy(questions[2].option4, "Pound");
    questions[2].correct_option = 1;

    // continue adding questions in a similar pattern

    // loop through questions and ask them
    for(int i=0; i<10; i++){
        display_question(); // display current question
        answer_question(); // take answer input and check if it's correct
        question_number++; // move on to next question
    }

    display_score(); // display final score

    return 0;
}