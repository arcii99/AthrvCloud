//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *ascii_to_morse(char *input)
{
    char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", 
                     "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", 
                     ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
                     ".--", "-..-", "-.--", "--..", " ", "", NULL};
    char *ascii[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", 
                     "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", 
                     "U", "V", "W", "X", "Y", "Z", " ", "", NULL};
    char *output = malloc(strlen(input) * 5);
    int i, j;
    for(i=0; i<strlen(input); i++)
    {
        for(j=0; ascii[j]; j++)
        {
            if(toupper(input[i]) == ascii[j][0])
            {
                strcat(output, morse[j]);
                strcat(output, " ");
                break;
            }
        }
    }
    return output;
}

int main()
{
    char input[256];
    char *output;
    printf("Enter the text to convert to Morse code: ");
    fgets(input, 256, stdin);
    output = ascii_to_morse(input);
    printf("Morse code equivalent: %s\n", output);
    free(output);
    return 0;
}