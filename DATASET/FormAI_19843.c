//FormAI DATASET v1.0 Category: Word Count Tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please provide a file name as argument\n");
        exit(EXIT_FAILURE);
    }
    FILE *fileptr;
    if ((fileptr = fopen(argv[1], "rb")) == NULL) {
        printf("Unable to open file\n");
        exit(EXIT_FAILURE);
    }
    char *word = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;
    while ((read = getline(&word, &len, fileptr)) != -1) {
        for(int i = 0; i < strlen(word); i++) {
            if(isspace(word[i])) {
                if(i != 0 && !isspace(word[i-1])) {
                    count++;
                }
            }
        }
        if(!isspace(word[strlen(word) - 1])) {
            count++;
        }
    }
    printf("Word count in %s : %d\n", argv[1], count);
    free(word);
    return 0;
}