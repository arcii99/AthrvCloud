//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    int i, j, len;
    char morse[27][5] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    printf("Hello there, I am a cheerful chatbot that can help you convert your text to Morse code! Please enter a sentence below:\n");
    scanf("%[^\n]", text);
    getchar(); // to clear input buffer

    len = strlen(text);

    for(i=0; i<len; i++)
    {
        if(text[i] == ' ')
        {
            printf(" / ");
            continue;
        }
        else if(text[i] >= 'a' && text[i] <= 'z')
        {
            j = text[i] - 'a';
        }
        else if(text[i] >= 'A' && text[i] <= 'Z')
        {
            j = text[i] - 'A';
        }
        else
        {
            printf(" ");
            continue;
        }

        printf("%s ", morse[j]);
    }

    printf("\nThank you for using my program! Have a nice day :)");

    return 0;
}