//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main(void) {
    char user_input[3];
    int score = 0;
    
    printf("Welcome to the C Periodic Table Quiz! \n\n");
    printf("Instructions: \n");
    printf("1. You will be given the name of an element and asked to provide its symbol. \n");
    printf("2. Type in your answer within 2 seconds. \n");
    printf("3. You can exit the quiz at any time by typing 'exit'. \n\n");
    
    printf("*** Let's begin! *** \n\n");
    
    // Question 1
    printf("What is the symbol for Nitrogen? \n");
    scanf("%2s", user_input);
    if (strcmp(user_input, "N") == 0) {
        printf("Correct! \n");
        score++;
    } else {
        printf("Incorrect. The correct answer is 'N'. \n");
    }
    
    // Question 2
    printf("What is the symbol for Oxygen? \n");
    scanf("%2s", user_input);
    if (strcmp(user_input, "O") == 0) {
        printf("Correct! \n");
        score++;
    } else {
        printf("Incorrect. The correct answer is 'O'. \n");
    }
    
    // Question 3
    printf("What is the symbol for Potassium? \n");
    scanf("%2s", user_input);
    if (strcmp(user_input, "K") == 0) {
        printf("Correct! \n");
        score++;
    } else {
        printf("Incorrect. The correct answer is 'K'. \n");
    }
    
    // Question 4
    printf("What is the symbol for Sodium? \n");
    scanf("%2s", user_input);
    if (strcmp(user_input, "Na") == 0) {
        printf("Correct! \n");
        score++;
    } else {
        printf("Incorrect. The correct answer is 'Na'. \n");
    }
    
    // Question 5
    printf("What is the symbol for Calcium? \n");
    scanf("%2s", user_input);
    if (strcmp(user_input, "Ca") == 0) {
        printf("Correct! \n");
        score++;
    } else {
        printf("Incorrect. The correct answer is 'Ca'. \n");
    }
    
    // Results
    printf("\n\n*** Results ***\n");
    printf("Number of correct answers: %d \n", score);
    printf("Number of incorrect answers: %d \n", 5 - score);
    
    return 0;
}