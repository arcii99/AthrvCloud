//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    char* fortunes[] = {
        "You will find love on a sunny day.",
        "Money is coming your way.",
        "A new opportunity will arise soon.",
        "Your hard work will pay off in the end.",
        "Be careful not to trust too easily.",
        "A great adventure awaits you."
    };

    int numFortunes = sizeof(fortunes)/sizeof(fortunes[0]); // determine size of fortunes array

    printf("Welcome to the Automated Fortune Teller!\n\n");

    char response;
    do {
        printf("Enter any character to get your fortune: ");
        scanf(" %c", &response); // get user input

        int index = rand() % numFortunes; // generate random index
        printf("Your fortune is: %s\n\n", fortunes[index]);

        printf("Would you like to try again? (y/n): ");
        scanf(" %c", &response); // get user input
        printf("\n");
    } while (response == 'y' || response == 'Y');

    printf("Thank you for using the Automated Fortune Teller!\n");

    return 0;
}