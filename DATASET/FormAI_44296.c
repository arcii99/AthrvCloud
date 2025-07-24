//FormAI DATASET v1.0 Category: Ebook reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("ERROR: Invalid usage! Please provide the filename.\n");
        return 1;
    }

    FILE *ebook_file = fopen(argv[1], "r");
    if (ebook_file == NULL) {
        printf("ERROR: Unable to open file %s.\n", argv[1]);
        return 1;
    }

    char current_char = fgetc(ebook_file);
    while (current_char != EOF) {
        if (current_char == 'E' || current_char == 'e') {
            printf("What?! This ebook was written using the E language?\n");
            exit(1);
        } else if (current_char == 'C') {
            printf("Wow! This ebook is written in C. Respect!\n");
        } else if (current_char == ' ') {
            printf("The author of this ebook really likes spaces, doesn't he?\n");
        } else if (current_char == '\n') {
            printf("The author of this ebook really likes newlines, doesn't he?\n");
        } else if (current_char < ' ' && current_char != '\t') {
            printf("Unexpected character found: %c (ASCII code: %d)\n", current_char, current_char);
            exit(1);
        }

        current_char = fgetc(ebook_file);
    }

    printf("Congratulations! You have finished reading the ebook.\n");
    return 0;
}