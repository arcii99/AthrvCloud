//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

int main(void){
    char word[MAX_WORD_LENGTH];
    char c;
    int count = 0, uniqueCount = 0;

    int frequency[26]; // frequency of each letter in the alphabet

    int i;
    for (i = 0; i < 26; i++){
        frequency[i] = 0;
    }

    printf("Enter text (type Ctrl-D to exit):\n");

    while ((c = getchar()) != EOF){
        // check if character is a letter
        if (isalpha(c)){
            // convert letter to lowercase
            c = tolower(c);

            // add letter to current word
            word[count] = c;
            count++;

            // check if current word is too long
            if (count > MAX_WORD_LENGTH){
                fprintf(stderr, "Error: Word too long.\n");
                exit(EXIT_FAILURE);
            }
        }
        // check if current word is complete
        else if (count > 0){
            // add null terminator to word
            word[count] = '\0';

            // increase frequency count of each letter in word
            int j;
            for (j = 0; j < strlen(word); j++){
                frequency[word[j] - 'a']++;
            }

            // print word and frequency count
            printf("%s: %d\n", word, frequency[word[0] - 'a']);

            // reset count and word array
            count = 0;
            memset(word, 0, sizeof(word));

            // increase count of unique words
            uniqueCount++;
        }
    }

    printf("Number of unique words: %d\n", uniqueCount);

    return 0;
}