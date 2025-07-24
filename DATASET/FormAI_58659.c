//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// Function to convert text to Morse code
void morseCode(char str[])
{
    // Morse code array for each character
    char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", " "};
    
    // Text array for each character
    char *text[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " ", "\0"};
    
    int i, j, k;
    
    printf("Morse code: ");
    for(i = 0; str[i] != '\0'; i++)
    {
        for(j = 0; j < 27; j++)
        {
            if(str[i] == *text[j])
            {
                printf("%s", morse[j]);
            }
        }
    }
    printf("\n");
}

int main()
{
    char str[100];
    
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    
    printf("Text: %s\n", str);
    
    morseCode(str);
    
    return 0;
}