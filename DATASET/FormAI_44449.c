//FormAI DATASET v1.0 Category: Educational ; Style: curious
#include <stdio.h>
#include <string.h>

// Let's create a program that converts a given input string into its corresponding ASCII code 

int main()
{
    char input_str[100]; // Input string with maximum of 100 characters
    printf("Hi there! I am a curious C program that converts input string into ASCII code.\n");

    // Step 1: Get user input and verify its length
    printf("Please enter your input string: ");
    fgets(input_str, 100, stdin); // Using fgets to prevent buffer overflow
    if (strlen(input_str) == 1) {
        printf("You did not enter anything. I need an input string to work my magic!\n");
        return 0;
    } else if (strlen(input_str) == 100 && input_str[99] != '\n') {
        printf("The input string exceeded my limit of 100 characters. Please try again!\n");
        return 0;
    } else {
        printf("Your input string is: \"%s\"\n", input_str);
    }

    // Step 2: Convert the input string to ASCII code
    printf("Your input string in ASCII code is:\n");
    for (int i = 0; i < strlen(input_str); i++) {
        printf("%d ", input_str[i]);
    }
    printf("\n");

    printf("Curious to know more about ASCII code? I can tell you that it ranges from 0 to 127, and each integer corresponds to a character.\n");
    printf("You can verify this by consulting the ASCII table. Cool, right? Let me know if you want to know anything else about ASCII code!");
    return 0;
}