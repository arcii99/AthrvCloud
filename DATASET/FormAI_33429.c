//FormAI DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include<stdio.h>
#include<string.h>

// Function to count the frequency of characters in string
void frequency(char *str, int len, int freq[])
{
    for(int i=0; i<len; i++)
    {
        freq[str[i]]++;
    }
}

// Function to do compression
void compression(char *str, int len)
{
    int freq[256] = {0}; // array to store the frequency of each character
    frequency(str, len, freq); // counting frequency of characters

    // Printing the compressed string
    printf("The compressed string is: ");
    for(int i=0; i<len; i++)
    {
        if(freq[str[i]] != 0)
        {
            printf("%c%d", str[i], freq[str[i]]); //printing the character and its frequency
            freq[str[i]] = 0; // resetting frequency to 0
        }
    }   
}

int main()
{
    char str[100];
    int len;

    printf("Welcome to the compression program! \n");
    printf("Please enter the string to compress: ");
    scanf("%[^\n]s", str);

    len = strlen(str);

    compression(str, len);

    return 0;
}