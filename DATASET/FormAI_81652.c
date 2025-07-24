//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complex
#include <stdio.h>
#include <string.h>

// Function to convert text to Morse code
void textToMorse(char* text) {
    int i, j;               // Loop variables
    char morse[36][6] = {   // Array to store Morse code equivalents for each letter and number
        {'.','-','\0'},     // A
        {'-','.','.','.', '\0'},     // B
        {'-','.','-','.', '\0'},     // C
        {'-','.','.', '\0'},         // D
        {'.','\0'},         // E
        {'.','.','-','.', '\0'},     // F
        {'-','-','.', '\0'},         // G
        {'.','.','.','.', '\0'},     // H
        {'.','.', '\0'},             // I
        {'.','-','-','-', '\0'},     // J
        {'-','.','-','\0'},          // K
        {'.','-','.','.', '\0'},     // L
        {'-','-','\0'},              // M
        {'-','.','\0'},              // N
        {'-','-','-', '\0'},         // O
        {'.','-','-','.', '\0'},     // P
        {'-','-','.','-','\0'},      // Q
        {'.','-','.', '\0'},         // R
        {'.','.','.', '\0'},         // S
        {'-','\0'},                  // T
        {'.','.','-','\0'},          // U
        {'.','.','.','-', '\0'},     // V
        {'.','-','-','\0'},          // W
        {'-','.','.','-', '\0'},     // X
        {'-','.','-','-', '\0'},     // Y
        {'-','-','.','.', '\0'},     // Z
        {'.','-','-','-', '-','\0'}, // 0
        {'.','.','-','-','-', '\0'}, // 1
        {'.','.','.','-','-', '\0'}, // 2
        {'.','.','.','.','-', '\0'}, // 3
        {'.','.','.','.','.', '\0'}, // 4
        {'-','.','.','.','.', '\0'}, // 5
        {'-','-','.','.','.', '\0'}, // 6
        {'-','-','-','.','.', '\0'}, // 7
        {'-','-','-','-','.', '\0'}, // 8
        {'-','-','-','-','-', '\0'}  // 9
    };

    // Loop through each character in the text
    for (i = 0; i < strlen(text); i++) {
        char ch = text[i];
        int index = -1;     // Index of the Morse code equivalent for the current character

        // Check if the character is a letter
        if (ch >= 'A' && ch <= 'Z') {
            index = ch - 'A';   // Calculate the index using the ASCII values
        }
        // Check if the character is a number
        else if (ch >= '0' && ch <= '9') {
            index = ch - '0' + 26;  // Calculate the index using the ASCII values
        }

        // If the character corresponds to an index in the morse array
        if (index >= 0 && index <= 35) {
            printf("%s ", morse[index]);    // Print the Morse code equivalent
        }
    }

    printf("\n");  // End the line
}

int main() {
    char text[100];

    printf("Enter text to convert to Morse code:\n");
    fgets(text, 100, stdin);    // Read the text from the user

    textToMorse(text);  // Convert the text to Morse code

    return 0;   // End the program
}