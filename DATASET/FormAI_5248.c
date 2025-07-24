//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator with the current time
    srand(time(0));
    
    // Declare variables for user input and random number
    int user_number, computer_number;
    
    // Get input from user
    printf("Enter a number between 1 and 10: ");
    scanf("%d", &user_number);
    
    // Generate a random number between 1 and 10
    computer_number = rand() % 10 + 1;
    
    // Compare the user input with the computer's number
    if (user_number == computer_number) {
        printf("Congratulations, you have won the lottery!\n");
    } else {
        printf("Sorry, you did not win this time. The computer's number was %d.\n", computer_number);
    }
    
    return 0;
}