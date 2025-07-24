//FormAI DATASET v1.0 Category: Online Examination System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question{
    char ques[200];
    char options[5][100];
    int answer;
};

int main(){
    int total_questions = 3;
    int count = 0;
    struct question q[total_questions];
    int i,j;
    for(i=0;i<total_questions;i++){
        printf("Enter question %d : ",i+1);
        scanf(" %[^\n]s",q[i].ques);
        printf("Enter options : \n");
        for(j=0;j<4;j++){
            scanf(" %[^\n]s",q[i].options[j]);
        }
        printf("Enter the correct option : ");
        scanf(" %d",&q[i].answer);
    }

    int score = 0;
    for(i=0;i<total_questions;i++){
        printf("\n\nQuestion %d : %s\n",i+1,q[i].ques);
        for(j=0;j<4;j++){
            printf("%c) %s\n",65+j,q[i].options[j]);  // ascii value of 'A' = 65
        }
        int answer;
        printf("Enter your answer : ");
        scanf(" %d",&answer);
        if(answer == q[i].answer){
            score++;
        }
    }

    printf("\n\nYour score is %d out of %d\n\n",score,total_questions);
    return 0;
}