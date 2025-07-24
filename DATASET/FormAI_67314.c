//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Linus Torvalds
/* Linus Torvalds Style Text to Morse Code Conversion Example Program */

#include <stdio.h>
#include <string.h>

void convertToMorse(char *message);

int main(void)
{
    char message[100];
    printf("Enter the message: ");
    fgets(message, 100, stdin);
    convertToMorse(message);
    return 0;
}

void convertToMorse(char *message)
{
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '};
    char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/"};
    int i, j, k, l, message_length = strlen(message);
    for(i=0; i<message_length; i++)
    {
        if(message[i] == '\n')
        {
            continue;
        }
        else
        {
            for(j=0; j<27; j++)
            {
                if(message[i] == letters[j])
                {
                    printf("%s ", morse_code[j]);
                }
            }
        }
    }
}