//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

// function to convert text to morse code
void textToMorse(char text[])
{
    int length = strlen(text);

    // array to map characters to morse code
    char* morse[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                       ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
                       ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
    
    // loop through each character in text
    for (int i = 0; i < length; i++)
    {
        // check if character is a space
        if (text[i] == ' ')
        {
            printf("  ");
        }
        else
        {
            // get index of character in morse array
            int index = text[i] - 'a';
            
            // print morse code for character
            printf("%s ", morse[index]);
        }
    }
}

int main()
{
    char text[] = "this is a unique c text to morse code conversion example program";
    
    printf("Text: %s\n", text);
    printf("Morse Code: ");
    
    // convert text to morse code
    textToMorse(text);

    return 0;
}