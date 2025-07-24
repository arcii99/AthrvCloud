//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: relaxed
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/"};

const char *char_set = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

int main()
{
    printf("-----------Morse Code Converter--------------\n");

    char input_str[1000];
    printf("\nEnter text to convert to Morse Code:\n");
    fgets(input_str, sizeof(input_str), stdin);

    printf("\nInput Text: %s\n", input_str);

    int length = strlen(input_str);
    input_str[length - 1] = '\0';
    length--;

    printf("\nMorse Code: ");

    for (int i = 0; i < length; i++)
    {
        int index;
        if (isalpha(input_str[i]))
        {
            index = toupper(input_str[i]) - 'A';
        }
        else if (input_str[i] == ' ')
        {
            index = 26;
        }
        else
        {
            continue;
        }

        printf("%s ", morse_code[index]);
    }

    printf("\n");

    return 0;
}