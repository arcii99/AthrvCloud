//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: cheerful
#include<stdio.h>
#include<string.h>

int main()
{
    printf("Welcome to the Cheerful Word Frequency Counter!\n");
    printf("Please enter any sentence that comes to your mind: \n");

    char sentence[1000];
    fgets(sentence, 1000, stdin);

    int frequency[26];
    memset(frequency, 0, sizeof(frequency));

    int i = 0;
    while(sentence[i] != '\0')
    {
        if(sentence[i] >= 'a' && sentence[i] <= 'z')
        {
            frequency[sentence[i] - 'a']++;
        }
        else if(sentence[i] >= 'A' && sentence[i] <= 'Z')
        {
            frequency[sentence[i] - 'A']++;
        }
        i++;
    }

    printf("\nHere is the frequency count for each letter in your sentence: \n");

    for(i = 0; i < 26; i++)
    {
        if(frequency[i] > 0)
        {
            printf("%c - %d\n", i + 'a', frequency[i]);
        }
    }

    printf("\nThank you for using the Cheerful Word Frequency Counter!\n");

    return 0;
}