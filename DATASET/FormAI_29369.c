//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY 10
#define MAX_LENGTH 100

char* conspiracies[MAX_CONSPIRACY] = {
    "The government is hiding the cure for cancer to make more money from treatments.",
    "Aliens have infiltrated the government and are controlling our leaders.",
    "The moon landing was faked to win the Cold War.",
    "The Illuminati is controlling world events from behind the scenes.",
    "The government is using chemtrails to control the population.",
    "The Earth is flat and the government is covering it up.",
    "The 9/11 attacks were an inside job.",
    "The vaccine industry is creating diseases to sell more vaccines.",
    "The Bilderberg Group is deciding the fate of the world in secret meetings.",
    "The New World Order is planning to take over the world."
};

int main(void) {
    srand(time(NULL));

    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

    printf("Would you like to generate a conspiracy theory? (y/n) ");
    char answer = getchar();
    getchar(); // clear newline from input buffer

    while (answer == 'y') {
        int index = rand() % MAX_CONSPIRACY;
        char* conspiracy = conspiracies[index];

        printf("\n%s\n", conspiracy);

        int length = rand() % MAX_LENGTH + 1;
        printf("\nHere is some supposed evidence to support this theory:\n");
        for (int i = 0; i < length; i++) {
            printf("%c", rand() % 26 + 'a');
        }

        printf("\n\nWould you like to generate another conspiracy theory? (y/n) ");
        answer = getchar();
        getchar(); // clear newline from input buffer
    }

    printf("\nThanks for using the Random Conspiracy Theory Generator!\n");

    return 0;
}