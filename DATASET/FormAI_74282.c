//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void count_frequency(char *str)
{
    int count[26] = {0}; // array to store count of each character
    // loop through each character in the string
    for (int i = 0; i < strlen(str); i++)
    {
        // if character is a letter, increment count of its corresponding index in the array
        if (isalpha(str[i]))
        {
            int index = tolower(str[i]) - 'a'; // calculate index of character
            count[index]++;
        }
    }
    // print the frequency count of each character
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            printf("%c: %d\n", i + 'a', count[i]);
        }
    }
}

int main()
{
    char str[1000];
    printf("Enter a string: ");
    fgets(str, 1000, stdin); // read string from user

    printf("Frequency of each letter in the string:\n");
    count_frequency(str); // count the frequency of each letter

    return 0;
}