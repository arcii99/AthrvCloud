//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DOT "."
#define DASH "-"
#define SEPARATOR " "
#define MAX_BUF_LEN 256

// Morse code struct
typedef struct Morse {
    char character; 
    char *code;
} Morse;

// Morse code array
Morse morse_code[] = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {'.', ".-.-.-"},
    {',', "--..--"},
    {'?', "..--.."},
    {'\'', ".----."},
    {'!', "-.-.--"},
    {'/', "-..-."},
    {'(', "-.--."},
    {')', "-.--.-"},
    {'&', ".-..."},
    {':', "---..."},
    {';', "-.-.-."},
    {'=', "-...-"},
    {'+', ".-.-."},
    {'-', "-....-"},
    {'_', "..--.-"},
    {'\"', ".-..-."},
    {'$', "...-..-"},
    {'@', ".--.-."},
    {' ', "/"}
};

// Function to convert text to Morse code
void text_to_morse(char text[], char morse[]) {
    int text_len = strlen(text);
    int morse_len = 0;

    for(int i=0; i<text_len; i++) {
        char c = toupper(text[i]);

        if(c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c == ' ' || c == '.' || c == ',' || c == '?' || c == '\'' || c == '!' || c == '/' || c == '(' || c == ')' || c == '&' || c == ':' || c == ';' || c == '=' || c == '+' || c == '-' || c == '_' || c == '\"' || c == '$' || c == '@') {
            // Find Morse code for character
            for(int j=0; j<sizeof(morse_code)/sizeof(morse_code[0]); j++) {
                if(morse_code[j].character == c) {
                    strcat(morse, morse_code[j].code);
                    strcat(morse, SEPARATOR);
                    morse_len += strlen(morse_code[j].code) + strlen(SEPARATOR);
                    break;
                }
            }
        }
    }
}

int main() {
    char text[MAX_BUF_LEN] = ""; // Initialize text input buffer
    char morse[MAX_BUF_LEN] = ""; // Initialize Morse code output buffer

    // Prompt user for input
    printf("Enter text to convert to Morse code:\n");
    fgets(text, MAX_BUF_LEN, stdin);

    // Remove newline character from text input buffer
    strtok(text, "\n");

    // Convert text to Morse code
    text_to_morse(text, morse);

    // Print Morse code output
    printf("Morse code: %s\n", morse);

    return 0;
}