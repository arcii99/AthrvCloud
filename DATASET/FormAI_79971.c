//FormAI DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100] = "Ye olde dragon doth spew fire upon yon castle wall";
    char word1[10], word2[10], new_sentence[100] = "";
    int i = 0, j = 0, k = 0, len = 0;

    printf("Original Sentence: %s\n", sentence);

    // Extracting the first word
    while (sentence[i] != ' ')
    {
        word1[i] = sentence[i];
        i++;
    }
    word1[i] = '\0';

    // Extracting the second word
    i++; // skipping the space
    while (sentence[i] != ' ')
    {
        word2[j] = sentence[i];
        i++;
        j++;
    }
    word2[j] = '\0';

    // Reversing the second word
    len = strlen(word2);
    for (i = len-1; i >= 0; i--)
    {
        new_sentence[k] = word2[i];
        k++;
    }

    // Inserting the first word and the reversed second word into the new sentence
    strcat(new_sentence, " ");
    strcat(new_sentence, word1);
    strcat(new_sentence, " ");
    strcat(new_sentence, word2);

    // Appending the rest of the sentence to the new sentence
    strcat(new_sentence, &sentence[strlen(word1)+strlen(word2)+2]);

    printf("New Sentence: %s\n", new_sentence);

    return 0;
}