//FormAI DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get and validate user input
int getValidInput() {
    int userChoice;
    do {
        printf("Enter your choice (1-3): ");
        scanf("%d", &userChoice);
    } while (userChoice < 1 || userChoice > 3);
    return userChoice;
}

// function to generate computer's choice
int getComputerChoice() {
    srand(time(0)); // seed for random number generation
    return (rand() % 3) + 1; // generate a random number between 1 and 3
}

// function to compare user's and computer's choice and declare the winner
void declareWinner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        printf("It's a tie!\n");
    } else if ((userChoice == 1 && computerChoice == 3) || 
               (userChoice == 2 && computerChoice == 1) || 
               (userChoice == 3 && computerChoice == 2)) {
        printf("Congratulations! You win!\n");
    } else {
        printf("Sorry! Computer wins!\n");
    }
}

int main() {
    int userChoice, computerChoice;
    printf("Welcome to the Rock-Paper-Scissors game!\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    userChoice = getValidInput(); // get and validate user's choice
    printf("You chose: %d\n", userChoice);
    computerChoice = getComputerChoice(); // generate computer's choice
    printf("Computer chose: %d\n", computerChoice);
    declareWinner(userChoice, computerChoice); // compare and declare the winner
    return 0;
}