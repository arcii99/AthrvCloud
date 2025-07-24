//FormAI DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>

//Main function
int main(){

    //Declaration of variables
    int questions[50];
    int answers[50];
    int score = 0;
    int i;

    //Initialization of questions and answers
    for(i = 0; i < 50; i++){
        questions[i] = i+1;
        answers[i] = i%4 + 1;
    }

    //Welcome message
    printf("Welcome to the Online Examination System!\n\n");

    //Instructions
    printf("Instructions:\n1. There are 50 multiple choice questions.\n");
    printf("2. Each question carries 2 marks.\n3. There is no negative marking.\n\n");

    //Loop for taking input from user and calculating score
    for(i = 0; i < 50; i++){
        printf("Question %d:\nWhat is the answer?\n1. Option A\n2. Option B\n3. Option C\n4. Option D\n", questions[i]);
        scanf("%d", &answers[i]);

        if(answers[i] == i%4 + 1)
            score += 2;
    }

    //Printing the score
    printf("\nYou scored %d out of 100.\n\n", score);

    //Exiting message
    printf("Thank you for using the Online Examination System!\n");

    //Returning 0 to indicate successful termination of program
    return 0;
}