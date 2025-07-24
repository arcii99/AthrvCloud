//FormAI DATASET v1.0 Category: String manipulation ; Style: active
#include <stdio.h>
#include <string.h>

// Function to reverse a string
char *reverseString(char *str)
{
    int length = strlen(str);
    char *temp = malloc(sizeof(char) * length);
    int i, j;
    for (i = length - 1, j = 0; i >= 0; i--, j++)
    {
        temp[j] = str[i];
    }
    temp[j] = '\0';
    return temp;
}

int main()
{

    char str1[50], str2[50];
    printf("Enter a string: ");
    scanf("%s", str1);

    // Counting the number of vowels and consonants in the entered string
    int vowels = 0, consonants = 0, i;
    for (i = 0; i < strlen(str1); i++)
    {
        if (str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' ||
            str1[i] == 'o' || str1[i] == 'u' || str1[i] == 'A' ||
            str1[i] == 'E' || str1[i] == 'I' || str1[i] == 'O' || str1[i] == 'U') 
        {
            vowels++;
        }
        else if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z'))
        {
            consonants++;
        }
    }

    printf("Number of vowels in the entered string: %d\n", vowels);
    printf("Number of consonants in the entered string: %d\n", consonants);

    // Reversing the entered string
    char *revStr = reverseString(str1);
    printf("Reversed string: %s\n", revStr);
    free(revStr);

    // Copying the reversed string to a new string
    strcpy(str2, revStr);

    // Concatenating the two strings
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    // Checking if the entered string is a palindrome
    int flag = 0;
    for (i = 0; i < strlen(str1) / 2; i++)
    {
        if (str1[i] != str1[strlen(str1) - i - 1])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Entered string is a palindrome.\n");
    }
    else
    {
        printf("Entered string is not a palindrome.\n");
    }

    return 0;
}