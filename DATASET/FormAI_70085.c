//FormAI DATASET v1.0 Category: Data mining ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed ante dui, semper sit amet maximus vel, vehicula non tellus. Sed varius vestibulum sodales. Duis sed gravida elit. Curabitur convallis felis est, nec sollicitudin turpis eleifend vel. Nullam ut sollicitudin enim. Phasellus vel viverra lectus. Curabitur ac lectus fermentum, pulvinar odio vel, iaculis eros. Nunc vel ipsum ac elit tincidunt egestas in vel eros. Nullam mattis dui vel vestibulum laoreet. Sed sit amet mauris eu mauris vulputate condimentum. Vestibulum eu augue mattis, varius nisl in, lobortis lorem.";

    // tokenize input into words
    char* words[100];
    int num_words = 0;
    char* token = strtok(input, " ,.");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ,.");
    }

    // create frequency table for each unique word
    struct word_freq {
        char* word;
        int freq;
    };
    struct word_freq word_freqs[100];
    int num_word_freqs = 0;

    for (int i = 0; i < num_words; i++) {
        int found = 0;
        for (int j = 0; j < num_word_freqs; j++) {
            if (strcmp(words[i], word_freqs[j].word) == 0) {
                word_freqs[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            word_freqs[num_word_freqs].word = words[i];
            word_freqs[num_word_freqs].freq = 1;
            num_word_freqs++;
        }
    }

    // print frequency table
    printf("WORD\tFREQUENCY\n");
    for (int i = 0; i < num_word_freqs; i++) {
        printf("%s\t%d\n", word_freqs[i].word, word_freqs[i].freq);
    }

    return 0;
}