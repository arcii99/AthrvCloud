//FormAI DATASET v1.0 Category: Text processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LEN 100    //maximum word length
#define MAX_LINE_LEN 1000   //maximum line length

int main(int argc, char* argv[])
{
    FILE* fp;
    char* file_name;
    char line[MAX_LINE_LEN];
    char word[MAX_WORD_LEN];
    int num_lines = 0, num_words = 0, num_chars = 0;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    file_name = argv[1];

    if ((fp = fopen(file_name, "r")) == NULL) {
        printf("Cannot open file: %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        num_lines++;
        int i = 0;
        while (line[i] != '\n' && line[i] != '\0') {
            if (isspace(line[i])) {
                num_words++;
            }
            else {
                num_chars++;
            }
            i++;
        }
        num_words++;    //counting the last word in line
    }

    printf("Number of lines: %d\n", num_lines);
    printf("Number of words: %d\n", num_words);
    printf("Number of characters: %d\n", num_chars);

    fclose(fp);
    return 0;
}