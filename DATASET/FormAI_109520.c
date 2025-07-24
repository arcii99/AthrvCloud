//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: invasive
//Welcome to the C Periodic Table Quiz program.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define global variables that hold the number of questions and the user's score.
int num_questions = 10, score = 0;

int main()
{
    char answer[10];

    // Create an array of structs to hold all the questions, answers and options.
    struct quiz{
        char question[100];
        char option1[20];
        char option2[20];
        char option3[20];
        char option4[20];
        char answer[20];
    } questions[10];
    
    // Initialize the questions, options and answers.
    strcpy(questions[0].question,"What is the symbol for Carbon");
    strcpy(questions[0].option1,"C");
    strcpy(questions[0].option2,"O");
    strcpy(questions[0].option3,"H");
    strcpy(questions[0].option4,"N");
    strcpy(questions[0].answer,"C");
    
    strcpy(questions[1].question,"How many elements are there in the periodic table?");
    strcpy(questions[1].option1,"101");
    strcpy(questions[1].option2,"118");
    strcpy(questions[1].option3,"120");
    strcpy(questions[1].option4,"125");
    strcpy(questions[1].answer,"118");

    strcpy(questions[2].question,"What is the symbol for Helium?");
    strcpy(questions[2].option1,"He");
    strcpy(questions[2].option2,"H");
    strcpy(questions[2].option3,"C");
    strcpy(questions[2].option4,"O");
    strcpy(questions[2].answer,"He");
    
    strcpy(questions[3].question,"What is the atomic number of gold?");
    strcpy(questions[3].option1,"79");
    strcpy(questions[3].option2,"80");
    strcpy(questions[3].option3,"81");
    strcpy(questions[3].option4,"82");
    strcpy(questions[3].answer,"79");
    
    strcpy(questions[4].question,"Which element is the most abundant gas in the atmosphere?");
    strcpy(questions[4].option1,"Oxygen");
    strcpy(questions[4].option2,"Nitrogen");
    strcpy(questions[4].option3,"Carbon dioxide");
    strcpy(questions[4].option4,"Hydrogen");
    strcpy(questions[4].answer,"Nitrogen");
    
    strcpy(questions[5].question,"What is the symbol for Iron?");
    strcpy(questions[5].option1,"Fe");
    strcpy(questions[5].option2,"I");
    strcpy(questions[5].option3,"Au");
    strcpy(questions[5].option4,"Ag");
    strcpy(questions[5].answer,"Fe");
    
    strcpy(questions[6].question,"What is the atomic number of chlorine?");
    strcpy(questions[6].option1,"17");
    strcpy(questions[6].option2,"18");
    strcpy(questions[6].option3,"19");
    strcpy(questions[6].option4,"20");
    strcpy(questions[6].answer,"17");
    
    strcpy(questions[7].question,"What is the symbol for Sodium?");
    strcpy(questions[7].option1,"Na");
    strcpy(questions[7].option2,"So");
    strcpy(questions[7].option3,"Ca");
    strcpy(questions[7].option4,"Si");
    strcpy(questions[7].answer,"Na");
    
    strcpy(questions[8].question,"What is the symbol for Hydrogen?");
    strcpy(questions[8].option1,"H");
    strcpy(questions[8].option2,"He");
    strcpy(questions[8].option3,"O");
    strcpy(questions[8].option4,"N");
    strcpy(questions[8].answer,"H");
    
    strcpy(questions[9].question,"What is the atomic number of uranium?");
    strcpy(questions[9].option1,"90");
    strcpy(questions[9].option2,"92");
    strcpy(questions[9].option3,"94");
    strcpy(questions[9].option4,"96");
    strcpy(questions[9].answer,"92");

    printf("Welcome to the C Periodic Table quiz program! You will be asked %d questions to test your knowledge on the periodic table of elements.\n", num_questions);
    printf("Please enter the correct answer (A, B, C or D). Let's begin!\n");

    // For loop to ask all the questions in the quiz and keep track of the user's score.
    for(int i=0; i<num_questions; i++){
        printf("%d. %s\n", i+1, questions[i].question);
        printf("   A. %s   B. %s\n", questions[i].option1, questions[i].option2);
        printf("   C. %s   D. %s\n", questions[i].option3, questions[i].option4);
        printf("Your answer: ");
        scanf("%s", answer);
        if(strcmp(answer, questions[i].answer) == 0){
            printf("Correct!\n");
            score++;
        }else{
            printf("Incorrect! The correct answer is %s\n", questions[i].answer);
        }
    }
    printf("Quiz complete. You scored %d out of %d. Thanks for playing!\n", score, num_questions);
    return 0;
}