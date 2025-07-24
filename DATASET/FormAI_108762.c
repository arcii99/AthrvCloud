//FormAI DATASET v1.0 Category: Word Count Tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100

int main() {
    char file_name[100], search_word[100];
    int count = 0;

    // get file name and word to search
    printf("Enter file name: ");
    fgets(file_name, sizeof(file_name), stdin);
    file_name[strcspn(file_name, "\n")] = '\0'; // remove trailing newline
    printf("Enter word to search: ");
    fgets(search_word, sizeof(search_word), stdin);
    search_word[strcspn(search_word, "\n")] = '\0'; // remove trailing newline

    // open file
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // loop through each line in file
    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), fp)) {
        char *word_ptr = strstr(line, search_word); // pointer to first occurrence of search word in line
        while (word_ptr != NULL) {
            count++; // increment count
            word_ptr = strstr(word_ptr + 1, search_word); // search for next occurrence of search word in line
        }
    }

    printf("Word '%s' appears %d times in file '%s'.\n", search_word, count, file_name);

    // close file
    fclose(fp);

    return 0;
}