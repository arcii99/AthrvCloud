//FormAI DATASET v1.0 Category: String manipulation ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int countVowels(char* string) 
{
    int count = 0;
    for (int i = 0; i < strlen(string); i++) 
    {
        switch (string[i]) 
        {
            case 'a': case 'A':
            case 'e': case 'E':
            case 'i': case 'I':
            case 'o': case 'O':
            case 'u': case 'U':
                count++;
                break;
        }
    }
    return count;
}

int main() 
{
    printf("Welcome to the C String Manipulation Example Program!\n");
    printf("This program will demonstrate some basic string manipulation functions.\n");
    char str1[100], str2[100], temp[100];

    printf("Please enter the first string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("Please enter the second string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = 0;

    printf("The length of the first string is: %ld\n", strlen(str1));
    printf("The length of the second string is: %ld\n", strlen(str2));

    int result = strcmp(str1, str2);
    if (result == 0) 
    {
        printf("The strings are equal.\n");
    } 
    else if (result < 0) 
    {
        printf("The first string is less than the second string.\n");
    } 
    else 
    {
        printf("The first string is greater than the second string.\n");
    }

    printf("The concatenated string is: %s%s\n", str1, str2);

    strncpy(temp, str1, 5);
    temp[5] = '\0';
    printf("The substring of the first string is: %s\n", temp);

    printf("The number of vowels in the first string is: %d\n", countVowels(str1));
    
    printf("Thank you for using the C String Manipulation Example Program!\n");
    return 0;
}