//FormAI DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, mark=0, choice;
    char ans;

    //creating a structure to store the questions and answer choices
    struct question{
        char ques[100];
        char optA[50];
        char optB[50];
        char optC[50];
        char optD[50];
        char correctAns;
    }q[5];

    //initializing the questions and answer choices
    strcpy(q[0].ques,"What is the capital of India?");
    strcpy(q[0].optA,"Delhi");
    strcpy(q[0].optB,"Mumbai");
    strcpy(q[0].optC,"Kolkata");
    strcpy(q[0].optD,"Chennai");
    q[0].correctAns='A';

    strcpy(q[1].ques,"Which of the following is not a programming language?");
    strcpy(q[1].optA,"Java");
    strcpy(q[1].optB,"Python");
    strcpy(q[1].optC,"HTML");
    strcpy(q[1].optD,"SQL");
    q[1].correctAns='C';

    strcpy(q[2].ques,"Who is the CEO of Apple Inc.?");
    strcpy(q[2].optA,"Tim Cook");
    strcpy(q[2].optB,"Jeff Bezos");
    strcpy(q[2].optC,"Satya Nadella");
    strcpy(q[2].optD,"Mark Zuckerberg");
    q[2].correctAns='A';

    strcpy(q[3].ques,"What is the largest planet in our solar system?");
    strcpy(q[3].optA,"Earth");
    strcpy(q[3].optB,"Mars");
    strcpy(q[3].optC,"Jupiter");
    strcpy(q[3].optD,"Saturn");
    q[3].correctAns='C';

    strcpy(q[4].ques,"What is the scientific name of pineapple?");
    strcpy(q[4].optA,"Ananas comosus");
    strcpy(q[4].optB,"Mango indica");
    strcpy(q[4].optC,"Papaya carica");
    strcpy(q[4].optD,"Litchi chinensis");
    q[4].correctAns='A';

    //printing instructions and asking for user confirmation to start the test
    printf("Welcome to the Online Examination System!\n");
    printf("You will be given 5 multiple choice questions.\n");
    printf("You will have to select A/B/C/D as your answer.\n");
    printf("Type 1 to start the test: ");
    scanf("%d",&choice);

    //starting the test if user confirms
    if(choice==1){
        srand(time(0)); //using current time as seed for random number generator
        printf("\n");

        //asking each question and verifying the answer
        for(i=0;i<5;i++){
            printf("%d. %s\n",i+1,q[i].ques);
            printf("A. %s\n",q[i].optA);
            printf("B. %s\n",q[i].optB);
            printf("C. %s\n",q[i].optC);
            printf("D. %s\n",q[i].optD);
            printf("Your answer: ");
            scanf(" %c",&ans);
            if(toupper(ans)==q[i].correctAns){
                printf("Correct answer! You get 2 marks.\n\n");
                mark+=2;
            }
            else{
                printf("Incorrect answer. No marks awarded.\n\n");
            }
        }

        //printing the final score
        printf("Your total score is %d out of 10.\n",mark);

        //awarding certificate based on score
        if(mark==10) printf("Congratulations! You have passed with distinction!\n");
        else if(mark>=6 && mark<=9) printf("Congratulations! You have passed the exam.\n");
        else printf("Sorry, you have failed the exam.\n");
    }
    else{
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}