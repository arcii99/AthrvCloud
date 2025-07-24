//FormAI DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // Seed the random number generator 
    int num1, num2, ans, userAns, i, score = 0;
    char op[3] = "+-"; // Array of operators to randomly choose from
    
    printf("\nWelcome to the Math Exercise!\n");
    printf("You will be given 10 randomly generated math problems to solve.\n");
    printf("Each problem will involve either addition or subtraction.\n");
    printf("You will receive one point for each correct answer.\n");
    printf("Good luck!\n\n");
    
    for(i = 1; i <= 10; i++){
        num1 = rand() % 100; // Generate a random number between 0 and 99
        num2 = rand() % 100;
        int randOp = rand() % 2; // Choose a random operator index
        
        if(op[randOp] == '+'){ // Add the numbers if operator is '+'
            ans = num1 + num2;
            printf("Problem %d: %d + %d = ", i, num1, num2);
        } else { // Subtract the numbers if operator is '-'
            ans = num1 - num2;
            printf("Problem %d: %d - %d = ", i, num1, num2);
        }
        
        scanf("%d", &userAns);
        
        if(userAns == ans){ // Check if user's answer is correct
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The answer was %d.\n", ans);
        }
    }
    
    printf("\nCongratulations! You have completed the Math Exercise.\n");
    printf("You answered %d out of 10 questions correctly.\n", score);
    
    return 0;
}