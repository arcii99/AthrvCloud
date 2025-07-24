//FormAI DATASET v1.0 Category: Online Examination System ; Style: scalable
#include<stdio.h>

struct question{
    char ques[100];
    char opt1[50];
    char opt2[50];
    char opt3[50];
    char opt4[50];
    char ans[5];
    int score;
};

void print_question(struct question q){
    printf("\n%s",q.ques);
    printf("\nA. %s",q.opt1);
    printf("\nB. %s",q.opt2);
    printf("\nC. %s",q.opt3);
    printf("\nD. %s",q.opt4);
    printf("\nEnter your answer(A/B/C/D): ");
}

int main(){
    int score=0;
    int i;
    struct question q[5];

    strcpy(q[0].ques,"What is the capital of India?");
    strcpy(q[0].opt1,"Mumbai");
    strcpy(q[0].opt2,"Delhi");
    strcpy(q[0].opt3,"Chennai");
    strcpy(q[0].opt4,"Kolkata");
    strcpy(q[0].ans,"B");
    q[0].score=2;

    strcpy(q[1].ques,"Who is the father of our nation?");
    strcpy(q[1].opt1,"Jawaharlal Nehru");
    strcpy(q[1].opt2,"Mahatma Gandhi");
    strcpy(q[1].opt3,"Sardar Patel");
    strcpy(q[1].opt4,"Lal Bahadur Shastri");
    strcpy(q[1].ans,"B");
    q[1].score=2;

    strcpy(q[2].ques,"Who is the Prime Minister of India?");
    strcpy(q[2].opt1,"Narendra Modi");
    strcpy(q[2].opt2,"Amit Shah");
    strcpy(q[2].opt3,"Rahul Gandhi");
    strcpy(q[2].opt4,"Manmohan Singh");
    strcpy(q[2].ans,"A");
    q[2].score=2;

    strcpy(q[3].ques,"What is 10 + 20?");
    strcpy(q[3].opt1,"5");
    strcpy(q[3].opt2,"20");
    strcpy(q[3].opt3,"30");
    strcpy(q[3].opt4,"40");
    strcpy(q[3].ans,"C");
    q[3].score=3;

    strcpy(q[4].ques,"Who invented the telephone?");
    strcpy(q[4].opt1,"Thomas Edison");
    strcpy(q[4].opt2,"Graham Bell");
    strcpy(q[4].opt3,"Isaac Newton");
    strcpy(q[4].opt4,"Albert Einstein");
    strcpy(q[4].ans,"B");
    q[4].score=3;

    printf("\n-------------WELCOME TO THE ONLINE EXAMINATION SYSTEM-------------\n\n");
    printf("\nNote-There are 5 questions and each question carry a different score.\n");
    printf("\n");

    for(i=0;i<5;i++){
        print_question(q[i]);
        char ans[5];
        scanf("%s",&ans);
        if(strcmp(ans,q[i].ans)==0){
            score+=q[i].score;
            printf("\nCorrect Answer!!\n\n");
        }
        else{
            printf("\nWrong Answer!!\n\n");
        }
    }

    printf("\n\n\n-------------------------------------------");
    printf("\n\n\tYour Total score is %d out of 12.",score);
    printf("\n\n-------------------------------------------\n\n");

    return 0;
}