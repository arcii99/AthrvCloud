//FormAI DATASET v1.0 Category: Text processing ; Style: genious
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100

int main()
{
    char input_str[MAX_STR_LEN];
    char output_str[MAX_STR_LEN];
    int vowels_count = 0;
    int consonants_count = 0;
    int i;

    printf("Enter a string: ");
    fgets(input_str, MAX_STR_LEN, stdin);

    for (i = 0; i < strlen(input_str); i++)
    {
        char c = tolower(input_str[i]);
        if (c >= 'a' && c <= 'z') 
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
            {
                vowels_count++;
            } 
            else 
            {
                consonants_count++;
            }
        }
    }

    strcpy(output_str, input_str);

    // Remove all vowels
    for (i = 0; i < strlen(output_str); i++) 
    {
        char c = tolower(output_str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
        {
            strcpy(&output_str[i], &output_str[i+1]);
            i--;
        }
    }

    printf("Input string: %s\n", input_str);
    printf("Output string: %s\n", output_str);
    printf("Number of vowels: %d\n", vowels_count);
    printf("Number of consonants: %d\n", consonants_count);

    return 0;
}