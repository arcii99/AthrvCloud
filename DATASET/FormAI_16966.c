//FormAI DATASET v1.0 Category: Math exercise ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int level, i, x, y, answer, user_answer, correct = 0, incorrect = 0;
    char restart;
    double score;
    srand(time(NULL)); // seed random number generator
    
    do {
        printf("Welcome to the math quiz!\n\n");
        printf("Please choose a difficulty level (1-3): ");
        scanf("%d", &level);
        
        while (1) {
            x = rand() % (int)pow(10, level); // generate random numbers within the chosen difficulty level
            y = rand() % (int)pow(10, level);
            answer = x + y; // calculate the answer
            
            printf("\nQuestion %d:\n", correct + incorrect + 1);
            printf("%d + %d = ", x, y);
            scanf("%d", &user_answer);
            
            if (user_answer == answer) {
                printf("Correct!\n");
                correct++;
            } else {
                printf("Incorrect. The correct answer is %d\n", answer);
                incorrect++;
            }
            
            // keep track of progress and give final score at the end
            score = (double)correct / (correct + incorrect) * 100;
            printf("Score: %.2lf%% (%d correct, %d incorrect)\n", score, correct, incorrect);
            
            // ask the user if they want to continue
            if (correct + incorrect == 10) {
                break;
            }
            
            printf("Continue? (y/n) ");
            scanf(" %c", &restart);
            if (restart == 'n') {
                break;
            }
        }
        
        printf("Final Score: %.2lf%% (%d correct, %d incorrect)\n", score, correct, incorrect);
        
        printf("Would you like to play again? (y/n) ");
        scanf(" %c", &restart);
        correct = 0;
        incorrect = 0;
        
    } while (restart == 'y');
    
    printf("Thanks for playing!\n");
    return 0;
}