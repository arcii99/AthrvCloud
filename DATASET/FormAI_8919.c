//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: safe
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void count_word_frequency(char []);

int main() {
    char string[MAX_SIZE];
    printf("Enter a string (max length 100): ");
    fgets(string, MAX_SIZE, stdin);
    count_word_frequency(string);
    return 0;
}

void count_word_frequency(char string[]) {
    int words = 0, letters = 0, i, j, k, word_count[MAX_SIZE] = {0};
    char word[MAX_SIZE];

    for(i = 0; string[i] != '\0'; i++) {
        //If a character is not an alphabet it is assumed to be a separator between words
        if(isalpha(string[i])) {
            word[letters] = string[i];
            letters++;
        } else {
            if(letters > 0) {
                word[letters] = '\0';
                words++;

                //Convert the word to lowercase
                for(k = 0; word[k] != '\0'; k++) {
                    word[k] = tolower(word[k]);
                }

                for(j = 0; j < words; j++) {
                    if(strcmp(word, &string[word_count[j]]) == 0) {
                        break;
                    }
                }

                //If the word already exists increment its count
                if(j < words) {
                    word_count[j]++;
                } else {
                    word_count[words] = letters + word_count[words - 1] + 1;
                    words++;
                }

                letters = 0;
            }
        }
    }

    printf("Word\t\tFrequency\n");
    for(i = 0; i < words; i++) {
        printf("%-14s%d\n", &string[word_count[i]], word_count[i+1] - word_count[i] - 1);
    }
}