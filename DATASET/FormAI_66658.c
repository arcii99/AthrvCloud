//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to convert text to morse code
void text_to_morse(const char* text)
{
    const char* morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", "--..--", ".-.-.-", "..--.."};

    const char* alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890.,?";
    int text_length = strlen(text);
    char morse[MAX_LENGTH];

    for (int i = 0; i < text_length; i++)
    {
        char ch = text[i];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - 'a' + 'A';
        }

        int pos = strchr(alpha, ch) - alpha;
        if (pos < 0)
        {
            continue;
        }

        strcpy(morse, morse_code[pos]);
        printf("%s ", morse);
    }
}

int main()
{
    char text[MAX_LENGTH];

    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Morse code: ");
    text_to_morse(text);

    return 0;
}