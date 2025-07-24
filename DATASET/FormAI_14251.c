//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    char userInput[50];
    printf("Good morrow, traveler! How may I assist thee?\n");
    printf("Please enter thy inquiry: ");

    fgets(userInput, 50, stdin);
    userInput[strcspn(userInput, "\n")] = '\0'; // Removes trailing newline character

    // Loop through the user input and replace any non-alphanumeric characters with spaces
    for (int i = 0; i < strlen(userInput); i++) {
        if (!isalnum(userInput[i])) {
            userInput[i] = ' ';
        }
    }

    printf("I shall relay thy inquiry: %s\n", userInput);
    printf("May thy journey be prosperous!\n");
    return 0;
}