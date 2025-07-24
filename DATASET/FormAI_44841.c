//FormAI DATASET v1.0 Category: Online Examination System ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question{
    char question[100];
    char option1[100];
    char option2[100];
    char option3[100];
    char option4[100];
    int correctanswer;
};

int main(){
    int score = 0;
    int numofquestions = 3;
    struct question exam[numofquestions];
    strcpy(exam[0].question,"What is the capital city of India?");
    strcpy(exam[0].option1,"Delhi");
    strcpy(exam[0].option2,"Mumbai");
    strcpy(exam[0].option3,"Kolkata");
    strcpy(exam[0].option4,"Chennai");
    exam[0].correctanswer = 1;

    strcpy(exam[1].question,"What is the smallest continent of the world?");
    strcpy(exam[1].option1,"Africa");
    strcpy(exam[1].option2,"Europe");
    strcpy(exam[1].option3,"Asia");
    strcpy(exam[1].option4,"Australia");
    exam[1].correctanswer = 4;

    strcpy(exam[2].question,"What year was World War II ended?");
    strcpy(exam[2].option1,"1945");
    strcpy(exam[2].option2,"1939");
    strcpy(exam[2].option3,"1941");
    strcpy(exam[2].option4,"1943");
    exam[2].correctanswer = 1;

    printf("Welcome to the Online Examination System!\n");
    printf("You will be given %d questions.\n",numofquestions);
    printf("Each question will have 4 options and you have to choose 1 option.\n");
    printf("Let's Begin!\n\n");

    for(int i=0;i<numofquestions;i++){
        printf("Question %d: %s\n",i+1,exam[i].question);
        printf("1. %s\n",exam[i].option1);
        printf("2. %s\n",exam[i].option2);
        printf("3. %s\n",exam[i].option3);
        printf("4. %s\n",exam[i].option4);
        int useranswer;
        printf("Enter your choice (1/2/3/4): ");
        scanf("%d",&useranswer);
        if(useranswer == exam[i].correctanswer){
            printf("Correct Answer!!\n\n");
            score++;
        }
        else{
            printf("Wrong Answer...the correct option is %d\n\n",exam[i].correctanswer);
        }
    }

    printf("Your Score: %d\n",score);
    printf("Thanks for participating in the Online Examination System!\n");

    return 0;
}