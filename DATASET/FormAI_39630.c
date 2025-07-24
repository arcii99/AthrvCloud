//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_FORTUNES 6
#define FORTUNE_LENGTH 100

char fortunes[NUM_FORTUNES][FORTUNE_LENGTH] = {
    "Good things come to those who wait.",
    "The best is yet to come.",
    "You will find success in unexpected places.",
    "Take chances and make mistakes.",
    "The journey is as important as the destination.",
    "Your kindness will lead to great things."
};

int main() {
    char question[100];
    char response[4];
    char *fortune;
    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller. Ask me a yes or no question!\n");

    do {
        printf("Question: ");
        fgets(question, 100, stdin);

        fortune = fortunes[rand() % NUM_FORTUNES];

        printf("Fortune: %s\n", fortune);

        printf("Do you have another question? (y/n) ");
        fgets(response, 4, stdin);
    } while (response[0] == 'y');

    printf("Thank you for using the Automated Fortune Teller!\n");

    return 0;
}