//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main()
{
    char c, message[100], morse[100][10];
    int i, j, k, len;

    char letters[26][3] = {{"A"}, {"B"}, {"C"}, {"D"}, {"E"}, {"F"}, {"G"}, {"H"}, {"I"}, {"J"}, {"K"}, {"L"}, {"M"}, {"N"}, {"O"}, {"P"}, {"Q"}, {"R"}, {"S"}, {"T"}, {"U"}, {"V"}, {"W"}, {"X"}, {"Y"}, {"Z"}};
    char codes[26][5] = {{".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}};

    printf("Enter message: ");
    scanf("%[^\n]%*c", message);

    len = strlen(message);

    // Convert each character to Morse code and store in array
    for (i = 0; i < len; i++)
    {
        c = message[i];
        // If character is a space, add a space to array
        if (c == ' ')
        {
            strcpy(morse[i], " ");
        }
        // If character is a capital letter, convert to lowercase
        else if (c >= 'A' && c <= 'Z')
        {
            c += 32;
            // Find index of letter in letters array and copy corresponding code to morse array
            for (j = 0; j < 26; j++)
            {
                if (letters[j][0] == c)
                {
                    strcpy(morse[i], codes[j]);
                    break;
                }
            }
        }
        // If character is a lowercase letter, copy corresponding code to morse array
        else
        {
            // Find index of letter in letters array and copy corresponding code to morse array
            for (j = 0; j < 26; j++)
            {
                if (letters[j][0] == c)
                {
                    strcpy(morse[i], codes[j]);
                    break;
                }
            }
        }
    }

    // Print the Morse code message
    printf("Morse code: ");
    for (i = 0; i < len; i++)
    {
        printf("%s ", morse[i]);
    }

    return 0;
}