//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the unique C Checksum Calculator!\n");
    printf("Please enter your name to begin: ");

    char name[50];
    scanf("%s", name);

    printf("Hi there, %s! Let's get started.\n", name);

    printf("Please enter the string you would like to calculate the checksum for: ");
    char input[100];
    scanf("%s", input);

    printf("Calculating checksum... ");
    int checksum = 0;
    for (int i = 0; i < strlen(input); i++) {
        checksum += i * input[i];
    }
    printf("Done!\n");
    printf("Your checksum is: %d\n", checksum);

    printf("Would you like to calculate another checksum? ");
    char response[5];
    scanf("%s", response);
    if (strcmp(response, "yes") == 0) {
        printf("Great! Let's start again.\n");
        main();
    } else {
        printf("Thanks for using the unique C Checksum Calculator. Goodbye!\n");
    }

    return 0;
}