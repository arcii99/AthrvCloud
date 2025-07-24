//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
    // Welcome Message
    printf("Welcome to the Text to ASCII Art generator!\n");
    printf("Enter your line of text below:\n");

    // Take Input From User
    char input[100];
    fgets(input, 100, stdin);

    // Remove New Line Character
    input[strcspn(input, "\n")] = 0;

    // Find Length of Input String
    int length = strlen(input);

    // ASCII Art
    for (int i = 0; i < length; i++) {
       if (input[i] == ' ') {
           printf("     ");
       } else {
           printf("  _  ");
       }
    }
    printf("\n");

    for (int i = 0; i < length; i++) {
        if (input[i] == ' ' || input[i] == '\0') {
            printf(" | | ");
        } else {
            printf("/ %c \\ ", input[i]);
        }
    }
    printf("\n");

    for (int i = 0; i < length; i++) {
        if (input[i] == ' ') {
            printf("(_) ");
        } else {
            printf("\\_%c_/", input[i]);
        }
    }
    printf("\n\n");

    // Final Message
    printf("Your ASCII Art has been generated. Thank you for using this program!\n");

    return 0;
}