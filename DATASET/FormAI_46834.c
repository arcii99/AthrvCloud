//FormAI DATASET v1.0 Category: Text Summarizer ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct word_freq {
    char *word;
    int freq;
};

char *remove_punctuations(char *str) {
    char *new_str = (char*) malloc(strlen(str) + 1);
    int j = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (!ispunct(str[i])) {
            new_str[j++] = tolower(str[i]);
        }
    }

    new_str[j] = '\0';
    return new_str;
}

int compare(struct word_freq *wf1, struct word_freq *wf2) {
    if (wf1->freq < wf2->freq) {
        return 1;
    } else if (wf1->freq > wf2->freq) {
        return -1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    char line[100];
    int num_words = 0, word_count = 0;
    char *word;

    struct word_freq *words = (struct word_freq*) malloc(sizeof(struct word_freq));

    while (fgets(line, 100, fp)) {
        char *token = strtok(line, " ");
        while (token != NULL) {
            word_count++;
            word = remove_punctuations(token);

            int found = 0;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].freq++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                words = (struct word_freq*) realloc(words, (num_words + 1) * sizeof(struct word_freq));
                words[num_words].word = word;
                words[num_words].freq = 1;
                num_words++;
            }

            token = strtok(NULL, " ");
        }
    }

    qsort(words, num_words, sizeof(struct word_freq), (__compar_fn_t) compare);

    printf("The 10 most used words in the text are:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s: %d\n", i + 1, words[i].word, words[i].freq);
    }

    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }
    free(words);

    fclose(fp);

    return 0;
}