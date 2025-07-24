//FormAI DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sentence[1000];
    char word[50];
    int count = 0;
    int sentence_length;

    // ask the user for input
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    // get the length of the sentence
    sentence_length = strlen(sentence);

    // ask the user for a word to search for
    printf("Enter a word to search for: ");
    scanf("%s", word);

    // loop through the sentence looking for the word
    for (int i = 0; i < sentence_length; i++) {
        if (sentence[i] == ' ') {
            char* temp = (char*)malloc(50 * sizeof(char));
            int j = i-count;
            int k = 0;
            while (j < i) {
                temp[k] = sentence[j];
                j++;
                k++;
            }
            temp[k] = '\0';
            if (strcmp(temp, word) == 0) {
                printf("The word '%s' is in the sentence.\n", word);
                return 0;
            }
            count = 0;
            free(temp);
        }
        else {
            count++;
        }
    }

    printf("The word '%s' is not in the sentence.\n", word);
    return 0;
}