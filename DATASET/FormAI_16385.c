//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Setup the variables
    char name[50];
    int age;
    int questionNumber;
    int randomNumber;

    // Get the user's name and age
    printf("Welcome to the automated fortune teller.\n");
    printf("What is your name? ");
    scanf("%s", name);

    printf("Hello %s, how old are you? ", name);
    scanf("%d", &age);

    // Randomly generate a number between 1 and 20
    srand(time(NULL));
    randomNumber = rand() % 20 + 1;

    // Ask the user to pick a number between 1 and 20
    printf("\nPlease pick a number between 1 and 20: ");
    scanf("%d", &questionNumber);

    // Compare the user's number to the randomly generated number
    if (questionNumber > randomNumber) {
        printf("\nGood news %s, the future is looking bright for you.\n", name);
    }
    else if (questionNumber < randomNumber) {
        printf("\nSorry %s, the future might not be as bright as you hoped for.\n", name);
    }
    else {
        printf("\nHmm, it's hard to tell what the future holds for you right now, %s.\n", name);
    }

    return 0;
}