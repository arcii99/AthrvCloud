//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdio.h>
#include <string.h>

void convert_to_morse(char text[], char morse[]) {
    char morseAlphabet[26][8] = { // Morse code equivalent for each letter in the English alphabet
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", 
        ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", 
        "...-", ".--", "-..-", "-.--", "--.."
    };
    
    int i, j, textLen;
    for(i = 0; text[i] != '\0'; i++) { // Iterate through each character in the input text
        if(text[i] >= 'a' && text[i] <= 'z') { // If the character is a lowercase letter
            j = text[i] - 'a'; // Get the corresponding index in the morseAlphabet array
            strcat(morse, morseAlphabet[j]); // Append the morse code to the output string
        }
        else if(text[i] >= 'A' && text[i] <= 'Z') { // If the character is an uppercase letter
            j = text[i] - 'A'; // Get the corresponding index in the morseAlphabet array
            strcat(morse, morseAlphabet[j]); // Append the morse code to the output string
        }
        else if(text[i] == ' ') { // If the character is a space
            strcat(morse, " / "); // Append the morse code for a space (which is represented as "/")
        }
        else {
            strcat(morse, " "); // Adds a space to separate morse code for non-letter characters
        }
    }
}

int main() {
    char input[100], output[1000] = "";
    printf("Enter text to convert to Morse code: ");
    fgets(input, sizeof(input), stdin); // Get input from user
    
    convert_to_morse(input, output); // Convert input text to morse code
    
    printf("\nMorse code: %s\n", output); // Print the morse code string
    
    return 0;
}