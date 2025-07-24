//FormAI DATASET v1.0 Category: Online Examination System ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Quiz{
    char Questions[5][100];
    char Options[5][4][50];
    char Answers[5];
}Quiz;

void takeQuiz(Quiz quiz){
    int score = 0;
    int i, j;
    char userAnswer;
    for(i=0; i<5; i++){
        printf("Question %d: %s\n", i+1, quiz.Questions[i]);
        for(j=0; j<4; j++){
            printf("%c: %s\n", 65+j, quiz.Options[i][j]);
        }
        printf("Select your answer(A/B/C/D): ");
        scanf("%c", &userAnswer);
        if(userAnswer == quiz.Answers[i]){
            score += 20;
        }
    }
    printf("Your Score is: %d/100\n", score);
}

int main(){
    Quiz quiz;

    strcpy(quiz.Questions[0], "What is the capital of India?");
    strcpy(quiz.Options[0][0], "Mumbai");
    strcpy(quiz.Options[0][1], "Delhi");
    strcpy(quiz.Options[0][2], "Chennai");
    strcpy(quiz.Options[0][3], "Bangalore");
    quiz.Answers[0] = 'B';

    strcpy(quiz.Questions[1], "Which is the largest Ocean in the world?");
    strcpy(quiz.Options[1][0], "Atlantic Ocean");
    strcpy(quiz.Options[1][1], "Arctic Ocean");
    strcpy(quiz.Options[1][2], "Indian Ocean");
    strcpy(quiz.Options[1][3], "Pacific Ocean");
    quiz.Answers[1] = 'D';

    strcpy(quiz.Questions[2], "Mumbai is located on the bank of which river?");
    strcpy(quiz.Options[2][0], "Brahmaputra");
    strcpy(quiz.Options[2][1], "Ganga");
    strcpy(quiz.Options[2][2], "Narmada");
    strcpy(quiz.Options[2][3], "Mithi");
    quiz.Answers[2] = 'D';

    strcpy(quiz.Questions[3], "Which country gifted the Statue of Liberty to USA?");
    strcpy(quiz.Options[3][0], "France");
    strcpy(quiz.Options[3][1], "Italy");
    strcpy(quiz.Options[3][2], "Germany");
    strcpy(quiz.Options[3][3], "Spain");
    quiz.Answers[3] = 'A';

    strcpy(quiz.Questions[4], "Who is the CEO of Amazon?");
    strcpy(quiz.Options[4][0], "Tim Cook");
    strcpy(quiz.Options[4][1], "Satya Nadella");
    strcpy(quiz.Options[4][2], "Mark Zuckerberg");
    strcpy(quiz.Options[4][3], "Jeff Bezos");
    quiz.Answers[4] = 'D';

    takeQuiz(quiz);

    return 0;
}