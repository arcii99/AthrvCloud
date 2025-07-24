//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    printf("Welcome to the Automated Fortune Teller. Let's see what the future holds for you...\n");

    //initialize random seed
    srand(time(NULL));

    //declare an array of fortunes
    char fortunes[10][100] = {"You will find love in the most unexpected place.",
                              "Your hard work will pay off in the near future.",
                              "You will meet someone who will change your life.",
                              "A great adventure awaits you.",
                              "You will find happiness wherever you go.",
                              "Your creativity will bring you success.",
                              "Luck is on your side today.",
                              "You will receive a pleasant surprise.",
                              "Your perseverance will be rewarded.",
                              "An important decision lies ahead."};

    //generate a random index number
    int r = rand() % 10;

    //print out the fortune
    printf("Your fortune: %s\n", fortunes[r]);

    //ask if the user wants to play again
    char answer[10];
    printf("Do you want to play again? (y/n)\n");
    scanf("%s", answer);

    //if the answer is yes, loop back to the beginning of the program
    while (strcmp(answer, "y") == 0)
    {
        printf("Let's see what the future holds for you...\n");
        r = rand() % 10;
        printf("Your fortune: %s\n", fortunes[r]);
        printf("Do you want to play again? (y/n)\n");
        scanf("%s", answer);
    }
    printf("Thank you for playing!\n");
    return 0;
}