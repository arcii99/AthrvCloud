//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_SENTENCES 50

int main(int argc, char *argv[]) {
    
    int sentence_count = 0;

    if (argc < 2) {
        printf("Please provide a file name as an argument\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file '%s'\n", filename);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    char *sentences[MAX_SENTENCES];

    while(fgets(buffer, BUFFER_SIZE, fp)) {
        char *token = strtok(buffer, ".");
        while (token != NULL && sentence_count < MAX_SENTENCES) {
            sentences[sentence_count++] = token;
            token = strtok(NULL, ".");
        }
    }

    printf("Summary: ");
    for (int i = 0; i < sentence_count; i++) {
        if (i == 0) {
            printf("%s.", sentences[i]);
        } else {
            char *last_word = strrchr(sentences[i - 1], ' ');
            if (last_word == NULL) {
                printf("%s.", sentences[i]);
            } else {
                printf("%s.", last_word + 1);
            }
        }
    }

    fclose(fp);
    return 0;
}