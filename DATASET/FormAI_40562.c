//FormAI DATASET v1.0 Category: Word Count Tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100 //maximum size of a word
#define MAX_LINE_SIZE 200 //maximum size of a line

void count_words(FILE *fp) {
    char line[MAX_LINE_SIZE], word[MAX_WORD_SIZE];
    int count = 0, i, j;

    while (fgets(line, MAX_LINE_SIZE, fp)) { //loop through each line in the file
        i = 0;
        while (line[i]) { //loop through each character in the line

            while (isspace(line[i])) //skip any white space
                i++;

            j = 0;
            while (line[i] && !isspace(line[i])) { //loop through each character in the word
                word[j++] = line[i++];
            }
            word[j] = '\0'; //terminate the word string

            if (j > 0) //if we have a non-empty word
                count++;
        }
    }

    printf("The number of words in the file is: %d\n", count);
}

int main(int argc, char *argv[]) {
    if (argc != 2) { //make sure we have the correct number of arguments
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) { //make sure the file opens correctly
        printf("Error opening file\n");
        exit(1);
    }

    count_words(fp);

    fclose(fp);
    return 0;
}