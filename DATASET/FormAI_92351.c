//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define fortune message arrays */
char *luckyNumber[] = {"7", "13", "22", "45", "66"};
char *luckyColor[] = {"blue", "green", "red", "yellow", "purple"};
char *luckyPhrase[] = {
    "Good things come to those who wait.",
    "The early bird catches the worm.",
    "Fortune favors the brave.",
    "Everything happens for a reason.",
    "Patience is a virtue."
};

/* Function to get a random index for the fortune message arrays */
int getRandomIndex() {
    srand(time(NULL));
    return rand() % 5;
}

/* Main function */
int main() {
    /* Print welcome message */
    printf("Welcome to the Automated Fortune Teller Program!\n\n");

    /* Ask for user's name */
    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\n");

    /* Print user's personalized fortune message */
    printf("%s, here is your fortune:\n\n", name);
    printf("Lucky number: %s\n", luckyNumber[getRandomIndex()]);
    printf("Lucky color: %s\n", luckyColor[getRandomIndex()]);
    printf("Lucky phrase: \"%s\"\n", luckyPhrase[getRandomIndex()]);

    /* Print closing message */
    printf("\nThank you for trying the Automated Fortune Teller Program! Good luck!\n");

    return 0;
}