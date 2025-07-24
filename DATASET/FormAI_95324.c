//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdio.h>
#include <string.h>

char *morseCode(char);

int main() {
    char msg[100];
    printf("Enter your message: ");
    fgets(msg, 100, stdin); // Taking input from user
    msg[strlen(msg) - 1] = '\0'; // Removing the newline character '\n'
    
    for(int i = 0; i < strlen(msg); i++) { // Loop through each character in message
        char ch = toupper(msg[i]); // Convert to uppercase for ease of conversion
        char *morse = morseCode(ch); // Get Morse code for the character
        printf("%s ", morse); // Print the Morse code of the character
    }
    
    return 0;
}

char *morseCode(char ch) {
    static char morse[5]; // Morse code is not more than 5 characters long
    
    switch(ch) { // Convert the character to Morse code
        case 'A':
            strcpy(morse, ".-");
            break;
        case 'B':
            strcpy(morse, "-...");
            break;
        case 'C':
            strcpy(morse, "-.-.");
            break;
        case 'D':
            strcpy(morse, "-..");
            break;
        case 'E':
            strcpy(morse, ".");
            break;
        case 'F':
            strcpy(morse, "..-.");
            break;
        case 'G':
            strcpy(morse, "--.");
            break;
        case 'H':
            strcpy(morse, "....");
            break;
        case 'I':
            strcpy(morse, "..");
            break;
        case 'J':
            strcpy(morse, ".---");
            break;
        case 'K':
            strcpy(morse, "-.-");
            break;
        case 'L':
            strcpy(morse, ".-..");
            break;
        case 'M':
            strcpy(morse, "--");
            break;
        case 'N':
            strcpy(morse, "-.");
            break;
        case 'O':
            strcpy(morse, "---");
            break;
        case 'P':
            strcpy(morse, ".--.");
            break;
        case 'Q':
            strcpy(morse, "--.-");
            break;
        case 'R':
            strcpy(morse, ".-.");
            break;
        case 'S':
            strcpy(morse, "...");
            break;
        case 'T':
            strcpy(morse, "-");
            break;
        case 'U':
            strcpy(morse, "..-");
            break;
        case 'V':
            strcpy(morse, "...-");
            break;
        case 'W':
            strcpy(morse, ".--");
            break;
        case 'X':
            strcpy(morse, "-..-");
            break;
        case 'Y':
            strcpy(morse, "-.--");
            break;
        case 'Z':
            strcpy(morse, "--..");
            break;
        case '0':
            strcpy(morse, "-----");
            break;
        case '1':
            strcpy(morse, ".----");
            break;
        case '2':
            strcpy(morse, "..---");
            break;
        case '3':
            strcpy(morse, "...--");
            break;
        case '4':
            strcpy(morse, "....-");
            break;
        case '5':
            strcpy(morse, ".....");
            break;
        case '6':
            strcpy(morse, "-....");
            break;
        case '7':
            strcpy(morse, "--...");
            break;
        case '8':
            strcpy(morse, "---..");
            break;
        case '9':
            strcpy(morse, "----.");
            break;
        default:
            strcpy(morse, ""); // For any character not in the above list, return empty string
    }
    
    return morse; // Return the Morse code of the character
}