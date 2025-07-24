//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scalable
#include <stdio.h>
#include <string.h>

// Function to convert a character to Morse code
char* convertToMorse(char c) {
    switch(c) {
        case 'a': 
            return ".-"; // Morse code for a
        case 'b':
            return "-..."; // Morse code for b
        case 'c':
            return "-.-."; // Morse code for c
        case 'd':
            return "-.."; // Morse code for d
        case 'e':
            return "."; // Morse code for e
        case 'f':
            return "..-."; // Morse code for f
        case 'g':
            return "--."; // Morse code for g
        case 'h':
            return "...."; // Morse code for h
        case 'i':
            return ".."; // Morse code for i
        case 'j':
            return ".---"; // Morse code for j
        case 'k':
            return "-.-"; // Morse code for k
        case 'l':
            return ".-.."; // Morse code for l
        case 'm':
            return "--"; // Morse code for m
        case 'n':
            return "-."; // Morse code for n
        case 'o':
            return "---"; // Morse code for o
        case 'p':
            return ".--."; // Morse code for p
        case 'q':
            return "--.-"; // Morse code for q
        case 'r':
            return ".-."; // Morse code for r
        case 's':
            return "..."; // Morse code for s
        case 't':
            return "-"; // Morse code for t
        case 'u':
            return "..-"; // Morse code for u
        case 'v':
            return "...-"; // Morse code for v
        case 'w':
            return ".--"; // Morse code for w
        case 'x':
            return "-..-"; // Morse code for x
        case 'y':
            return "-.--"; // Morse code for y
        case 'z':
            return "--.."; // Morse code for z
        case '0':
            return "-----"; // Morse code for 0
        case '1':
            return ".----"; // Morse code for 1
        case '2':
            return "..---"; // Morse code for 2
        case '3':
            return "...--"; // Morse code for 3
        case '4':
            return "....-"; // Morse code for 4
        case '5':
            return "....."; // Morse code for 5
        case '6':
            return "-...."; // Morse code for 6
        case '7':
            return "--..."; // Morse code for 7
        case '8':
            return "---.."; // Morse code for 8
        case '9':
            return "----."; // Morse code for 9
        case ' ':
            return "/"; // Morse code for space
        default:
            return ""; // Return empty string if character is not supported
    }
}

int main() {
    char message[1000]; // Maximum length of message is 1000 characters
    printf("Enter message to be converted to Morse code:\n");
    fgets(message, 1000, stdin); // Get input from user
    int messageLength=strlen(message); // Determine length of message

    printf("Morse code:\n");
    for(int i=0; i<messageLength; i++) {
        char c = tolower(message[i]); // Convert character to lowercase to match Morse code
        char* morseCode = convertToMorse(c); // Call function to convert character to Morse code
        printf("%s ", morseCode); // Print Morse code for character
    }
    return 0;
}