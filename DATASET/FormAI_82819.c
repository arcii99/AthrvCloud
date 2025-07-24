//FormAI DATASET v1.0 Category: Text processing ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* This program reads a text file, reverses the order of characters in each line,
 * and prints the modified data to standard output.
 */

#define MAX_LINE_LENGTH 1024

/* Function prototype */
void reverse_string(char * str);

/* Main program */
int main(int argc, char * argv[]) {

    char line[MAX_LINE_LENGTH];
    FILE * fp;

    if (argc < 2) {
        printf("usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        reverse_string(line);
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}

/* Reverse a string by swapping the characters in place */
void reverse_string(char * str) {
    int i = 0;
    int j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}