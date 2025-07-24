//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if character is a vowel
int isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return 1;
    else
        return 0;
}

int main()
{
    char ccl[1000]; // C Cat Language string to be translated
    char eng[1000] = ""; // English string after translation
    int i;

    printf("Enter C Cat Language string to be translated : ");
    gets(ccl);

    for (i = 0; ccl[i] != '\0'; i++) // Loop through each character in the C Cat Language string
    {
        if (isVowel(ccl[i])) // If character is a vowel
        {
            if (ccl[i] >= 'a' && ccl[i] <= 'z') // If character is a lowercase vowel
            {
                strcat(eng, "meow"); // Append "meow" to the English string
            }
            else if (ccl[i] >= 'A' && ccl[i] <= 'Z') // If character is an uppercase vowel
            {
                strcat(eng, "MEOW"); // Append "MEOW" to the English string
            }
        }
        else // If character is not a vowel
        {
            eng[strlen(eng)] = ccl[i]; // Append the character to the English string
            eng[strlen(eng)] = '\0'; // Add null terminator at the end
        }
    }

    printf("Translated string in English : %s", eng); // Display the translated string in English

    return 0;
}