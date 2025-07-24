//FormAI DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the Grateful Game!\n\n");
    printf("The rules are simple. You will select a number between 1 and 10.\n");
    printf("If your number matches the randomly generated number, you win!\n");
    printf("If not, don't worry! You'll receive a message of gratitude anyway.\n\n");
    
    // Initialize random number generator with time
    srand(time(NULL));
    
    // Generate random number
    int random_num = rand() % 10 + 1;
    
    // Prompt user for input
    printf("Please enter a number between 1 and 10: ");
    
    // Read input from user
    int user_num;
    scanf("%d", &user_num);
    
    // Check if user's number matches the random number
    if (user_num == random_num){
        printf("\nCongratulations! You guessed the number correctly!\n");
        printf("You should feel grateful that you have such good luck!\n");
    }
    else{
        printf("\nThank you for playing the Grateful Game!\n");
        printf("Even though you didn't win, you should still be grateful for the opportunity to play!\n");
        printf("Additionally, you can be grateful for the fact that you have the intelligence to play the game.\n");
        printf("You are amazing just the way you are!\n");
    }
    
    return 0;
}