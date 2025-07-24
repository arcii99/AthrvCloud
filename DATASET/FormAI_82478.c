//FormAI DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

char answers[10] = {'A', 'C', 'D', 'B', 'B', 'A', 'C', 'D', 'B', 'A'};
char studentAnswers[10];
int score = 0;

void getAnswers(){
    printf("Enter your answers: \n");
    for(int i = 0; i < 10; i++){
        printf("Question %d: ", i+1);
        scanf(" %c", &studentAnswers[i]);
    }
}

void calculateScore(){
    for(int i = 0; i < 10; i++){
        if(studentAnswers[i] == answers[i]){
            score++;
        }
    }
}

void displayResult(){
    printf("Your score is: %d/10\n", score);
    if(score >= 8){
        printf("Great job! You passed the exam.\n");
    }else{
        printf("Better luck next time.\n");
    }
}

int main(){
    printf("Welcome to the Online Examination System.\n");
    printf("You will be presented with 10 multiple choice questions.\n");
    getAnswers();
    calculateScore();
    displayResult();
    return 0;
}