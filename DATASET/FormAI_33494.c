//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int score = 0; //initial score is 0
    srand(time(0)); //initialize random seed
    
    printf("------------Welcome to the C Periodic Table Quiz!------------\n");
    printf("Answer the following 10 questions to test your knowledge!\n\n");
    
    //array of questions and corresponding answers
    char* questions[] = {"What is the symbol for nitrogen?", 
                         "What is the atomic number for gold?", 
                         "What is the symbol for potassium?", 
                         "What is the atomic number for oxygen?", 
                         "What is the symbol for sodium?", 
                         "What is the atomic number for helium?", 
                         "What is the symbol for carbon?", 
                         "What is the atomic number for sulfur?", 
                         "What is the symbol for iron?", 
                         "What is the atomic number for magnesium?"};
    
    char* answers[] = {"N", "79", "K", "8", "Na", "2", "C", "16", "Fe", "12"};
    
    //loop through each question
    for(int i=0; i<10; i++) {
        printf("Question %d: %s\n", i+1, questions[i]);
        
        //get user input
        char input[255];
        scanf("%s", input);
        
        //check if user input is correct
        if(strcmp(input, answers[i]) == 0) {
            printf("Correct!\n");
            score++; //increment score
        } else {
            printf("Incorrect. The correct answer is %s.\n", answers[i]);
        }
    }
    
    printf("\n------------------------\n");
    printf("Quiz Finished!\n");
    printf("Your score is %d out of 10.\n", score);
    
    return 0; //exit program
}