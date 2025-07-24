//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // Declare variables to store user's input and fortune
    char name[20], question[50], fortune[100];
    // Declare variables to store random numbers
    int num1, num2, num3;

    // Get user's name
    printf("Welcome to the Automated Fortune Teller! What is your name?\n");
    scanf("%s", name);

    printf("Greetings, %s! Please ask a yes or no question.\n", name);
    scanf("%s", question);

    // Generate random numbers
    srand(time(NULL));
    num1 = rand() % 10 + 1;
    num2 = rand() % 10 + 1;
    num3 = rand() % 10 + 1;

    // Check if all random numbers are the same
    if (num1 == num2 && num2 == num3) {
        strcpy(fortune, "My dear Romeo, fate is indeed on your side. Your wishes will come true!");
    }
    // Check if only two random numbers are the same
    else if (num1 == num2 || num1 == num3 || num2 == num3) {
        strcpy(fortune, "Alas, my dear Romeo, the future is uncertain. Your destiny depends on your own actions.");
    }
    // If all random numbers are different
    else {
        strcpy(fortune, "Oh Fortune! Why must you be so fickle? The answer is unclear, my dear Romeo.");
    }

    // Print the fortune
    printf("And the answer is...\n");
    printf("%s\n", fortune);

    return 0;
}