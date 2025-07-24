//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char question[100]; // Create an array to store the user's question
    char response[4][50] = { // Create a multidimensional array to store the possible responses
        "It is certain.",
        "Reply hazy, try again.",
        "Don't count on it.",
        "Outlook good."
    };

    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Ask me a yes or no question.\n");
    scanf("%[^\n]%*c", question);

    srand(time(NULL)); // Set the seed value for the random number generator

    printf("\nThinking...\n\n");

    int randomIndex = rand() % 4; // Generate a random number between 0 and 3

    printf("Question: %s\n", question);
    printf("Answer: %s", response[randomIndex]);

    return 0;
}