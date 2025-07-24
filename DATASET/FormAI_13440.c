//FormAI DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 1000

int main(int argc, char *argv[]) {
    FILE *fp;
    char *filename;
    char words[MAX_WORD_COUNT][MAX_WORD_LENGTH];
    int frequency[MAX_WORD_COUNT] = {0};
    int count = 0;
    int i, j;

    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];

    if((fp = fopen(filename, "r")) == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char c, word[MAX_WORD_LENGTH];
    int word_len = 0, index;

    while((c = fgetc(fp)) != EOF) {
        if(isalnum(c)) {
            word[word_len++] = tolower(c);
        } else if(word_len > 0) {
            word[word_len] = '\0';
            index = -1;
            for(i = 0; i < count; i++) {
                if(strcmp(words[i], word) == 0) {
                    index = i;
                    break;
                }
            }
            if(index == -1) {
                strcpy(words[count], word);
                frequency[count]++;
                count++;
            } else {
                frequency[index]++;
            }
            word_len = 0;
        }
    }

    fclose(fp);

    printf("Word Count Statistics\n");
    printf("---------------------\n");

    for (i = 0; i < count; i++) {
        printf("%s : %d\n", words[i], frequency[i]);
    }

    return 0;
}