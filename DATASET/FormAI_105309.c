//FormAI DATASET v1.0 Category: Word Count Tool ; Style: medieval
#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000], word[100];
    int count = 0, i, j, str_len, word_len;

    // Prompt user to input string and word
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter a word to count: ");
    scanf("%s", word);

    // Calculate lengths of string and word
    str_len = strlen(str);
    word_len = strlen(word);

    // Check for word occurrences
    for(i=0;i<=str_len-word_len;i++)
    {
        // Check if word is present at current position
        for(j=0;j<word_len;j++)
        {
            if(str[i+j]!=word[j])
            {
                break;
            }
        }
        if(j==word_len)
        {
            // Word was found, increase count
            count++;
        }
    }

    // Print word count result
    printf("'%s' occurs %d times in the string.\n", word, count);

    return 0;
}