//FormAI DATASET v1.0 Category: String manipulation ; Style: curious
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100];
    int i, j, count = 0;

    printf("Enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);

    printf("\n\nOriginal sentence: %s\n\n", sentence);

    // Remove all vowels from the sentence
    for(i = 0; sentence[i]!='\0'; i++)
    {
        if(sentence[i]=='a' || sentence[i]=='e' ||
                sentence[i]=='i' || sentence[i]=='o' ||
                sentence[i]=='u' || sentence[i]=='A' ||
                sentence[i]=='E' || sentence[i]=='I' ||
                sentence[i]=='O' || sentence[i]=='U')
        {
            for(j = i; sentence[j]!='\0'; j++)
            {
                sentence[j] = sentence[j + 1];
            }
            i--;
        }
    }
    printf("Sentence without vowels: %s\n\n", sentence);

    // Count the number of words in the sentence
    for(i = 0; sentence[i] != '\0'; i++)
    {
        if(sentence[i] == ' ')
        {
            count++;
        }
    }
    count++;
    printf("Number of words in the sentence: %d\n\n", count);

    // Reverse the words in the sentence
    char temp;
    int start = 0;
    int end;

    for(i = 0; sentence[i]; i++)
    {
        if(sentence[i] == ' ' || sentence[i+1] == '\0')
        {
            if(sentence[i+1] == '\0')
            {
                end = i;
            }
            else
            {
                end = i-1;
            }

            while(start < end)
            {
                temp = sentence[start];
                sentence[start] = sentence[end];
                sentence[end] = temp;

                start++;
                end--;
            }
            start = i+1;
        }
    }
    printf("Reverse words in the sentence: %s", sentence);

    return 0;
}