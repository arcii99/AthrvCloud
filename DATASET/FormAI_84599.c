//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    char output[1000];
    char morseTable[36][8] = {
        {".-"},     // A
        {"-..."},   // B
        {"-.-."},   // C
        {"-.."},    // D
        {"."},      // E
        {"..-."},   // F
        {"--."},    // G
        {"...."},   // H
        {".."},     // I
        {".---"},   // J
        {"-.-"},    // K
        {".-.."},   // L
        {"--"},     // M
        {"-."},     // N
        {"---"},    // O
        {".--."},   // P
        {"--.-"},   // Q
        {".-."},    // R
        {"..."},    // S
        {"-"},      // T
        {"..-"},    // U
        {"...-"},   // V
        {".--"},    // W
        {"-..-"},   // X
        {"-.--"},   // Y
        {"--.."},   // Z
        {"-----"},  // 0
        {".----"},  // 1
        {"..---"},  // 2
        {"...--"},  // 3
        {"....-"},  // 4
        {"....."},  // 5
        {"-...."},  // 6
        {"--..."},  // 7
        {"---.."},  // 8
        {"----."}   // 9
    };

    printf("Enter text to convert to Morse code:\n");
    fgets(input, sizeof(input), stdin);
    strtok(input, "\n"); // remove the newline character

    // convert to uppercase for simplicity
    for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // paranoid checks
    if (strlen(input) > 80) {
        printf("WARNING: Input is too long! Truncating to 80 characters\n");
        input[80] = '\0'; // truncate the string
    }

    int outputIndex = 0;
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (!isalnum(c)) {
            // paranoid checks
            if (isspace(c)) {
                printf("WARNING: Input contains spaces! Removing\n");
                continue;
            } else {
                printf("WARNING: Input contains non-alphanumeric characters! Removing\n");
                continue;
            }
        }

        int morseIndex = -1;
        if (isdigit(c)) {
            morseIndex = c - '0' + 25; // map to table index
        } else {
            morseIndex = c - 'A';
        }

        if (morseIndex < 0 || morseIndex > 35) {
            printf("WARNING: Index out of range! Skipping character\n");
            continue;
        }

        // paranoid checks
        if (outputIndex > 950) {
            printf("WARNING: Output is getting too long! Truncating\n");
            break; // stop outputting
        }

        strcat(output, morseTable[morseIndex]); // append Morse code to output
        strcat(output, " "); // add space between characters
        outputIndex += strlen(morseTable[morseIndex]) + 1; // update output index
    }

    printf("Morse code:\n%s\n", output);
    return 0;
}