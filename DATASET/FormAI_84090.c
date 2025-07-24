//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_MORSE_LENGTH 5  // Maximum length of a morse code
#define MAX_TEXT_LENGTH 100 // Maximum length of input text

char* morseCode[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", 
                      ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
                      ".--", "-..-", "-.--", "--.." };

char* letterList = "abcdefghijklmnopqrstuvwxyz"; // List of alphabetic letters

// Function to convert any text to morse code
void convertToMorse(char text[], char morse[])
{
    int i, j;
    
    for(i = 0; i < strlen(text); i++) 
    {
        // Check if the character is an alphabetic letter
        if(isalpha(text[i])) 
        {
            // Convert the character to lowercase
            text[i] = tolower(text[i]);
            
            // Find the morse code for the letter
            for(j = 0; j < strlen(letterList); j++) 
            {
                if(text[i] == letterList[j]) 
                {
                    strcat(morse, morseCode[j]);
                    strcat(morse, " "); // Add a space between two letters
                    break;
                }
            }
        } 
        // Check if the character is a space
        else if(text[i] == ' ') 
        {
            strcat(morse, "/ "); // Add a forward slash for a space
        } 
        // Check if the character is a digit
        else if(isdigit(text[i])) 
        {
            strcat(morse, text[i]);
            strcat(morse, " "); // Add a space between two digits
        }
    }
}

int main() 
{
    char input_text[MAX_TEXT_LENGTH];
    char morse_code[MAX_TEXT_LENGTH * MAX_MORSE_LENGTH] = ""; // Initialize morse code string as an empty string
    
    printf("Enter any text to convert to morse code:\n");
    fgets(input_text, MAX_TEXT_LENGTH, stdin);
    
    // Remove the newline character from the input string
    input_text[strcspn(input_text, "\n")] = '\0';
    
    convertToMorse(input_text, morse_code);
    
    printf("Morse code for the input text:\n%s", morse_code);
    
    return 0;
}