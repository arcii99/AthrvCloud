//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

void morseCodeConversion(char message[], int size);

int main()
{
    char message[20];
    
    printf("Enter a message to convert to Morse code: ");
    scanf("%s", message);
    
    // Convert message to Morse code and print the output
    morseCodeConversion(message, strlen(message));
    
    return 0;
}

void morseCodeConversion(char message[], int size)
{
    // Mapping of alphabets and numbers to Morse code
    char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                     "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                     "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                     "-.--", "--..", "-----", ".----", "..---", "...--", "....-",
                     ".....", "-....", "--...", "---..", "----."};
                     
    // Loop through the message and convert each character to Morse code
    for (int i = 0; i < size; i++)
    {
        // Check if the character is an alphabet or a number
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            printf("%s ", morse[message[i] - 'a']);
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            printf("%s ", morse[message[i] - 'A']);
        }
        else if (message[i] >= '0' && message[i] <= '9')
        {
            printf("%s ", morse[26 + message[i] - '0']);
        }
    }
}