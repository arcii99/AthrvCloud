//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));
    
    // Declare variables
    int randNum;
    char question[50];
    
    // Print welcome message
    printf("Welcome to Automated Fortune Teller! Ask me any yes or no question.\n");
    
    // Get user's question
    printf("Question: ");
    fgets(question, 50, stdin);
    
    // Generate a random number between 0 and 9
    randNum = rand() % 10;
    
    // Generate random answer
    switch(randNum)
    {
        case 0: printf("It is certain.\n"); break;
        case 1: printf("It is decidedly so.\n"); break;
        case 2: printf("Without a doubt.\n"); break;
        case 3: printf("Yes - definitely.\n"); break;
        case 4: printf("You may rely on it.\n"); break;
        case 5: printf("As I see it, yes.\n"); break;
        case 6: printf("Most likely.\n"); break;
        case 7: printf("Outlook good.\n"); break;
        case 8: printf("Yes.\n"); break;
        case 9: printf("Signs point to yes.\n"); break;
    }
    
    return 0;
}