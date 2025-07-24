//FormAI DATASET v1.0 Category: String manipulation ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char message[1000];
    printf("Enter a message: ");
    fgets(message,1000,stdin);

    int length = strlen(message);

    // count number of spaces
    int space_count = 0;
    for(int i=0; i<length; i++)
    {
        if(message[i] == ' ')
        {
            space_count++;
        }
    }

    // replace spaces with underscores
    char new_message[1000];
    int j=0;
    for(int i=0; i<length; i++)
    {
        if(message[i] == ' ')
        {
            new_message[j] = '_';
            j++;
        }
        else
        {
            new_message[j] = message[i];
            j++;
        }
    }
    new_message[j] = '\0';

    printf("Original Message: %s", message);
    printf("Modified Message: %s", new_message);

    // reverse the message
    char reverse_message[1000];
    int k=0;
    for(int i=length-1; i>=0; i--)
    {
        reverse_message[k] = message[i];
        k++;
    }
    reverse_message[k] = '\0';

    printf("Reversed Message: %s", reverse_message);

    // convert message to uppercase
    char upper_message[1000];
    for(int i=0; i<length; i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            upper_message[i] = message[i] - 32;
        }
        else
        {
            upper_message[i] = message[i];
        }
    }
    upper_message[length] = '\0';

    printf("Uppercase Message: %s", upper_message);

    // count vowels and consonants
    int vowel_count = 0, consonant_count = 0;
    for(int i=0; i<length; i++)
    {
        if(message[i] == 'a' || message[i] == 'e' || message[i] == 'i' || message[i] == 'o' || message[i] == 'u' || message[i] == 'A' || message[i] == 'E' || message[i] == 'I' || message[i] == 'O' || message[i] == 'U')
        {
            vowel_count++;
        }
        else if((message[i] >= 'a' && message[i] <= 'z') || (message[i] >= 'A' && message[i] <= 'Z'))
        {
            consonant_count++;
        }
    }

    printf("Number of vowels: %d\n", vowel_count);
    printf("Number of consonants: %d\n", consonant_count);

    // remove extra spaces from message
    char trimmed_message[1000];
    int l=0;
    for(int i=0; i<length; i++)
    {
        if(message[i] != ' ')
        {
            trimmed_message[l] = message[i];
            l++;
        }
        else if(i != 0 && i != length-1 && message[i-1] != ' ')
        {
            trimmed_message[l] = message[i];
            l++;
        }
    }
    trimmed_message[l] = '\0';

    printf("Trimmed Message: %s", trimmed_message);

    return 0;
}