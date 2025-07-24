//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: artistic
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100];
    char *morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    printf("Enter a sentence to convert to Morse code: ");
    fgets(sentence, 100, stdin);

    for (int i = 0; i < strlen(sentence); i++) // loop through each character in sentence
    {
        if (sentence[i] == ' ') // if character is a space, print a slash
        {
            printf("/");
        }
        else if (sentence[i] >= 'A' && sentence[i] <= 'Z') // if character is uppercase letter, convert to lowercase
        {
            printf("%s ", morse[sentence[i] - 'A']);
        }
        else if (sentence[i] >= 'a' && sentence[i] <= 'z') // if character is lowercase letter
        {
            printf("%s ", morse[sentence[i] - 'a']);
        }
    }
    return 0;
}