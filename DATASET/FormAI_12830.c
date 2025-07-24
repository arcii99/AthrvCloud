//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdio.h>
#include <string.h>

const char *morse_codes[] = {
    "",
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

int main()
{
    char input[1000];
    printf("Enter text to convert to Morse code (A-Z, 0-9, space): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // remove trailing newline

    // convert to all uppercase for simplicity
    for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // iterate through input and convert to Morse code
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            printf("%s ", morse_codes[input[i] - 'A' + 1]);
        } else if (input[i] >= '0' && input[i] <= '9') {
            printf("%s ", morse_codes[input[i] - '0' + 27]);
        } else if (input[i] == ' ') {
            printf(" ");
        } else {
            printf("ERROR: Invalid character '%c'\n", input[i]);
            return 1;
        }
    }

    printf("\n");
    return 0;
}