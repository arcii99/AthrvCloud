//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: lively
/* 
 * This program converts any text input to Morse code representation. 
 * The user inputs a text string of up to 100 characters and the program 
 * outputs the corresponding Morse code to the console.
*/

#include <stdio.h>
#include <string.h>

void convertToMorse(char* text);

int main() 
{
    char text[100];
    printf("Enter text to convert to Morse code:\n");
    fgets(text, 100, stdin); // get text input from user
    convertToMorse(text); // convert text to Morse and print
    
    return 0;
}

void convertToMorse(char* text)
{
    char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", 
                     "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", 
                     "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
                     "-.--", "--..", "/", " ", "", "", "", "", "", "", "", "",
                     ".----", "..---", "...--", "....-", ".....", "-....", 
                     "--...", "---..", "----.", "-----"}; // Morse code lookup table
    int i, j, len = strlen(text);
    for (i = 0; i < len; i++) // iterate through each character in text
    {
        if (text[i] == '\n') break; // exit loop when end of text input is reached
        else if (text[i] >= 'A' && text[i] <= 'Z') // convert uppercase letters
        {
            j = (int) text[i] - 65; // get index position for corresponding letter in Morse code array
            printf("%s ", morse[j]); // print Morse code for letter
        }
        else if (text[i] >= 'a' && text[i] <= 'z') // convert lowercase letters
        {
            j = (int) text[i] - 97; // get index position for corresponding letter in Morse code array
            printf("%s ", morse[j]); // print Morse code for letter
        }
        else if (text[i] >= '0' && text[i] <= '9') // convert numbers
        {
            j = 26 + ((int) text[i] - 48); // get index position for corresponding number in Morse code array
            printf("%s ", morse[j]); // print Morse code for number
        }
        else // handle characters not found in lookup table
        {
            printf("X "); // print "X" to indicate unknown character
        }
    }
    printf("\n"); // print newline character after last Morse code symbol
}