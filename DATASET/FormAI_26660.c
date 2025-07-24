//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initializes random number generator with current time
    int alien_odds = rand() % 101; // generates a random number between 0-100

    printf("Welcome to the Alien Invasion Probability Calculator\n");
    printf("The chances of an alien invasion today is %d%%\n", alien_odds);

    if (alien_odds <= 25) {
        printf("Don't worry, the chances of an alien invasion are low. Enjoy your day!\n");
    } else if (alien_odds <= 50) {
        printf("There is a moderate chance of an alien invasion. Keep an eye out!\n");
    } else if (alien_odds <= 75) {
        printf("We recommend being cautious, as the chances of an alien invasion are quite high.\n");
    } else {
        printf("An alien invasion is imminent. Take cover and stay safe!\n");
    }

    printf("Would you like to run the calculator again? (y/n): ");
    char choice;
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        main(); // restarts the program
    } else {
        printf("Thank you for using the Alien Invasion Probability Calculator. Stay safe!\n");
    }

    return 0;
}