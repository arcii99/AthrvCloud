//FormAI DATASET v1.0 Category: Word Count Tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Please provide a file name.\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Unable to open the file.\n");
        return 1;
    }

    char *word;
    size_t length = 0;
    ssize_t read;

    int count = 0;
    while ((read = getline(&word, &length, file)) != -1) {
        char *token = strtok(word, " \t\n\r");
        while (token != NULL) {
            count++;
            token = strtok(NULL, " \t\n\r");
        }
    }

    printf("Total words in the file '%s': %d\n", argv[1], count);
    fclose(file);
    return 0;
}