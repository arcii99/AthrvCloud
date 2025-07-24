//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

// Function to check if a given word is valid in C Alien Language
int isValid(char* word, char* pattern)
{
    int wlen = strlen(word);
    int plen = strlen(pattern);
    if(wlen != plen)
        return 0;
    for(int i=0; i<plen; i++)
    {
        if(pattern[i] != '*' && word[i] != pattern[i])
            return 0;
    }
    return 1;
}

int main()
{
    char dictionary[][10] = {"hello", "world", "c", "alien", "language", "translator"};
    char pattern[] = "c***en******"; // Taking an example pattern
    int dict_len = sizeof(dictionary)/sizeof(dictionary[0]);
    int count = 0;
    for(int i=0; i<dict_len; i++)
    {
        if(isValid(dictionary[i], pattern))
        {
            printf("%d. %s\n", count+1, dictionary[i]);
            count++;
        }
    }
    if(count == 0)
        printf("No words found!\n");
    else
        printf("Total %d word(s) found!\n", count);
    return 0;
}