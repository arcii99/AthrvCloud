//FormAI DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Forward declarations */
char *lowercase(char *);
int is_valid_word(char *);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    /* Open the file */
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }

    /* Allocate memory for the buffer */
    size_t bufsize = 1024;
    char *buffer = malloc(sizeof(char) * bufsize);

    /* Read each line of the file*/
    while (getline(&buffer, &bufsize, fp) != -1) {
        char *token = strtok(buffer, " \n");

        /* Loop through each word in the line */
        while (token != NULL) {
            char *word = lowercase(token);

            /* Check if the word is valid */
            if (!is_valid_word(word)) {
                printf("%s is not a valid word.\n", token);
            }

            /* Get the next word */
            token = strtok(NULL, " \n");
        }
    }

    /* Free the memory */
    free(buffer);

    /* Close the file */
    fclose(fp);

    return 0;
}

/* Convert a string to lowercase */
char *lowercase(char *str) {
    int len = strlen(str);
    char *newstr = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++) {
        newstr[i] = tolower(str[i]);
    }

    newstr[len] = '\0';

    return newstr;
}

/* Check if a word is valid */
int is_valid_word(char *word) {
    /* TODO: Implement a dictionary lookup to check if the word is valid */
    /* For now, just return true so that all words are considered valid */
    return 1;
}