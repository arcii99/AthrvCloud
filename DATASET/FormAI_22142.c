//FormAI DATASET v1.0 Category: Word Count Tool ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* get_file_contents(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);
    char* file_contents = malloc((file_size+1)*sizeof(char));
    fread(file_contents, sizeof(char), file_size, fp);
    fclose(fp);
    file_contents[file_size] = '\0';
    return file_contents;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char* file_contents = get_file_contents(argv[1]);
    printf("File Contents:\n\n%s\n", file_contents);

    char* delimiter = " .,;:?!\n\t";
    char* word;
    int word_count = 0;
    word = strtok(file_contents, delimiter);
    while (word != NULL) {
        word_count++;
        printf("%d: %s\n", word_count, word);
        word = strtok(NULL, delimiter);
    }

    printf("\n\nTotal Words: %d\n", word_count);

    free(file_contents);
    return 0;
}