//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

// Function that converts each letter to Morse code
char *to_morse(char letter) {
    switch(letter) {
        case 'a': return ".-";
        case 'b': return "-...";
        case 'c': return "-.-.";
        case 'd': return "-..";
        case 'e': return ".";
        case 'f': return "..-.";
        case 'g': return "--.";
        case 'h': return "....";
        case 'i': return "..";
        case 'j': return ".---";
        case 'k': return "-.-";
        case 'l': return ".-..";
        case 'm': return "--";
        case 'n': return "-.";
        case 'o': return "---";
        case 'p': return ".--.";
        case 'q': return "--.-";
        case 'r': return ".-.";
        case 's': return "...";
        case 't': return "-";
        case 'u': return "..-";
        case 'v': return "...-";
        case 'w': return ".--";
        case 'x': return "-..-";
        case 'y': return "-.--";
        case 'z': return "--..";
        case ' ': return " ";
    }
}

int main() {
    char message[100];
    printf("Enter a message in English:\n");
    fgets(message, 100, stdin);
    printf("The message in Morse code is:\n");

    // Loop through each character in the message
    for(int i = 0; i < strlen(message); i++) {
        char *morse = to_morse(tolower(message[i])); // Convert character to lowercase and then to Morse code
        printf("%s ", morse);
    }
    printf("\n");
    
    return 0;
}