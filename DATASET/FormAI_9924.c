//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char *DEFAULT_CHARS = "#@$%&*o!;:. ";
int DEFAULT_CHAR_COUNT = 10;

// function to generate and print ASCII art
void generate_art(char *text, int char_count, char *chars, int row_count, int col_count) {
    int text_len = strlen(text);
    char art[row_count][col_count+1];

    srand(time(NULL)); // initialize random seed

    // initialize art array with spaces
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < col_count+1; j++) {
            art[i][j] = ' ';
        }
    }

    // print text in center of art array
    int start_col = (col_count - text_len * char_count) / 2;
    for (int i = 0; i < text_len; i++) {
        int char_index = rand() % char_count;
        for (int j = 0; j < char_count; j++) {
            if (j == char_index) {
                for (int k = 0; k < row_count; k++) {
                    art[k][start_col+j+i*char_count] = chars[j % strlen(chars)];
                }
            }
        }
    }

    // print art array
    for (int i = 0; i < row_count; i++) {
        printf("%s\n", art[i]);
    }
}

int main() {
    printf("Welcome to ASCII art generator!\n");
    printf("Enter your text: ");

    char text[100];
    fgets(text, 100, stdin);
    strtok(text, "\n"); // remove trailing newline from text

    printf("Enter number of characters per letter (default is 10): ");

    char char_count_str[10];
    fgets(char_count_str, 10, stdin);
    int char_count = atoi(char_count_str);
    if (char_count <= 0) {
        char_count = DEFAULT_CHAR_COUNT;
    }

    printf("Enter characters to use (default is \"#@$%&*o!;:. \"): ");

    char chars[100];
    fgets(chars, 100, stdin);
    strtok(chars, "\n"); // remove trailing newline from chars
    if (strlen(chars) == 0) {
        strcpy(chars, DEFAULT_CHARS);
    }

    printf("Enter number of rows in art (default is 10): ");

    char row_count_str[10];
    fgets(row_count_str, 10, stdin);
    int row_count = atoi(row_count_str);
    if (row_count <= 0) {
        row_count = 10;
    }

    int text_len = strlen(text);
    int col_count = text_len * char_count;

    generate_art(text, char_count, chars, row_count, col_count);

    return 0;
}