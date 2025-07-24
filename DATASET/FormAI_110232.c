//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    FILE *fp;
    char ch, prev_char = '\0';
    int count = 0, word_count = 0, line_count = 0;
    if(argc != 2){
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Cannot open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    while((ch = fgetc(fp)) != EOF){
        count++;
        if(ch == '\n'){
            line_count++;
        }
        if(!isspace(ch) && (isspace(prev_char) || prev_char == '\0')){
            word_count++;
        }
        prev_char = ch;
    }
    fclose(fp);
    printf("Number of characters in %s: %d\n", argv[1], count);
    printf("Number of words in %s: %d\n", argv[1], word_count);
    printf("Number of lines in %s: %d\n", argv[1], line_count);
    return EXIT_SUCCESS;
}