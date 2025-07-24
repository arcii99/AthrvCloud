//FormAI DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_STRING_LENGTH 1000

int main() {

    char file_name[MAX_FILE_NAME_LENGTH];
    char text[MAX_STRING_LENGTH];
    char search_word[MAX_STRING_LENGTH];

    printf("Enter the file name: ");
    scanf("%s", file_name);

    printf("Enter the word to search for: ");
    scanf("%s", search_word);

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return EXIT_FAILURE;
    }

    printf("Searching for occurrences of the word '%s'...\n", search_word);

    while (fgets(text, MAX_STRING_LENGTH, file) != NULL) {

        size_t len = strlen(text);
        if (len > 0 && text[len - 1] == '\n') {
            text[len - 1] = '\0';
        }

        char *ptr = strstr(text, search_word);

        if (ptr != NULL) {
            printf("Found occurrence of the word '%s' in the following text:\n", search_word);
            printf("%s\n", text);
        }

    }

    fclose(file);

    return EXIT_SUCCESS;

}