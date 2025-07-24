//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int generateRandomNumber(int upperBound) {
    srand(time(0));
    int number = rand() % upperBound;
    return number;
}

int main() {
    // Welcome Message
    printf("Welcome to the Automated Fortune Teller!\n");

    // Prompt the user to input their name
    char name[20];
    printf("What's your name? ");
    scanf("%s", name);

    // Display the name input by the user
    printf("Hello, %s!\n\n", name);

    // Declare an array of fortunes
    char* fortunes[5] = {
        "Today is your lucky day!",
        "Good things come to those who wait.",
        "You will meet your true love soon.",
        "Your dreams will come true!",
        "A new opportunity is on the horizon."
    };

    // Generate a random number to select a fortune
    int upperBound = 5;
    int index = generateRandomNumber(upperBound);

    // Display the selected fortune
    printf("Your fortune of the day is:\n");
    printf("%s\n", fortunes[index]);

    // Exit message
    printf("Thank you for using the Automated Fortune Teller!\n");

    return 0;
}