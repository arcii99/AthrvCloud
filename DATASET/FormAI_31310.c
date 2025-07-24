//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: active
#include <stdio.h>
#include <string.h>

int main()
{
    // Define variables
    char text[100], morse[100][10];
    int i, j, len;
    
    // Morse code chart array
    const char *morse_chart[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
                                    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
                                    "-.--", "--.."};
    
    // Get input from user
    printf("Enter the text to convert to Morse code: ");
    fgets(text, 100, stdin);
    
    // Convert text to uppercase
    len = strlen(text);
    for(i = 0; i < len; i++)
    {
        text[i] = toupper(text[i]);
    }
    
    // Convert each character to Morse code
    for(i = 0; i < len; i++)
    {
        if(text[i] == ' ')
        {
            strcpy(morse[i], "/");
        }
        else if(text[i] >= 'A' && text[i] <= 'Z')
        {
            strcpy(morse[i], morse_chart[text[i]-'A']);
        }
    }
    
    // Print out Morse code output
    printf("\nMorse code output: ");
    for(i = 0; i < len; i++)
    {
        printf("%s ", morse[i]);
    }
    
    return 0;
}