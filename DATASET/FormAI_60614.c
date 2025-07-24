//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: artistic
#include <stdio.h>
#include <string.h>

void convertToMorse(char* text);

int main()
{
    char input[100];
    printf("Enter text to convert to Morse code: ");
    fgets(input, 100, stdin);
    convertToMorse(input);

    return 0;
}

void convertToMorse(char* text)
{
    // Morse code dictionary
    char* morseCode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                            ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
                            "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    char* letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Alphabets string
    char* numbers[10] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", 
                            "--...", "---..", "----."}; // Numbers array

    int len = strlen(text);
    for(int i = 0; i < len; i++)
    {
        char c = toupper(text[i]); // convert to uppercase for case-insensitivity
        if(c == ' ') // individual words separation
            printf("     ");
        else if(c >= 'A' && c <= 'Z') //convert alphabets
            printf("%s ", morseCode[c-'A']);
        else if(c >= '0' && c <= '9') //convert numbers
            printf("%s ", numbers[c-'0']);
    }
}