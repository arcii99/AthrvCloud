//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcomeMessage() {
    printf("\n\n**********************************************\n");
    printf("\tWelcome to Automated Fortune Teller!\n");
    printf("**********************************************\n");
}

void generateFortune() {
    printf("\n\nGenerating your fortune...\n\n");
    sleep(2); // Wait for 2 seconds for the suspense
    srand(time(0));
    int randomNumber = rand() % 5; // Generates random number between 0 to 4

    // Array of fortunes
    char *fortunes[] = {
        "You will soon receive an unexpected gift.",
        "A great opportunity is on its way to you.",
        "Happiness is waiting for you ahead.",
        "Your past will catch up with you, but it will bring good memories.",
        "The future is bright for you, keep moving forward."
    };

    printf("Your fortune is: %s\n", fortunes[randomNumber]);
}

int main() {
    char response;
    welcomeMessage(); // Greet the user
    do {
        printf("Do you want to know your fortune? (Y/N): ");
        scanf(" %c", &response);
        if(response == 'Y' || response == 'y') {
            generateFortune(); // Generate random fortune
        }
    } while(response != 'N' && response != 'n');

    printf("\nThank you for using Automated Fortune Teller!\n");
    return 0;
}