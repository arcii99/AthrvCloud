//FormAI DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 100

// Function to count the number of vowels in a string
int count_vowels(char *str)
{
    int count = 0;
    char vowels[] = "aeiouAEIOU";
    int str_len = strlen(str);
    for (int i = 0; i < str_len; i++)
    {
        for (int j = 0; j < strlen(vowels); j++)
        {
            if (str[i] == vowels[j])
            {
                count++;
                break;
            }
        }
    }
    return count;
}

int main()
{
    char str[MAX_STRING_SIZE];
    printf("Enter a string: ");
    fgets(str, MAX_STRING_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the newline character from fgets

    int num_vowels = count_vowels(str);

    printf("\nNumber of vowels in the string: %d\n", num_vowels);

    printf("\nReversed string: ");
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n\n");

    return 0;
}