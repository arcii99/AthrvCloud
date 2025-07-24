//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

// Function to convert text to Morse code
void textToMorse(char text[])
{
    char morseCode[100][10] = {
      ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
      ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
    };
    
    int len = strlen(text);
    int i, j;
    for(i = 0; i < len; i++)
    {
        // Check for space
        if(text[i] == ' ')
        {
            printf(" ");
        }
        else
        {
            // Convert the character to uppercase to match the Morse code table
            char c = toupper(text[i]);
            
            // Find the index of the character in the Morse code table
            int index = (int)c - 65;
            
            // Print the Morse code for the character
            printf("%s ", morseCode[index]);
        }
    }
    printf("\n");
}

int main()
{
    char text[100];
    printf("Enter some text: ");
    fgets(text, 100, stdin);
    printf("Morse code: ");
    textToMorse(text);
    return 0;
}