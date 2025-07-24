//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: enthusiastic
// Welcome to the Text to Morse Code Conversion program, 
// where we transform your text into a series of dots and dashes!
// Get ready for some exciting Morse code action!
#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    char morse_code[100][50]; // each code can have up to 50 characters (dots, dashes, spaces)
    char morse_chars[36][6] = {
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."},
        {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"},
        {"-.--"}, {"--.."}, {".----"}, {"..---"}, {"...--"}, {"....-"}, {"....."}, {"-...."}, {"--..."}, {"---.."}, {"----."}
    };
    
    printf("Welcome to the Text to Morse Code Conversion program!\n");
    printf("Please enter your text (up to 100 characters) and press enter: ");
    fgets(text, 100, stdin);
    int text_len = strlen(text) - 1; // ignore the newline character
    
    // convert each character into Morse code
    for (int i = 0; i < text_len; i++) {
        char c = tolower(text[i]);
        if (c >= 'a' && c <= 'z') { // alphabets
            int index = c - 'a';
            strcpy(morse_code[i], morse_chars[index]);
        } else if (c >= '0' && c <= '9') { // numbers
            int index = c - '0' + 26;
            strcpy(morse_code[i], morse_chars[index]);
        } else { // space or unknown character
            strcpy(morse_code[i], "/");
        }
    }
    
    // print the Morse code sequence
    printf("\nHere's your text in Morse code:\n");
    for (int i = 0; i < text_len; i++) {
        printf("%s ", morse_code[i]);
    }
    printf("\n");
    
    // celebrate the success of the program
    printf("Congratulations! You now know how to speak in Morse code!\n");
    printf("Keep practicing and impress your friends!\n");
    return 0;
}