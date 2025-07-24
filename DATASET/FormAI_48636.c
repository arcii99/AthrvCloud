//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: accurate
#include <stdio.h>
#include <string.h>

void convertTextToMorseCode(char*);

int main()
{
    char text[100];

    printf("Enter the text to convert to Morse Code: ");
    fgets(text, 100, stdin);

    convertTextToMorseCode(text);

    return 0;
}

void convertTextToMorseCode(char* text)
{
    int i, j, k;
    char morseCode[36][6] = {
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."},
        {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."},
        {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"},
        {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}, {".----"},
        {"..---"}, {"...--"}, {"....-"}, {"....."}, {"-...."}, {"--..."},
        {"---.."}, {"----."}, {"-----"}
    };

    char letters[36] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                        'Y', 'Z', '1', '2', '3', '4', '5', '6',
                        '7', '8', '9', '0'};

    int len = strlen(text);

    printf("\nMorse Code: ");

    for(i=0; i<len; i++)
    {
        if(text[i] != ' ')
        {
            for(j=0; j<36; j++)
            {
                if(text[i] == letters[j] || text[i] == letters[j]+32)
                {
                    printf("%s ", morseCode[j]);
                    break;
                }
            }
        }
        else
        {
            printf("  ");
        }
    }
}