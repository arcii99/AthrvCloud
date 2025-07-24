//FormAI DATASET v1.0 Category: Online Examination System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question {
    char ques[100];
    char options[4][50];
    int correct_option;
};

void insert_question(struct question ques_array[]) {
    static int i=0;
    printf("Enter question:\n");
    scanf(" %[^\n]",ques_array[i].ques);
    printf("Enter options:\n");
    scanf(" %[^\n]",ques_array[i].options[0]);
    scanf(" %[^\n]",ques_array[i].options[1]);
    scanf(" %[^\n]",ques_array[i].options[2]);
    scanf(" %[^\n]",ques_array[i].options[3]);
    printf("Enter correct option:\n");
    scanf("%d",&ques_array[i].correct_option);
    i++;
    char choice;
    printf("Do you want to add more questions? Press y for Yes and n for No.\n");
    scanf(" %c",&choice);
    if(choice == 'y') {
        insert_question(ques_array);
    }
}

void display_question(struct question ques) {
    printf("%s\n",ques.ques);
    printf("1. %s\n",ques.options[0]);
    printf("2. %s\n",ques.options[1]);
    printf("3. %s\n",ques.options[2]);
    printf("4. %s\n",ques.options[3]);
}

void start_exam(struct question ques_array[], int size, int i) {
    if(i >= size) { //Base case
        return;
    }
    display_question(ques_array[i]);
    int chosen_option;
    printf("Enter your choice:\n");
    scanf("%d",&chosen_option);
    if(chosen_option == ques_array[i].correct_option) {
        printf("Correct answer! Move to next question.\n");
    }
    else {
        printf("Incorrect answer! Move to next question.\n");
    }
    i++;
    start_exam(ques_array,size,i); //Recursive call
}

int main() {
    printf("Welcome to the Online Examination System!\n");
    struct question ques_array[20];
    insert_question(ques_array);
    printf("The exam starts now!\n");
    start_exam(ques_array,20,0); //Start exam with 20 questions
    printf("Thank you for taking the exam!\n");
    return 0;
}