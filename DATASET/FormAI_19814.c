//FormAI DATASET v1.0 Category: Word Count Tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];

    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open %s for reading\n", filename);
        exit(1);
    }

    char buf[1024];
    int num_words = 0;
    int total_words = 0;
    int max_words = 0;

    static int word_count[MAX_WORDS];

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        char* p = buf;

        while (*p != '\0') {
            if (isalnum(*p)) {
                num_words++;
            }
            else {
                if (num_words > 0) {
                    total_words++;
                    word_count[num_words-1]++;
                    if (num_words > max_words) {
                        max_words = num_words;
                    }
                    num_words = 0;
                }
            }
            p++;
        }
    }

    printf("Word Count Results\n");
    printf("==================\n\n");
    printf("%-15s %10s %10s\n", "Word Length", "Count", "Percent");

    int i;
    for (i=0; i<max_words; i++) {
        if (word_count[i] > 0) {
            printf("%-15d %10d %10.2f%%\n", i+1, word_count[i], ((float)word_count[i] / total_words) * 100);
        }
    }

    printf("\nTotal Words: %d\n", total_words);

    fclose(fp);

    return 0;
}