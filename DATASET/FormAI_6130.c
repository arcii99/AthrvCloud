//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_RESUME_LINES 1000
#define MAX_WORD_LENGTH 50
#define MAX_WORDS_PER_LINE 10

int main(int argc, char *argv[]) {
    FILE *file_ptr;
    char line[MAX_LINE_LENGTH];
    char resume[MAX_RESUME_LINES][MAX_LINE_LENGTH];
    char *words[MAX_WORDS_PER_LINE];
    int i, j, num_lines = 0, num_words = 0;

    if (argc != 2) {
        printf("Usage: %s resume.txt\n", argv[0]);
        exit(1);
    }

    file_ptr = fopen(argv[1], "r");
    if (file_ptr == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file_ptr) != NULL) {
        strcpy(resume[num_lines], line);
        num_lines++;
    }

    fclose(file_ptr);

    for (i = 0; i < num_lines; i++) {
        num_words = 0;
        words[num_words] = strtok(resume[i], " ");
        while (words[num_words] != NULL) {
            num_words++;
            words[num_words] = strtok(NULL, " ");
        }

        printf("Line %d contains %d word(s):\n", i+1, num_words);
        for (j = 0; j < num_words; j++) {
            printf("%s\n", words[j]);
        }
        printf("\n");
    }

    return 0;
}