//FormAI DATASET v1.0 Category: Online Examination System ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Question{
    char ques[100];
    char option1[25], option2[25], option3[25], option4[25];
    int ans;
};

void displayQuiz(struct Question quiz[]){
    for(int i=0;i<5;i++){
        printf("\n\nQuestion %d: %s",i+1,quiz[i].ques);
        printf("\n1. %s",quiz[i].option1);
        printf("\n2. %s",quiz[i].option2);
        printf("\n3. %s",quiz[i].option3);
        printf("\n4. %s",quiz[i].option4);
    }
}

int main(){
    struct Question quiz[5];
    int marks=0;
    char choice;

    strcpy(quiz[0].ques, "What is the capital of India?");
    strcpy(quiz[0].option1,"Mumbai");
    strcpy(quiz[0].option2,"Chennai");
    strcpy(quiz[0].option3,"Kolkata");
    strcpy(quiz[0].option4,"New Delhi");
    quiz[0].ans=4;

    strcpy(quiz[1].ques, "What is the national animal of India?");
    strcpy(quiz[1].option1,"Elephant");
    strcpy(quiz[1].option2,"Tiger");
    strcpy(quiz[1].option3,"Lion");
    strcpy(quiz[1].option4,"Giraffe");
    quiz[1].ans=2;

    strcpy(quiz[2].ques, "Who is known as Missile Man of India?");
    strcpy(quiz[2].option1,"APJ Abdul Kalam");
    strcpy(quiz[2].option2,"Jawaharlal Nehru");
    strcpy(quiz[2].option3,"Sardar Patel");
    strcpy(quiz[2].option4,"Bhagat Singh");
    quiz[2].ans=1;

    strcpy(quiz[3].ques, "Which country is known as the Land of Rising Sun?");
    strcpy(quiz[3].option1,"Japan");
    strcpy(quiz[3].option2,"USA");
    strcpy(quiz[3].option3,"Korea");
    strcpy(quiz[3].option4,"China");
    quiz[3].ans=1;

    strcpy(quiz[4].ques, "Which planet is known as the Red Planet?");
    strcpy(quiz[4].option1,"Mars");
    strcpy(quiz[4].option2,"Jupiter");
    strcpy(quiz[4].option3,"Saturn");
    strcpy(quiz[4].option4,"Venus");
    quiz[4].ans=1;

    printf("Welcome to the Online Quiz System\n");
    printf("Please read the below instructions carefully before proceeding\n\n");
    printf("1. There will be total 5 questions.\n2. Each question carry 2 marks.\n3. There will be no negative marking.\n");
    printf("\nAre you ready to begin with the quiz? (Y/N) : ");
    scanf(" %c",&choice);

    if(choice=='Y' || choice=='y'){
        displayQuiz(quiz);

        int answer;
        for(int i=0;i<5;i++){
            printf("\n\nEnter the correct answer of Question %d : ",i+1);
            scanf("%d",&answer);

            if(answer==quiz[i].ans)
                marks+=2;
        }

        printf("\n\nCongratulation! You have successfully completed the quiz.\n");
        printf("Your score is : %d\n\n",marks);
    }

    return 0;
}