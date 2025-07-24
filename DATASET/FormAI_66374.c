//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: creative
#include <stdio.h>
#include <string.h>

// Declare function for translating alien to english
void alien_to_english(char *input);

int main()
{
    char input[] = "Uaxnirp rpuj d,zp,r fdoxnrp udpgt-isd qirep rud gbndrzt!";
    printf("Alien Language Input: %s \n", input);
    printf("Translating... \n");
    alien_to_english(input);
    printf("English Output: %s \n", input);

    return 0;
}

void alien_to_english(char *input)
{
    // Define array for mapping alien characters to English
    char mapping[27] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ' '};
    // Define array for mapping English characters to Alien
    char reverse_mapping[27] = {'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'q', 'w', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ' '};

    // Loop through input and map each alien character to English
    for (int i = 0; i < strlen(input); i++)
    {
        for (int j = 0; j < 27; j++)
        {
            if (input[i] == mapping[j])
            {
                input[i] = reverse_mapping[j];
                break;
            }
        }
    }
}