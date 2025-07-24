//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller by Sherlock Holmes.\n");
    printf("Please ask a question and I will reveal your fortune.\n");
    printf("Enter 'q' to quit.\n\n");

    char question[100];

    while (1) {
        printf("What would you like to know? ");
        fgets(question, sizeof(question), stdin);

        if (question[0] == 'q') {
            printf("\nGoodbye!\n");
            break;
        }

        printf("\nHmmm, let me think...\n\n");
        int fortuneNum = rand() % 5; // Random number from 0-4

        switch (fortuneNum) {
            case 0:
                printf("I see danger ahead. Tread carefully.\n\n");
                break;
            case 1:
                printf("The stars show a positive outcome for you.\n\n");
                break;
            case 2:
                printf("Your troubles will soon come to an end.\n\n");
                break;
            case 3:
                printf("I sense a new opportunity will present itself to you.\n\n");
                break;
            case 4:
                printf("Be cautious with your investments. The future is uncertain.\n\n");
                break;
            default:
                printf("Oops, something went wrong. Please try again.\n\n");
                break;
        }
    }

    return 0;
}