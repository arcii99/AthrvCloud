//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("*******************************************\n");
    printf("       Welcome to the Automated Fortune Teller\n");
    printf("*******************************************\n");
    printf("\n");

    // Array of possible fortunes
    char fortunes[10][100] = {
        "You will find true love in the near future. ",
        "Great things are coming your way soon. ",
        "A new career opportunity will present itself to you. ",
        "Take that chance, it will be worth it. ",
        "You will receive a surprise gift from someone close to you. ",
        "Travel is in your future, pack your bags. ",
        "There is a large sum of money headed your way. ",
        "A long held dream will soon come true. ",
        "Your current difficulties will pass, stay strong. ",
        "Life is full of obstacles, but you will overcome them. "};

    char question[100];
    printf("What is your burning question? (press 'q' to quit)\n");
    fgets(question, 100, stdin);

    // Determine if the user wants to play or quit
    while(question[0] != 'q')
    {
        // Generate a random number between 0 and 9
        srand(time(NULL));
        int fortune_index = rand() % 10;

        // Print the fortune
        printf("\nYour fortune is: %s\n", fortunes[fortune_index]);

        printf("\nWhat is your burning question? (press 'q' to quit)\n");
        fgets(question, 100, stdin);
    }

    printf("\nGoodbye! Thanks for playing.\n");
    return 0;
}