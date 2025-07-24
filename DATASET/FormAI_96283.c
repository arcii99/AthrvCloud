//FormAI DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICT_SIZE 1000
#define WORD_LENGTH 50

int load_dictionary(const char* filename, char dictionary[][WORD_LENGTH]);
int check_spelling(char text[], char dictionary[][WORD_LENGTH], int dict_size);

int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Usage: %s [dictionary file] [text file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char dictionary[DICT_SIZE][WORD_LENGTH];
    int dict_size = load_dictionary(argv[1], dictionary);

    FILE *fp = fopen(argv[2], "r");
    if(fp == NULL) {
        printf("Error opening text file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    char line[1024];
    char *p, *word_start, *word_end;

    int line_num = 0;
    while(fgets(line, sizeof(line), fp)) {
        ++line_num;
        p = line;
        while(*p) {
            word_start = NULL;
            word_end = NULL;

            while(*p && !isalpha(*p)) ++p;
            if(!*p) break;

            word_start = p;
            while(*p && isalpha(*p)) ++p;
            word_end = p - 1;

            if(word_start && word_end){
                char check_word[WORD_LENGTH];
                int word_len = word_end - word_start + 1;
                strncpy(check_word, word_start, word_len);
                check_word[word_len] = '\0';

                int result = check_spelling(check_word, dictionary, dict_size);
                if(!result) {
                    printf("Error at Line %d: %s is not in dictionary\n", line_num, check_word);
                }
            }
        }
    }

    fclose(fp);

    return 0;
}

int load_dictionary(const char* filename, char dictionary[][WORD_LENGTH]) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening dictionary file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int dict_size = 0;
    while(fgets(dictionary[dict_size], WORD_LENGTH, fp) && dict_size < DICT_SIZE) {
        char *pos;
        if((pos = strchr(dictionary[dict_size], '\n')) != NULL)
            *pos = '\0';

        ++dict_size;
    }

    fclose(fp);

    return dict_size;
}

int check_spelling(char text[], char dictionary[][WORD_LENGTH], int dict_size) {
    for(int i = 0; i < dict_size; ++i) {
        if(strcmp(text, dictionary[i]) == 0)
            return 1;
    }

    return 0;
}