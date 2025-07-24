//FormAI DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question{
    int question_id;
    char question_text[200];
    char options[4][50];
    char correct_option;
};

typedef struct question Question;

int main(){
    Question questions[10];
    int score = 0;
    int user_response;

    //Question 1
    questions[0].question_id = 1;
    strcpy(questions[0].question_text,"What is the full form of CPU?");
    strcpy(questions[0].options[0], "Central Programming Unit");
    strcpy(questions[0].options[1], "Central Processing Unit");
    strcpy(questions[0].options[2], "Central Power Unit");
    strcpy(questions[0].options[3], "Computational Processing Unit");
    questions[0].correct_option = 'b';

    //Question 2
    questions[1].question_id = 2;
    strcpy(questions[1].question_text,"Which one of these is a programming language?");
    strcpy(questions[1].options[0], "Microsoft Excel");
    strcpy(questions[1].options[1], "Java");
    strcpy(questions[1].options[2], "Adobe Photoshop");
    strcpy(questions[1].options[3], "Windows 10");
    questions[1].correct_option = 'b';

    //Question 3
    questions[2].question_id = 3;
    strcpy(questions[2].question_text,"What is the full form of HTML?");
    strcpy(questions[2].options[0], "High Text Market Language");
    strcpy(questions[2].options[1], "Hyper Transferred Markup Language");
    strcpy(questions[2].options[2], "Highly Transferable Markup Language");
    strcpy(questions[2].options[3], "Hyper Text Markup Language");
    questions[2].correct_option = 'd';

    //Question 4
    questions[3].question_id = 4;
    strcpy(questions[3].question_text,"What is the full form of RAM?");
    strcpy(questions[3].options[0], "Random Access Memory");
    strcpy(questions[3].options[1], "Readable Access Memory");
    strcpy(questions[3].options[2], "Reversible Access Memory");
    strcpy(questions[3].options[3], "Repeatable Access Memory");
    questions[3].correct_option = 'a';

    //Question 5
    questions[4].question_id = 5;
    strcpy(questions[4].question_text,"Which one of these belongs to Microsoft?");
    strcpy(questions[4].options[0], "Photoshop");
    strcpy(questions[4].options[1], "Windows");
    strcpy(questions[4].options[2], "Mac OS");
    strcpy(questions[4].options[3], "Linux");
    questions[4].correct_option = 'b';

    printf("Welcome to the online examination!\n\n");

    for(int i=0;i<5;i++){
        printf("Question %d:\n",i+1);
        printf("%s\n",questions[i].question_text);
        printf("a. %s\n",questions[i].options[0]);
        printf("b. %s\n",questions[i].options[1]);
        printf("c. %s\n",questions[i].options[2]);
        printf("d. %s\n",questions[i].options[3]);

        printf("Enter your response (a/b/c/d): \n");
        scanf(" %c",&user_response);

        if(user_response==questions[i].correct_option){
            score++;
            printf("Your response is correct!\n");
        }else{
            printf("Your response is incorrect!\n");
        }

        printf("\n");
    }

    printf("Your exam is over!\n");
    printf("Your final score is %d out of 5!",score);

    return 0;
}