//FormAI DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

char* reverseString(char* string);
char* removeVowels(char* string);
char* capitalizeWords(char* string);

int main()
{
    char inputString[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(inputString, MAX_LENGTH, stdin);
    
    printf("\nOriginal String: %s", inputString);
    char* reversedString = reverseString(inputString);
    printf("Reversed String: %s", reversedString);
    
    char* noVowelsString = removeVowels(inputString);
    printf("String with Vowels removed: %s", noVowelsString);
    
    char* capitalizedWords = capitalizeWords(inputString);
    printf("String with Capitalized Words: %s", capitalizedWords);
    
    return 0;
}

char* reverseString(char* string)
{
    int length = strlen(string) - 1;
    char* reversedString = (char*) malloc(length * sizeof(char));
    int i, j;
    
    for (i = length - 2, j = 0; i >= 0; i--, j++)
    {
        reversedString[j] = string[i];
    }
    reversedString[j] = '\0';
    
    return reversedString;
}

char* removeVowels(char* string)
{
    int length = strlen(string) - 1;
    char* noVowelsString = (char*) malloc(length * sizeof(char));
    int i, j;
    
    for (i = 0, j = 0; i < length; i++)
    {
        if (string[i] != 'a' && string[i] != 'e' && string[i] != 'i' && string[i] != 'o' && string[i] != 'u' 
        && string[i] != 'A' && string[i] != 'E' && string[i] != 'I' && string[i] != 'O' && string[i] != 'U')
        {
            noVowelsString[j] = string[i];
            j++;
        }
    }
    noVowelsString[j] = '\0';
    
    return noVowelsString;
}

char* capitalizeWords(char* string)
{
    int length = strlen(string) - 1;
    char* capitalizedString = (char*) malloc(length * sizeof(char));
    int i, j;
    
    for (i = 0; string[i] != '\0'; i++)
    {
        if (i == 0 || string[i-1] == ' ')
        {
            capitalizedString[i] = toupper(string[i]);
        }
        else
        {
            capitalizedString[i] = string[i];
        }
    }
    capitalizedString[length-1] = '\0';
    
    return capitalizedString;
}