//FormAI DATASET v1.0 Category: Online Examination System ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_QUESTIONS 50
#define MAX_OPTIONS 4

typedef struct{     //structure to hold the question and options
    char question[100];
    char option[MAX_OPTIONS][50];
    int correct_option;
}Question;

Question questions[MAX_QUESTIONS];   //array of questions

int num_questions=0;    //to keep track of number of questions

void addQuestion(Question q){    //function to add question to array of questions
    questions[num_questions++]=q;
}

void displayQuestion(Question q){    //function to display the question
    printf("%s\n",q.question);
    for(int i=0;i<MAX_OPTIONS;i++){
        printf("%d. %s\n",i+1,q.option[i]);
    }
}

int takeTest(){     //function to take the test
    int score=0;
    for(int i=0;i<num_questions;i++){
        printf("Question %d:\n",i+1);
        displayQuestion(questions[i]);
        int user_option;
        printf("Enter your choice(1-4): ");
        scanf("%d",&user_option);
        if(user_option==questions[i].correct_option){
            printf("Correct Answer!\n");
            score++;
        }
        else{
            printf("Wrong Answer\n");
        }
    }
    return score;
}

int main(){
    printf("Welcome to the Online Examination System\n");
    printf("----------------------------------------\n");

    //adding questions
    Question q1,q2,q3,q4,q5;
    strcpy(q1.question,"What does the acronym RAM stand for?");
    strcpy(q1.option[0],"Read Only Memory");
    strcpy(q1.option[1],"Random Access Memory");
    strcpy(q1.option[2],"Real Access Memory");
    strcpy(q1.option[3],"Real Only Memory");
    q1.correct_option=2;

    strcpy(q2.question,"Which one of the following is not a data type?");
    strcpy(q2.option[0],"int");
    strcpy(q2.option[1],"char");
    strcpy(q2.option[2],"real");
    strcpy(q2.option[3],"float");
    q2.correct_option=3;

    strcpy(q3.question,"Which one of the following is not a programming language?");
    strcpy(q3.option[0],"C++");
    strcpy(q3.option[1],"C#");
    strcpy(q3.option[2],"Java");
    strcpy(q3.option[3],"Microsoft Excel");
    q3.correct_option=4;

    strcpy(q4.question,"What is the value of x after the following code: int x=5; x++;");
    strcpy(q4.option[0],"6");
    strcpy(q4.option[1],"5");
    strcpy(q4.option[2],"4");
    strcpy(q4.option[3],"7");
    q4.correct_option=1;

    strcpy(q5.question,"What is the output of the following code: printf(\"%%d\",sizeof(int));");
    strcpy(q5.option[0],"4");
    strcpy(q5.option[1],"2");
    strcpy(q5.option[2],"8");
    strcpy(q5.option[3],"Depends on the computer architecture");
    q5.correct_option=1;

    addQuestion(q1);
    addQuestion(q2);
    addQuestion(q3);
    addQuestion(q4);
    addQuestion(q5);

    int choice;
    do{     //menu driven loop
        printf("\n1. Start Test\n");
        printf("2. Add Question\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nStarting Test...\n");
                int score=takeTest();
                printf("\nYour Score: %d/%d\n",score,num_questions);
                break;
            case 2:
                printf("\nAdding new Question...\n");
                Question new_q;
                printf("Enter question: ");
                scanf("%s",new_q.question);
                printf("Enter options: \n");
                for(int i=0;i<MAX_OPTIONS;i++){
                    scanf("%s",new_q.option[i]);
                }
                printf("Enter correct option: ");
                scanf("%d",&new_q.correct_option);
                addQuestion(new_q);
                printf("Question Added Successfully!\n");
                break;
            case 3:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
        }
    }while(choice!=3);

    return 0;
}