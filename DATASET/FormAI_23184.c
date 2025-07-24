//FormAI DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_LINE_LEN 500

char dictionary[][MAX_WORD_LEN] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};

int compare(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

int main() {
    int num_words = sizeof(dictionary) / sizeof(dictionary[0]);
    qsort(dictionary, num_words, sizeof(char[MAX_WORD_LEN]), compare);

    char line[MAX_LINE_LEN], word[MAX_WORD_LEN];
    printf("Enter a sentence to spell check: ");
    fgets(line, MAX_LINE_LEN, stdin);

    char *pch = strtok(line, " \n\t");
    while (pch) {
        int len = strlen(pch);
        if (len > MAX_WORD_LEN) {
            printf("The word \"%s\" is too long\n", pch);
        } else {
            for (int i = 0; i < len; i++) {
                pch[i] = tolower(pch[i]);
            }
            if (bsearch(pch, dictionary, num_words, sizeof(char[MAX_WORD_LEN]), compare)) {
                printf("%s is spelled correctly!\n", pch);
            } else {
                printf("Did you mean ");
                for (int i = 0; i < num_words; i++) {
                    int cmp = strcmp(pch, dictionary[i]);
                    if (cmp < 0) {
                        int j = i - 1;
                        while (j >= 0 && strncmp(pch, dictionary[j], len) == 0) {
                            printf("%s ", dictionary[j]);
                            j--;
                        }
                        printf("%s", dictionary[i]);
                        break;
                    } else if (cmp == 0) {
                        printf("%s is spelled correctly!", pch);
                        break;
                    }
                }
                printf("?\n");
            }
        }
        pch = strtok(NULL, " \n\t");
    }

    return 0;
}