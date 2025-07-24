//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random seed
    srand(time(NULL));
    
    // Ask user to input their question
    printf("Ask a yes or no question: ");
    char question[100];
    fgets(question, 100, stdin);
    
    // Generate a random number between 1 and 10
    int randNum = rand() % 10 + 1;
    
    // Implement shape shifting
    if (randNum < 4) {
        printf("The answer is YES.\n");
    } else if (randNum >= 4 && randNum < 7) {
        printf("The answer is MAYBE.\n");
    } else if (randNum >= 7 && randNum < 9) {
        printf("The answer is UNLIKELY.\n");
    } else {
        printf("The answer is NO.\n");
    }
    
    // Randomly select a fortune
    int randFortune = rand() % 6 + 1;
    switch (randFortune) {
        case 1:
            printf("Your future is bright. Keep working towards your goals!\n");
            break;
        case 2:
            printf("You may encounter some obstacles in the near future, but you have the strength to overcome them.\n");
            break;
        case 3:
            printf("It's time to take a risk. Trust in yourself and go for it.\n");
            break;
        case 4:
            printf("You will soon meet someone who will change your life for the better.\n");
            break;
        case 5:
            printf("You have a hidden talent that you should explore. Don't be afraid to take a chance.\n");
            break;
        case 6:
            printf("Your past mistakes do not define you. Learn from them and move forward.\n");
            break;
    }
    
    return 0;
}