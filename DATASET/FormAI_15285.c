//FormAI DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, answer, player_answer, num_questions, correct_answers = 0;
    char operator;
  
    printf("Welcome to the Math Exercise Game!\n\n");
    printf("How many questions would you like to answer today? ");
    scanf("%d", &num_questions);
  
    // Generate random math exercises and ask the player to solve them
    srand(time(NULL));
  
    for (int i = 0; i < num_questions; i++) {
        num1 = rand() % 100;
        num2 = rand() % 100;
      
        // Randomly select an operator (+, -, *, or /)
        switch(rand() % 4) {
            case 0: operator = '+'; answer = num1 + num2; break;
            case 1: operator = '-'; answer = num1 - num2; break;
            case 2: operator = '*'; answer = num1 * num2; break;
            case 3: operator = '/'; answer = num1 / num2; break;
        }
      
        printf("Question #%d: What is %d %c %d?\n", i+1, num1, operator, num2);
        scanf("%d", &player_answer);
      
        // Check if the player's answer is correct
        if (player_answer == answer) {
            printf("Great job! You got it right!\n\n");
            correct_answers++;
        } else {
            printf("Sorry, the correct answer is %d.\n\n", answer);
        }
    }
  
    // Calculate and display the player's score
    float score = ((float) correct_answers / num_questions) * 100;
    printf("Congratulations! You answered %d out of %d questions correctly (%.2f%%).\n", correct_answers, num_questions, score);
  
    return 0;
}