//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables
    int num;
    char response;

    // Seed the random number generator
    srand(time(NULL));

    // Print initial message
    printf("Welcome to the Fortune Teller Program.\n");

    do {
        // Generate random number between 0 and 9
        num = rand() % 10;

        // Use switch statement to print fortune based on generated number
        switch(num) {
            case 0:
                printf("You will receive a promotion at work.\n");
                break;
            case 1:
                printf("Your financial situation will improve.\n");
                break;
            case 2:
                printf("You will meet someone special.\n");
                break;
            case 3:
                printf("Your health will improve.\n");
                break;
            case 4:
                printf("You will travel to an exotic location.\n");
                break;
            case 5:
                printf("You will have a long and happy life.\n");
                break;
            case 6:
                printf("You will achieve great success in your career.\n");
                break;
            case 7:
                printf("You will find inner peace and happiness.\n");
                break;
            case 8:
                printf("You will win a large sum of money.\n");
                break;
            case 9:
                printf("You will accomplish a great feat.\n");
                break;
        }

        // Ask user if they want another fortune
        printf("Would you like another fortune? (y/n) ");
        scanf(" %c", &response);

    } while (response == 'y' || response == 'Y');

    // Print closing message
    printf("Thank you for using the Fortune Teller Program.\n");

    return 0;
}