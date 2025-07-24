//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20
#define MAX_CHARS 256

void print_ascii_art(char c);

char ascii_art[MAX_CHARS][MAX_HEIGHT][MAX_WIDTH+1];

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[64];
    char ch;
    int i, j, k;
    int c = 0;

    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Unable to open file %s\n", argv[1]);
        exit(-1);
    }

    /* Read ascii art from file */
    while(!feof(fp) && c != MAX_CHARS) {
        for(i = 0; i < MAX_HEIGHT; i++) {
            for(j = 0; j < MAX_WIDTH+1; j++) {
                ch = fgetc(fp);
                if(ch == '\n' || ch == EOF) {
                    ascii_art[c][i][j] = '\0';
                    break;
                }
                ascii_art[c][i][j] = ch;
            }
            if(ch == EOF) {
                break;
            }
        }
        c++;
    }
    fclose(fp);

    /* Print ASCII art for each character */
    for(k = 0; k < MAX_CHARS; k++) {
        printf("ASCII Art for character %c:\n\n", k);
        print_ascii_art(k);
        printf("\n\n");
    }

    return 0;
}

/**
 * Prints ASCII art for a given character
 * If no ASCII art is available for the given character,
 * a blank space is printed instead.
 */
void print_ascii_art(char c) {
    int i, j;
    int found = 0;

    for(i = 0; i < MAX_HEIGHT; i++) {
        for(j = 0; j < MAX_WIDTH && ascii_art[c][i][j] != '\0'; j++) {
            if(ascii_art[c][i][j] != ' ') {
                found = 1;
                break;
            }
        }
        if(found) {
            break;
        }
    }

    if(found) {
        for(; i < MAX_HEIGHT; i++) {
            for(j = 0; j < MAX_WIDTH && ascii_art[c][i][j] != '\0'; j++) {
                putchar(ascii_art[c][i][j]);
            }
            putchar('\n');
        }
    } else {
        putchar(' ');
    }
}