//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayHeader();
void displayFortune();
int rollDice(int, int);
void endProgram();

int main()
{
    srand(time(NULL)); // Seed for random number generator
    
    // Display program header
    displayHeader();
    
    // Display fortune
    displayFortune();
    
    // End program
    endProgram();
    
    return 0;
}

// Function to display program header
void displayHeader()
{
    printf("=============================================\n");
    printf("|         Welcome to the Fortune Teller      |\n");
    printf("|             Your destiny awaits!           |\n");
    printf("=============================================\n\n");
}

// Function to display fortune
void displayFortune()
{
    char fortunes[5][100] = {"Your future is bright and full of joy.", 
                             "You will soon come into a great deal of wealth.", 
                             "Beware of those close to you, for they may betray you.", 
                             "The path ahead is riddled with challenges, but you will overcome them.", 
                             "Your true love is closer than you think."};
    
    int fortuneIndex = rollDice(1, 5) - 1; // Generate random index for fortune
    
    printf("Your fortune:\n");
    printf("------------------------------\n\n");
    printf("%s\n\n", fortunes[fortuneIndex]);
}

// Function to roll dice with given range
int rollDice(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Function to end program
void endProgram()
{
    printf("\nThank you for consulting the Fortune Teller.\n");
}