//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: protected
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    srand(time(NULL)); // initialize random seed

    char fortunes[10][100] = {"You will find love soon.", "Luck is on your side today!", 
                              "A surprise awaits you.", "Good news is coming your way.", 
                              "Your dreams will become a reality.", "You will achieve great things.",
                              "Your future is looking bright.", "A long lost friend will contact you soon.",
                              "A new opportunity is coming your way.", "Great things are in store for you."};

    int random_num = rand() % 10; // generate a random number between 0 and 9

    printf("Welcome to the Automated Fortune Teller!\n\n");

    // ask the user if they want to receive their fortune
    printf("Do you want to receive your fortune? (y/n) ");
    char input;
    scanf("%c", &input);

    if (input == 'y') {

        printf("\nHere is your fortune: %s\n", fortunes[random_num]);

    } else if (input == 'n') {

        printf("\nOk, maybe next time.\n");

    } else {
        // handle invalid input
        printf("\nSorry, I did not understand your input. Please try again.\n");
    }

    return 0;
}