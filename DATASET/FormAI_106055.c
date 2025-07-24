//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main()
{
    // define the C Cat Language variables
    char ccat_sentence[100];
    int ccat_word_count = 0;
    int ccat_meow_count = 0;

    // define the English Language variables
    char english_sentence[100];
    int english_word_count = 0;

    // get the C Cat Language sentence from the user
    printf("Enter a sentence in C Cat Language: ");
    fgets(ccat_sentence, 100, stdin);

    // count the number of words and meows in the C Cat Language sentence
    for (int i = 0; i < strlen(ccat_sentence); i++)
    {
        if (ccat_sentence[i] == ' ')
        {
            ccat_word_count++;
        }
        if (ccat_sentence[i] == 'M')
        {
            ccat_meow_count++;
        }
    }
    ccat_word_count++; // add 1 to the word count to account for the last word in the sentence

    // translate the C Cat Language sentence to English
    for (int i = 0; i < strlen(ccat_sentence);)
    {
        if (ccat_sentence[i] == 'M')
        {
            printf("Meow");
            i += 3; // skip over the 'M' and two following 'eo'
        }
        else if (ccat_sentence[i] == 'C')
        {
            printf("Hello");
            i += 3; // skip over the 'C' and two following 'at'
        }
        else if (ccat_sentence[i] == 'L')
        {
            printf("Bye");
            i += 2; // skip over the 'L' and following 'ick'
        }
        else
        {
            printf("%c", ccat_sentence[i]);
            i++;
        }
    }

    // count the number of words in the English translation
    for (int i = 0; i < strlen(english_sentence); i++)
    {
        if (english_sentence[i] == ' ')
        {
            english_word_count++;
        }
    }
    english_word_count++; // add 1 to the word count to account for the last word in the sentence

    // calculate the ratio of words in the C Cat Language sentence to words in the English translation
    float word_ratio = (float)ccat_word_count / (float)english_word_count;

    // print out the statistics of the C Cat Language sentence
    printf("\n\nC Cat Language Statistics:\n");
    printf("Number of words: %d\n", ccat_word_count);
    printf("Number of meows: %d\n", ccat_meow_count);

    // print out the statistics of the English translation
    printf("\nEnglish Translation Statistics:\n");
    printf("Number of words: %d\n", english_word_count);

    // print out the ratio of words in the C Cat Language sentence to words in the English translation
    printf("\nRatio of C Cat Language words to English words: %.2f\n", word_ratio);

    return 0;
}