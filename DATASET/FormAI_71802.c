//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: thoughtful
#include <stdio.h>
#include <string.h>

void convertToMorseCode(char *text);

int main() {
    char text[100];
    
    printf("Please enter the text to convert to Morse code:\n");
    fgets(text, sizeof(text), stdin);
    
    convertToMorseCode(text);
    
    return 0;
}

void convertToMorseCode(char *text) {
    int i;
    int j;
    
    char morseCode[36][6] = { 
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"}, 
        {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, 
        {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}, {".----"}, {"..---"}, {"...--"}, {"....-"}, 
        {"....."}, {"-...."}, {"--..."}, {"---.."}, {"----."}, {"-----"} 
    };
    
    char alphabet[36] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4',
        '5', '6', '7', '8', '9', '0'
    };
    
    int length = strlen(text);
    
    // Loop through the text
    for (i = 0; i < length; i++) {
        // Get the character in uppercase
        char c = toupper(text[i]);
        
        // Find the corresponding morse code
        for (j = 0; j < 36; j++) {
            if (alphabet[j] == c) {
                printf("%s ", morseCode[j]);
            }
        }
        
        // If the character is a space, output a newline
        if (c == ' ') {
            printf("\n");
        }
        
        // If the character is not in the alphabet, output question mark
        if (c < 'A' || c > 'Z') {
            printf("? ");
        }
    }
}