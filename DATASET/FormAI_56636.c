//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: lively
#include <stdio.h>

int main() {
    char input[100];
    printf("Enter the text you want to convert to ASCII art:\n");
    scanf("%s", input);

    // get the length of the input string
    int length = 0;
    while (input[length] != '\0') {
        length++;
    }

    // loop through each character and print the corresponding ASCII art
    for (int i = 0; i < length; i++) {
        char c = input[i];

        // check if the character is a letter or a number
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            printf("    _______\n");
            printf("  /         \\\n");
            printf(" /  /~~~~~\\  \\\n");
            printf(" |  |     |  |\n");
            printf(" |  |  %c  |  |\n", c);
            printf(" |  |     |  |\n");
            printf(" |  |  /  \\  |\n");
            printf(" \\\\  \\/~\\/  /\n");
            printf("  \\\\_______/\n");
            printf("     V\n");
        }
        // check if the character is a space
        else if (c == ' ') {
            printf("\n\n\n\n\n\n\n\n");
        }
        // if the character is not a letter, number, or space, just ignore it
        else {
            continue;
        }
    }

    return 0;
}