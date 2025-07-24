//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random fortune
char* getFortune() {
    srand(time(NULL));  // Seed the random generator
    int index = rand() % 5;  // Generate a random number
    char* fortunes[] = {"You will achieve great success!", "Stay away from danger today.", "You will meet an old friend soon.", "Be careful with finances today.", "Love is in the air for you!"};
    return fortunes[index];  // Return a random fortune
}

int main() {
    char name[20];  // Variable to store user's name
    printf("Welcome to the automated fortune teller. What is your name?: ");
    scanf("%s", name);  // Take user's name as input
    printf("Hello, %s! Let me see my crystal ball and predict your fortune for today...\n", name);
    
    char playAgain = 'y';  // Variable to store user's choice to play again
    while(playAgain == 'y') {  // Loop to keep playing until user chooses to exit
        char* fortune = getFortune();  // Generate a fortune
        printf("\n%s\n\n", fortune);  // Print the fortune
        printf("Would you like to know your fortune again? (y/n): ");
        scanf(" %c", &playAgain);  // Take user's choice to play again as input
    }
    
    printf("Thank you for playing. See you again soon!");
    return 0;
}