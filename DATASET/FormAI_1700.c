//FormAI DATASET v1.0 Category: Word Count Tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: word_count [filename]\n");
        exit(EXIT_FAILURE);
    }
    
    FILE *fp;
    char *filename = argv[1];
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    
    char buffer[BUFF_SIZE];
    int word_count = 0;
    int character_count = 0;
    int line_count = 0;
    int in_word = 0;
    
    while (fgets(buffer, BUFF_SIZE, fp) != NULL) {
        line_count++;
        for (int i = 0; buffer[i]; i++) {
            character_count++;
            if (isspace(buffer[i])) {
                in_word = 0;
            } else if (!in_word) {
                in_word = 1;
                word_count++;
            }
        }
    }
    
    fclose(fp);
    
    printf("Word count: %d\n", word_count);
    printf("Character count: %d\n", character_count);
    printf("Line count: %d\n", line_count);
    
    return 0;
}