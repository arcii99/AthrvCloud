//FormAI DATASET v1.0 Category: Online Examination System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANS_LENGTH 20
#define MAX_NAME_LENGTH 20

//the question struct
struct question {
    char text[100];
    char correct_answer[MAX_ANS_LENGTH];
};

//the user struct
struct user {
    char name[MAX_NAME_LENGTH];
    int score;
};

int main() {
    //initialize questions array
    struct question questions[MAX_QUESTIONS];
    
    //populate questions array
    strcpy(questions[0].text, "What is the capital of France?");
    strcpy(questions[0].correct_answer, "Paris");
    
    strcpy(questions[1].text, "What is the command to compile a C program?");
    strcpy(questions[1].correct_answer, "gcc");
    
    //initialize user
    struct user u1;
    
    printf("Welcome to the Online C Examination System!\n");
    printf("Please enter your name: ");
    fgets(u1.name, MAX_NAME_LENGTH, stdin);
    u1.name[strcspn(u1.name, "\n")] = '\0';
    
    //start exam
    printf("Hello %s, let's start the exam!\n", u1.name);
    for(int i=0; i<MAX_QUESTIONS; i++) {
        printf("\nQuestion %d:\n%s\n", i+1, questions[i].text);
        printf("Enter your answer: ");
        char user_ans[MAX_ANS_LENGTH];
        fgets(user_ans, MAX_ANS_LENGTH, stdin);
        user_ans[strcspn(user_ans, "\n")] = '\0';
        
        if(strcmp(user_ans, questions[i].correct_answer) == 0) {
            printf("Correct!\n");
            u1.score += 10;
        } else {
            printf("Incorrect, the correct answer is: %s\n", questions[i].correct_answer);
        }
    }
    
    //display score
    printf("\n\nCongratulations %s! Your final score is: %d\n", u1.name, u1.score);
    
    return 0;
}