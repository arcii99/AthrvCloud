//FormAI DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char *word = NULL;
    size_t wordlen = 0;
    ssize_t linelen;
    int wordcount = 0;

    while((linelen = getline(&word, &wordlen, fp)) != -1) {
        char *ptr = word;
        while(*ptr != '\0') {
            if(isalpha(*ptr)) {
                wordcount++;
                while(isalpha(*ptr))
                    ptr++;
            } else {
                ptr++;
            }
        }
    }

    printf("Number of words in %s: %d\n", argv[1], wordcount);

    fclose(fp);
    free(word);
    return 0;
}