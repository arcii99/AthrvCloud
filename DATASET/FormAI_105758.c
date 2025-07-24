//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    // Declare variables
    char* fortunes[] = {"You will have a great day!", "Good things come to those who wait.", "The future is looking bright.", "You should trust your instincts.",
                        "Be bold in your actions and decisions.", "Take a break and relax.", "There is a great opportunity coming your way.", "You will find success in your endeavors."};
    int num_fortunes = sizeof(fortunes) / sizeof(char*);
    int rand_num;
    char user_input;

    // Seed the random number generator
    srand(time(NULL));

    // Print welcome message
    printf("Welcome to the Automated Fortune Teller program!\n");
    printf("Would you like to receive a fortune? (y/n): ");
    scanf(" %c", &user_input);

    // Loop until user doesn't want a fortune anymore
    while (user_input == 'y' || user_input == 'Y') {
        // Generate random fortune
        rand_num = rand() % num_fortunes;
        printf("Fortune: %s\n", fortunes[rand_num]);

        // Ask if user wants another fortune
        printf("Would you like to receive another fortune? (y/n): ");
        scanf(" %c", &user_input);
    }

    // Print goodbye message and exit
    printf("Thank you for using the Automated Fortune Teller program!\n");
    return 0;
}