//FormAI DATASET v1.0 Category: Online Examination System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct questions{
    char question[200];
    char option1[100];
    char option2[100];
    char option3[100];
    char option4[100];
    int answer;
} ;

int main(){
    struct questions q[10];
    int i, marks=0, ans;

    printf("Welcome to the Online Examination System\n");
    printf("\nEnter 10 Questions and its respective options\n");
    for(i=0;i<10;i++){
        printf("\nEnter Question %d: ", i+1);
        fgets(q[i].question, 200, stdin);
        printf("\nEnter Option 1: ");
        fgets(q[i].option1, 100, stdin);
        printf("\nEnter Option 2: ");
        fgets(q[i].option2, 100, stdin);
        printf("\nEnter Option 3: ");
        fgets(q[i].option3, 100, stdin);
        printf("\nEnter Option 4: ");
        fgets(q[i].option4, 100, stdin);
        printf("\nEnter Answer: ");
        scanf("%d", &q[i].answer);
        fflush(stdin);
    }

    printf("\n\nThe Exam Begins Now...\n");
    for(i=0;i<10;i++){
        printf("\n\n%d. %s\n%s%s%s%s\n", i+1, q[i].question, q[i].option1, q[i].option2, q[i].option3, q[i].option4);
        printf("\nEnter your answer: ");
        scanf("%d", &ans);
        if(ans==q[i].answer)
            marks++;
    }

    printf("\n\n\nYour total marks: %d/10\n", marks);
    return 0;
}