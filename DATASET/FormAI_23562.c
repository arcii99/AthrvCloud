//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char playAgain = 'y';
    printf("Welcome to the Peaceful Fortune Teller!\n\n");

    while (playAgain == 'y') {
        // Get the user's name
        char name[20];
        printf("What is your name?\n");
        scanf("%s", name);

        // Generate a random fortune
        srand(time(NULL));
        int fortuneNum = rand() % 5;
        char *fortune;

        switch(fortuneNum) {
            case 0:
                fortune = "You will find inner peace and joy today.";
                break;
            case 1:
                fortune = "Good fortune will come your way in the near future.";
                break;
            case 2:
                fortune = "You will be successful in all of your endeavors.";
                break;
            case 3:
                fortune = "You will meet someone special today.";
                break;
            case 4:
                fortune = "Today will be a lucky day for you.";
                break;
        }

        // Display the user's fortune
        printf("\n%s, your fortune for today is:\n%s\n", name, fortune);

        // Ask if the user wants to play again
        printf("\nDo you want another fortune? (y/n)\n");
        scanf(" %c", &playAgain);
    }

    printf("Thanks for playing!\n");
    return 0;
}