//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: genious
#include <stdio.h>
#include <string.h>

char* morse_code(char);

int main()
{
    char text[100];
    printf("Enter text to convert into Morse code:\n");
    fgets(text, sizeof(text), stdin);

    int len = strlen(text);

    // Loop through each character and print its Morse code equivalent
    for(int i = 0; i < len; i++)
    {
        char ch = text[i];

        // Convert uppercase to lowercase and ignore non-alphabetic characters
        if(ch >= 'A' && ch <= 'Z') ch += 32;
        if(ch < 'a' || ch > 'z') continue;

        char* morse = morse_code(ch);
        printf("%s ", morse);
    }

    printf("\n");
    return 0;
}

char* morse_code(char ch)
{
    // Morse code lookup table for alphabetic characters
    char* lookup[26] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    return lookup[ch - 'a'];
}