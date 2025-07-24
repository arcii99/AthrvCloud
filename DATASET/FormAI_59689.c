//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Set up random number generator
    srand(time(NULL));

    // Initialize array of fortunes
    char fortunes[5][100] = {
        "You will meet a tall, dark stranger",
        "Good things come to those who wait",
        "Your hard work will pay off",
        "Beware of unexpected surprises",
        "Happiness is just around the corner"
    };

    // Print welcome message
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("---------------------------------------\n\n");

    // Ask user for their name
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);
    printf("\n");

    // Generate a random number between 0 and 4
    int index = rand() % 5;

    // Print the fortune
    printf("Hello, %s! Your fortune today is:\n\n", name);
    printf("%s\n", fortunes[index]);

    // Print closing message
    printf("\nThank you for using the Automated Fortune Teller!\n");
    printf("-----------------------------------------------\n");

    return 0;
}