//FormAI DATASET v1.0 Category: Online Examination System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question{
    char ques[150];
    char op1[50];
    char op2[50];
    char op3[50];
    char op4[50];
    char ans[50];
};

int main(){
    struct question q[5];
    int i, total_score = 0;
    char opt[50];

    strcpy(q[0].ques, "What is the capital of India?");
    strcpy(q[0].op1, "Mumbai");
    strcpy(q[0].op2, "Delhi");
    strcpy(q[0].op3, "Kolkata");
    strcpy(q[0].op4, "Chennai");
    strcpy(q[0].ans, "Delhi");

    strcpy(q[1].ques, "Who is the first prime minister of India?");
    strcpy(q[1].op1, "Jawaharlal Nehru");
    strcpy(q[1].op2, "Lal Bahadur Shastri");
    strcpy(q[1].op3, "Indira Gandhi");
    strcpy(q[1].op4, "Rajiv Gandhi");
    strcpy(q[1].ans, "Jawaharlal Nehru");

    strcpy(q[2].ques, "What is the currency of Japan?");
    strcpy(q[2].op1, "Yen");
    strcpy(q[2].op2, "Dollar");
    strcpy(q[2].op3, "Rupee");
    strcpy(q[2].op4, "Euro");
    strcpy(q[2].ans, "Yen");

    strcpy(q[3].ques, "Who directed the movie Bahubali?");
    strcpy(q[3].op1, "SS Rajamouli");
    strcpy(q[3].op2, "Karan Johar");
    strcpy(q[3].op3, "Sanjay Leela Bhansali");
    strcpy(q[3].op4, "Prabhas");
    strcpy(q[3].ans, "SS Rajamouli");

    strcpy(q[4].ques, "What is the national animal of India?");
    strcpy(q[4].op1, "Cow");
    strcpy(q[4].op2, "Tiger");
    strcpy(q[4].op3, "Lion");
    strcpy(q[4].op4, "Elephant");
    strcpy(q[4].ans, "Tiger");

    printf("Welcome to the Online Examination System!\n");
    printf("There are 5 questions in this test.\n");
    printf("Each correct answer carries 2 marks.\n");
    printf("Please type your answer in the format of 'Answer Number'. Eg: 'a' for Option A.\n\n");

    for(i=0; i<5; i++){
        printf("Q%d. %s\n", i+1, q[i].ques);
        printf("a. %s\n", q[i].op1);
        printf("b. %s\n", q[i].op2);
        printf("c. %s\n", q[i].op3);
        printf("d. %s\n", q[i].op4);
        printf("Answer: ");
        scanf("%s", opt);
        if(strcmp(opt, "a")==0 && strcmp(q[i].op1, q[i].ans)==0){
            total_score += 2;
        }
        else if(strcmp(opt, "b")==0 && strcmp(q[i].op2, q[i].ans)==0){
            total_score += 2;
        }
        else if(strcmp(opt, "c")==0 && strcmp(q[i].op3, q[i].ans)==0){
            total_score += 2;
        }
        else if(strcmp(opt, "d")==0 && strcmp(q[i].op4, q[i].ans)==0){
            total_score += 2;
        }
        printf("\n");
    }

    printf("Your total score is: %d\n", total_score);

    return 0;
}