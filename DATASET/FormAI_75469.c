//FormAI DATASET v1.0 Category: Online Examination System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

struct node {
    int quesid, option1, option2, option3, option4, ans;
};

int main() {
    int numQuestions, score=0, answer;
    printf("Welcome to the Online Examination System\n");
    printf("Enter the number of questions you want to attempt: ");
    scanf("%d", &numQuestions);

    struct node questions[numQuestions];
    for(int i=0; i<numQuestions; i++) {
        printf("Enter details for Question %d\n", i+1);
        printf("Question ID: ");
        scanf("%d", &questions[i].quesid);
        printf("Option 1: ");
        scanf("%d", &questions[i].option1);
        printf("Option 2: ");
        scanf("%d", &questions[i].option2);
        printf("Option 3: ");
        scanf("%d", &questions[i].option3);
        printf("Option 4: ");
        scanf("%d", &questions[i].option4);
        printf("Answer: ");
        scanf("%d", &questions[i].ans);
    }

    printf("\n\nExam Begins\n");
    for(int i=0; i<numQuestions; i++) {
        printf("Question %d: \n", i+1);
        printf("Option 1: %d\n", questions[i].option1);
        printf("Option 2: %d\n", questions[i].option2);
        printf("Option 3: %d\n", questions[i].option3);
        printf("Option 4: %d\n", questions[i].option4);
        printf("Your Answer: ");
        scanf("%d", &answer);
        if(answer == questions[i].ans) {
            score++;
        }
    }

    printf("\nYour Score is: %d out of %d\n", score, numQuestions);
    printf("Thank you for taking the exam!\n");

    return 0;
}