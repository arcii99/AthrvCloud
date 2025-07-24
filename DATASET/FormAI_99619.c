//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5    // Maximum number of fortunes

// An array of fortunes to be randomly selected
char *fortunes[MAX] = {
    "You will find love in the most unexpected place.",
    "Good news will come to you when you least expect it.",
    "You will overcome a great challenge in the near future.",
    "Your hard work will be rewarded soon.",
    "A valuable lesson will be learned from a mistake you make."
};

// Recursively print out fortunes until the user decides to quit
void printFortune() {
    int random = rand() % MAX;      // Generate a random number between 0 and MAX
    printf("\n%s\n\n", fortunes[random]);    // Print out a randomly selected fortune
    printf("Would you like another fortune?\n");
    char choice = getchar();        // Get user input
    if(choice == '\n')              // Make sure we are only getting a single character
        choice = getchar();         
    if (choice == 'y' || choice == 'Y')
        printFortune();             // If the user chooses to continue, recursively call printFortune
    else
        printf("Goodbye!\n");       // Otherwise, end the program
}

int main() {
    srand(time(NULL));             // Seed the random number generator with the current time
    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Would you like a fortune?\n");
    char choice = getchar();        // Get user input
    if(choice == '\n')              // Make sure we are only getting a single character
        choice = getchar();
    if (choice == 'y' || choice == 'Y')
        printFortune();             // If the user chooses to see a fortune, call our recursive function
    else
        printf("Goodbye!\n");       // Otherwise, end the program
    return 0;
}