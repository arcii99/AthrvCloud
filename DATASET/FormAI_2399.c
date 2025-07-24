//FormAI DATASET v1.0 Category: Online Examination System ; Style: lively
#include<stdio.h>
#include<stdlib.h>

struct Question{
    int id;
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int correct_option;
};

struct Student{
    int roll_no;
    char name[50];
    int marks;
};

int main(){
    int n, m;
    printf("Enter Number of Questions: ");
    scanf("%d", &n);
    struct Question q[n];
    printf("Enter Questions, options and answer: \n");
    for(int i=0;i<n;i++){
        q[i].id = i+1;
        printf("Question %d: \n", q[i].id);
        scanf("%s", &q[i].question);
        printf("Option 1: ");
        scanf("%s", &q[i].option1);
        printf("Option 2: ");
        scanf("%s", &q[i].option2);
        printf("Option 3: ");
        scanf("%s", &q[i].option3);
        printf("Option 4: ");
        scanf("%s", &q[i].option4);
        printf("Correct Option: ");
        scanf("%d", &q[i].correct_option);
    }

    printf("\nEnter Number of Students: ");
    scanf("%d", &m);
    struct Student s[m];
    printf("\nEnter Student Details: \n");
    for(int i=0;i<m;i++){
        s[i].marks = 0;
        printf("Roll Number of Student %d: ", i+1);
        scanf("%d", &s[i].roll_no);
        printf("Name of Student %d: ", i+1);
        scanf("%s", &s[i].name);
    }

    int attempted[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            attempted[i][j] = -1;
        }
    }

    int choice;
    do{
        printf("\n\nMENU: \n");
        printf("1. Attempt Test \n");
        printf("2. View Results \n");
        printf("3. Exit \n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nTest Started! \n");
                for(int i=0;i<n;i++){
                    printf("\nQuestion %d: %s \n", q[i].id, q[i].question);
                    printf("1. %s \n", q[i].option1);
                    printf("2. %s \n", q[i].option2);
                    printf("3. %s \n", q[i].option3);
                    printf("4. %s \n", q[i].option4);
                    int option;
                    printf("Enter Option: ");
                    scanf("%d", &option);

                    if(option-1 == q[i].correct_option){
                        for(int j=0;j<m;j++){
                            if(s[j].roll_no != -1){
                                printf("\n%s Correct! +1 Marks to Roll Number %d, %s", s[j].name, s[j].roll_no, q[i].question);
                                s[j].marks++;
                            }
                        }
                    }
                    else{
                        for(int j=0;j<m;j++){
                            if(s[j].roll_no != -1){
                                printf("\n%s Wrong! 0 Marks to Roll Number %d, %s", s[j].name, s[j].roll_no, q[i].question);
                            }
                        }
                    }
                }

                printf("\n\nTest Over! \n");

                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        attempted[i][j] = -1;
                    }
                }

                printf("\n------------------------------------------------------------------------------------\n");

                break;

            case 2:
                printf("\nRESULTS: \n");
                printf("\nRoll Number \tName \tMarks\n");
                for(int i=0;i<m;i++){
                    printf("%d \t%s \t%d\n", s[i].roll_no, s[i].name, s[i].marks);
                }
                printf("\n------------------------------------------------------------------------------------\n");

                break;

            case 3:
                printf("\n Program Terminated! \n");
                break;

            default:
                printf("\n Invalid Choice! \n");
                printf("\n------------------------------------------------------------------------------------\n");
        }

    }while(choice!=3);

    return 0;
}