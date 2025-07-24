//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char answer[20], element[10];
    int score = 0;
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Are you ready to start? (y/n): ");
    fgets(answer, 20, stdin);
    
    if (strcmp(answer, "y\n") == 0 || strcmp(answer, "Y\n") == 0) {
        printf("\n");
        printf("Question 1: What is the symbol for helium? ");
        fgets(element, 10, stdin);
        if (strcmp(element, "He\n") == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is He.\n\n");
        }
        
        printf("Question 2: What is the atomic number of carbon? ");
        fgets(element, 10, stdin);
        if (strcmp(element, "6\n") == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is 6.\n\n");
        }
        
        printf("Question 3: What element has the symbol Mg? ");
        fgets(element, 10, stdin);
        if (strcmp(element, "Magnesium\n") == 0 || strcmp(element, "magnesium\n") == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is Magnesium.\n\n");
        }
        
        printf("Question 4: What is the atomic number of oxygen? ");
        fgets(element, 10, stdin);
        if (strcmp(element, "8\n") == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is 8.\n\n");
        }
        
        printf("Question 5: What is the symbol for sodium? ");
        fgets(element, 10, stdin);
        if (strcmp(element, "Na\n") == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is Na.\n\n");
        }
        
        printf("Congratulations, you finished the quiz!\n");
        printf("Your score is: %d/5\n", score);
    } else {
        printf("Okay, have a nice day!\n");
    }
    
    return 0;
}