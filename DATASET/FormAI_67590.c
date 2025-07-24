//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: excited
#include <stdio.h>
#include <string.h>

// Function to convert text to morse code
void textToMorse(char *text)
{
    char morse[37][7] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
    "..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.","/"};

    int len = strlen(text);

    printf("\nThe Morse code for '%s' is: \n", text);

    // Traverse through each character of the given text and convert to Morse code
    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ')
        {
            printf("/");
            continue;
        }

        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            printf("%s ", morse[text[i] - 'A']);
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            printf("%s ", morse[text[i] - 'a']);
        }
        else if (text[i] >= '0' && text[i] <= '9')
        {
            printf("%s ", morse[26 + text[i] - '0']);
        }
    }
}

int main()
{
    char text[100];

    printf("Welcome to the Morse Code Converter!");
    printf("\nEnter the text in English: ");
    scanf("%[^\n]", text);
    textToMorse(text);
    printf("\nThank you for using the Morse Code Converter!");

    return 0;
}