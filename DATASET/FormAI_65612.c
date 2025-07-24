//FormAI DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator
    
    int num1, num2, answer, user_answer, score = 0;
    
    // print welcome message
    printf("Welcome to the Math Exercise!\n");
    printf("You will be given two random numbers between 1 and 10 and you will have to add them.\n");
    printf("You will earn one point for each correct answer.\n");
    printf("You will have 10 questions in total. Good luck!\n");
    
    // loop for 10 questions
    for(int i=1; i<=10; i++) {
        // generate two random numbers and calculate the answer
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;
        answer = num1 + num2;
        
        // prompt the user for their answer
        printf("\nQuestion %d: What is %d + %d?\n", i, num1, num2);
        scanf("%d", &user_answer);
        
        // check if the answer is correct
        if(user_answer == answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", answer);
        }
    }
    
    // print final score
    printf("\nEnd of game. Your final score is %d out of 10.\n", score);
    
    return 0;
}