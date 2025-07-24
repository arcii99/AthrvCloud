//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: excited
#include<stdio.h>
#include<string.h>

int main()
{
    char sentence[1000], translated_sentence[1000] = "";
    int i, j, word_count = 0;

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter your sentence in English:\n");
    fgets(sentence, 1000, stdin);
    sentence[strlen(sentence)-1] = '\0'; // Removing newline character

    // Translate each word one by one
    for(i=0; i<strlen(sentence); i++)
    {
        if(sentence[i] == ' ')
        {
            word_count++; // Counting number of words in the sentence
            continue; // Skip this iteration
        }

        if(word_count%2 == 0) // Translate even position words
        {
            switch(sentence[i])
            {
                case 'a': translated_sentence[j] = 'm'; j++; break;
                case 'e': translated_sentence[j] = 'o'; j++; break;
                case 'i': translated_sentence[j] = 'u'; j++; break;
                case 'o': translated_sentence[j] = 'i'; j++; break;
                case 'u': translated_sentence[j] = 'a'; j++; break;
                default: translated_sentence[j] = sentence[i];
            }
        }
        else // Leave odd position words as is
        {
            translated_sentence[j] = sentence[i];
        }
        j++;
    }
    word_count++; // Increment word_count for the last word

    printf("Your translated sentence is:\n%s\n", translated_sentence);
    printf("Your sentence had %d words, out of which %d words were modified.\n", word_count, (word_count+1)/2);

    printf("\nThank you for using the C Cat Language Translator!\n");
    return 0;
}