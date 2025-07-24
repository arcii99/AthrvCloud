//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Set seed of random number generator

    // Array of possible fortunes
    char fortunes[10][50] = {"You will find success in love.",
                             "Money will come your way.",
                             "A new job opportunity will arise.",
                             "Travel is in your future.",
                             "You will meet a new friend.",
                             "A loved one will bring you joy.",
                             "Good news is coming your way.",
                             "An unexpected event will lead to success.",
                             "You will conquer your fears.",
                             "A new adventure is on the horizon."};

    int random_num = rand() % 10; // Generate a random number between 0-9
    char response;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Would you like to know your fortune? (y/n) ");
    scanf("%c", &response);

    // If user responds with 'y', display a randomly generated fortune
    if(response == 'y' || response == 'Y') {
        printf("\nYour fortune is: %s", fortunes[random_num]);
    } 
    // If user responds with 'n', exit the program
    else {
        printf("\nGoodbye!");
        return 0;
    }

    return 0;
}