//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Automated Fortune Teller program!\n\n");

    // Seed the random number generator
    srand(time(NULL));

    // Array of fortune messages
    char* fortunes[5] = {
        "You will receive unexpected news today.",
        "Your hard work will pay off in the near future.",
        "A change of scenery is in your future.",
        "Be careful in your financial dealings, as troubles may arise.",
        "Love is in the cards for you."
    };

    // Ask the user for their name
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);

    // Generate a random number between 0 and 4
    int fortune_index = rand() % 5;

    // Display the fortune message
    printf("\nHello, %s. Your fortune for today is:\n%s\n", name, fortunes[fortune_index]);

    // Thank the user for using the program
    printf("\nThank you for using the Automated Fortune Teller program!\n");

    return 0;
}