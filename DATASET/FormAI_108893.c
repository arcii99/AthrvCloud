//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // set up a seed for random number generation
    srand(time(NULL));
    
    // welcome message 
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("---------------------------------------\n\n");
    
    // prompt the user for their name
    printf("What is your name? ");
    char name[50];
    scanf("%s", name);
    
    // generate a random number between 1 and 5
    int random_number = rand() % 5 + 1;
    
    // display the fortune based on the random number
    switch(random_number) {
        case 1:
            printf("\n%s, you will have a prosperous future!\n", name);
            break;
        case 2:
            printf("\n%s, beware of bad luck today!\n", name);
            break;
        case 3:
            printf("\n%s, it is a good day to take risks!\n", name);
            break;
        case 4:
            printf("\n%s, you will meet a new friend today!\n", name);
            break;
        case 5:
            printf("\n%s, let go of the past and focus on the present!\n", name);
            break;
        default:
            printf("\n%s, an error has occurred! Please try again.\n", name);
            break;
    }
    
    // goodbye message
    printf("\nThank you for using the Automated Fortune Teller!\n");
    printf("----------------------------------------------\n");
    
    return 0;
}