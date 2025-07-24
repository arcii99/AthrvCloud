//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <string.h>

const char* MORSE_TABLE[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};

const char* ALPHA_TABLE[36] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};

void gratefulMessage()
{
    printf("Welcome to the Text to Morse Code Converter, today is a great day!\n");
    printf("We are grateful for you choosing our program and we are excited to help!\n");
    printf("Let's get started!\n");
}

void convertToMorseCode(char input[])
{
    printf("\n");
    printf("Input Text: %s\n", input);
    printf("Morse Code: ");
    for (int i = 0; i < strlen(input); i++) 
    {
        if (input[i] == ' ') 
        {
            printf("/ ");
        } 
        else 
        {
            char upperCaseInput = toupper(input[i]);
            int index = upperCaseInput - 'A';
            printf("%s ", MORSE_TABLE[index]);
        }
    }
    printf("\n");
    printf("Thank you for using our program!\n");
}

int main() 
{
    gratefulMessage();

    char input[100];

    printf("Enter text to convert to Morse Code: ");
    fgets(input, sizeof(input), stdin);

    convertToMorseCode(input);

    return 0;
}