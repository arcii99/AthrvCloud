//FormAI DATASET v1.0 Category: Online Examination System ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question{
    char ques[500];
    char options[4][100];
    int ans;
};

int main(){
    struct question quesarr[10];
    int marks = 0;
    int i, j, ans = 0, resp[10];
    FILE *fp;

    fp = fopen("questions.txt", "r");
    if(fp == NULL) printf("File Error!");

    for(i = 0; i < 10; i++){
        fscanf(fp, "%[^\n]\n", quesarr[i].ques);
        for(j = 0; j < 4; j++) 
            fscanf(fp, "%[^\n]\n", quesarr[i].options[j]);
        fscanf(fp, "%d\n", &quesarr[i].ans);
    }

    printf("****************************************************************\n");
    printf("************************** Online Exam *************************\n");
    printf("****************************************************************\n");

    for(i = 0; i < 10; i++){
        printf("\n\n%s\n", quesarr[i].ques);
        for(j = 0; j < 4; j++) printf("\n%d. %s", j+1, quesarr[i].options[j]);
        printf("\nEnter your response (1-4): ");
        scanf("%d", &resp[i]);
        if(resp[i] == quesarr[i].ans) marks++;
    }

    printf("\n\nYour Score: %d\n\n", marks);
    if(marks >= 5) printf("Congratulations! You have passed the exam.");
    else printf("Better luck next time!");

    return 0;
}