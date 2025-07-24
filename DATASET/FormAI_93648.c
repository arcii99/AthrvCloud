//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: peaceful
#include <stdio.h>
#include <string.h>

// Function to convert text to Morse code
void textToMorse(char text[]) {
    char morse[36][6] = {
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
    
    int len = strlen(text);
    
    // Loop through each character of the text
    for (int i = 0; i < len; i++) {
        // Check if character is a whitespace
        if (text[i] == ' ') {
            printf(" / ");  // Add space symbol in morse code
        }
        else {
            // Convert character to uppercase
            char c = toupper(text[i]);
            
            // Check if character is a valid alphabet or number for Morse code
            if (c >= 'A' && c <= 'Z') {
                printf("%s ", morse[c - 'A']);  // Add Morse code for alphabet
            }
            else if (c >= '0' && c <= '9') {
                printf("%s ", morse[c - '0' + 26]);  // Add Morse code for number
            }
            else {
                printf("[INVALID CHARACTER]");
            }
        }
    }
}

int main() {
    char text[100];
    
    printf("Enter text to convert to Morse code:\n");
    fgets(text, sizeof(text), stdin);
    strtok(text, "\n");  // Remove newline character
    
    printf("Morse code: ");
    textToMorse(text);
    
    return 0;
}