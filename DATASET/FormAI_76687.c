//FormAI DATASET v1.0 Category: Funny ; Style: funny
#include <stdio.h>

int main() {
    int love = 0;
    
    printf("Welcome to the Love Calculator!\n");
    printf("Enter how much you love C programming: ");
    scanf("%d", &love);
    
    printf("Calculating love...");
    for(int i = 0; i < 5; i++) {
        printf(".");
    }

    if(love < 50) {
        printf("\nSorry, not much love here...maybe try Java instead?\n");
    }
    else if(love >= 50 && love < 75) {
        printf("\nThere's potential here, keep on coding!\n");
    }
    else if(love >= 75 && love < 90) {
        printf("\nWow, you really love C programming!\n");
    }
    else {
        printf("\nCongratulations, you have found your one true love!\n");
    }
    
    printf("Would you like to test another language? (Y/N) ");
    char choice;
    scanf(" %c", &choice);
    
    if(choice == 'Y' || choice == 'y') {
        printf("Sorry, this program only works for C lovers. Do you want to try again? (Y/N) ");
        scanf(" %c", &choice);
        
        if(choice == 'Y' || choice == 'y') {
            printf("Okay, let's go again!\n");
            main(); // Recursion...infinite love!
        }
    }
    
    printf("Thanks for using the Love Calculator. Happy coding!\n");
    return 0;
}