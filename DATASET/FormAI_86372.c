//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Declare a struct to store the Morse Code mapping
struct MorseMap {
    char letter;
    char code[6];
};

// Create an array of MorseMap structs for each letter of the alphabet 
// (including space)
struct MorseMap morse_map[] = {
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
    {' ', " "}
}; 

int main() {
    char input[MAX_LENGTH];  // Declare input string.
    printf("Enter a message to convert to Morse Code: ");
    fgets(input, MAX_LENGTH, stdin); // Read input string from stdin.
    input[strcspn(input, "\n")] = 0;  // Remove newline character from input.
    
    int length = strlen(input);
    printf("Input: %s\n", input);
    
    // Convert each letter in input string to Morse Code using the MorseMap struct
    for (int i = 0; i < length; i++) {
        char letter = toupper(input[i]);  // Convert input letter to uppercase
        char* code;  // Declare pointer to Morse Code string
        
        // Find Morse Code mapping for input letter
        for (int j = 0; j < sizeof(morse_map) / sizeof(morse_map[0]); j++) {
            if (morse_map[j].letter == letter) {
                code = morse_map[j].code;  // Set Morse Code pointer to mapping
                break;
            }
        }
        
        // Print Morse Code for input letter
        printf("%s ", code); 
    }
    
    printf("\n");
    return 0;
}