//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get a fortune based on random number generated
void getFortune() {
    int randNum = rand() % 5;
    switch(randNum) {
        case 0:
            printf("Good things are coming your way.\n");
            break;
        case 1:
            printf("You will face challenges, but they will make you stronger.\n");
            break;
        case 2:
            printf("You will find love in unexpected places.\n");
            break;
        case 3:
            printf("Your hard work will pay off soon.\n");
            break;
        case 4:
            printf("Be careful of those seeking to deceive you.\n");
            break;
    }
}

int main() {
    time_t t;
    srand((unsigned) time(&t)); // Seed random number generator

    // Greet the user and get their name
    char name[20];
    printf("Hello! I am your automated fortune teller. What is your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s! Are you ready to receive your fortune? (Y/N)\n", name);

    // Continue looping to get fortunes until user says no
    char input;
    do {
        scanf(" %c", &input); // Get user input for continue or quit
        if(input == 'Y' || input == 'y') {
            getFortune();
            printf("Do you want to receive another fortune, %s? (Y/N)\n", name);
        }
    } while(input != 'N' && input != 'n');

    printf("Thanks for visiting! Goodbye, %s.\n", name);
    return 0;
}