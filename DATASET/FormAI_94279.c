//FormAI DATASET v1.0 Category: Word Count Tool ; Style: future-proof
/*
 * This program implements a C word count tool. It reads a text file 
 * and counts the number of words in it. The program takes one 
 * argument, which is the filename of the text file.
 */

#include <stdio.h>
#include <ctype.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

/* function to count number of words in a file */
int word_count_file(char *file_name)
{
    FILE *fp;
    char c;
    int state = OUT, words = 0;

    /* open the file */
    fp = fopen(file_name, "r");

    /* check if the file was opened successfully */
    if (fp == NULL) {
        printf("Could not open file %s\n", file_name);
        return -1;
    }

    /* read the file character by character */
    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c)) {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            words++;
        }
    }

    /* close the file */
    fclose(fp);

    return words;
}

/* example usage of the word_count_file function */
int main(int argc, char *argv[])
{
    /* check if a filename was provided */
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    /* count the number of words in the file */
    int word_count = word_count_file(argv[1]);

    /* print the result */
    printf("Number of words in file %s: %d\n", argv[1], word_count);

    return 0;
}