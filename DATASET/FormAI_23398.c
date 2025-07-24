//FormAI DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the frequency of each character in the given string
void calculate_frequency(char *str, int *freq)
{
    for(int i=0; i<strlen(str); i++)
    {
        freq[(int)str[i]]++;
    }
}

// Function to print the frequency of each character in the given string
void print_frequency(char *str, int *freq)
{
    printf("Frequency of characters in the string '%s':\n", str);
    for(int i=0; i<strlen(str); i++)
    {
        if(freq[(int)str[i]] != 0)
        {
            printf("%c: %d\n", str[i], freq[(int)str[i]]);
            freq[(int)str[i]] = 0;
        }
    }
}

int main()
{
    char str[100];
    int freq[256] = {0}; // Initializing array with 0s
    
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // Removing trailing newline character
    
    calculate_frequency(str, freq);
    print_frequency(str, freq);
    
    return 0;
}