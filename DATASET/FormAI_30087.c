//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Global variables 
int fortuneNum;
char name[20];
char partner[20];

int main() 
{
    // User inputs 
    printf("Welcome to the Automated Fortune Teller. Please enter your name: ");
    scanf("%s", name);
    printf("And who is your romantic partner? ");
    scanf("%s", partner);
    
    // Set seed for random number generator 
    srand(time(NULL));
    
    // Generate random number from 1 to 5 
    fortuneNum = (rand() % 5) + 1;
    
    // Output fortunes based on chosen number 
    switch(fortuneNum) {
        case 1:
            printf("\n%s and %s, your love is written in the stars. Keep your heart and mind open to all the joy that the universe has to offer.\n", name, partner);
            break;
        case 2:
            printf("\n%s and %s, you were meant to be together. The winds of fate have brought you both together for a reason, so cherish each other always.\n", name, partner);
            break;
        case 3:
            printf("\n%s and %s, your love is like a rose in bloom. As long as you both nurture it with care and devotion, it will continue to blossom and flourish.\n", name, partner);
            break;
        case 4:
            printf("\n%s and %s, your love may face challenges, but together you can conquer them all. Trust in each other and your love will continue to grow stronger.\n", name, partner);
            break;
        case 5:
            printf("\n%s and %s, you have a deep, eternal love. Even in difficult times, your love will never falter. Keep the flame burning bright and let it guide you both through life.\n", name, partner);
            break;
    }
    
    return 0;
}