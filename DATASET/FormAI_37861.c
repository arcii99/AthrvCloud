//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: high level of detail
#include <stdio.h>
#include <string.h>

char* textToMorse(char c)
{
    switch(c)
    {
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
         case '0': return "-----";
         case '1': return ".----";
         case '2': return "..---";
         case '3': return "...--";
         case '4': return "....-";
         case '5': return ".....";
         case '6': return "-....";
         case '7': return "--...";
         case '8': return "---..";
         case '9': return "----.";
         case '.': return ".-.-.-";
         case ',': return "--..--";
         case '?': return "..--..";
         case '!': return "-.-.--";
         case '@': return ".--.-.";
         case ' ': return "/";
        default: return "";
    }
}

void textToMorseCode(char* textMsg)
{
    for(int i = 0; i < strlen(textMsg); i++)
    {
        putchar(' '); // Add space between each Morse code letter
        printf("%s", textToMorse(textMsg[i]));
    }
 
    printf("\n"); // Print new line after message is translated
}

int main()
{
    char textMsg[100]; // Max message length is 100 characters
 
    printf("Enter text message: ");
    fgets(textMsg, sizeof(textMsg), stdin); 
    textMsg[strcspn(textMsg, "\n")] = 0; // Remove newline character from input
 
    textToMorseCode(textMsg); // Translate text message into Morse code
 
    return 0;
}