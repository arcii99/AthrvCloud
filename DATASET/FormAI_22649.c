//FormAI DATASET v1.0 Category: Word Count Tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[1000];
    int countWords=0, countSentences=0, countVowels=0, countConsonants=0;

    printf("Enter a sentence: ");
    fgets(text, sizeof(text), stdin);

    for(int i=0; i<strlen(text); i++)
    {
        //Count Words
        if(text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
            countWords++;

        //Count Sentences
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
            countSentences++;

        //Count Vowels
        if(text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U')
            countVowels++;

        //Count Consonants
        if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
            countConsonants++;
    }

    printf("Words: %d\n", countWords+1);
    printf("Sentences: %d\n", countSentences);
    printf("Vowels: %d\n", countVowels);
    printf("Consonants: %d\n", countConsonants-countVowels);

    return 0;
}