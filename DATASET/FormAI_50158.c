//FormAI DATASET v1.0 Category: Encryption ; Style: statistical
/* Welcome to my unique encryption program in C! */
/* In this program, we will be using statistical techniques to encrypt a message. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function to calculate the frequency of each character in a string */
void calculate_frequency(char *text, int *freq)
{
    memset(freq, 0, sizeof(int)*26);
    for (int i = 0; i < strlen(text); i++) 
    {
        if (text[i] >= 'a' && text[i] <= 'z') 
        {
            freq[text[i] - 'a']++;
        }
    }
}

/* Function to shuffle an array */
void shuffle_array(int *arr, int size)
{
    srand(time(NULL));

    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    char plaintext[1000];
    printf("Please enter the message you want to encrypt: ");
    fgets(plaintext, 1000, stdin);

    int freq[26];
    calculate_frequency(plaintext, freq);

    printf("\nFrequency of each letter in the message:\n");
    for (int i = 0; i < 26; i++) 
    {
        printf("%c: %d\n", 'a' + i, freq[i]);
    }

    int shuffle_order[26];
    for (int i = 0; i < 26; i++) 
    {
        shuffle_order[i] = i;
    }
    shuffle_array(shuffle_order, 26);

    printf("\nShuffle order:\n");
    for (int i = 0; i < 26; i++) 
    {
        printf("%c -> %c\n", 'a' + i, shuffle_order[i] + 'a');
    }

    printf("\nEncrypted message:\n");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            printf("%c", shuffle_order[plaintext[i] - 'a'] + 'a');
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

    return 0;
}