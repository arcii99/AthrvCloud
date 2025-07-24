//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char buffer[1024];
    FILE *input_file;
    char *word, *result;
    int i, frequency = 0, num_chars = 0, num_words = 0;

    input_file = fopen("input_file.txt", "r");

    if (input_file == NULL) {
        fprintf(stderr, "Error! Could not open file\n");
        exit(-1);
    }

   // reading the input file
    while (fgets(buffer, sizeof(buffer), input_file)) {

        // counting the number of characters
        num_chars += strlen(buffer);

        // counting the number of words
        char* token = strtok(buffer, " \n");
        while (token != NULL)
        {
            num_words++;
            token = strtok(NULL, " \n");
        }

        // removing punctuations and converting to lowercase
        char *p = buffer;
        while (*p) {
            if (ispunct(*p))
            {
                memmove(p, p + 1, strlen(p + 1) + 1);
            }
            else
            {
                *p = tolower(*p);
            }
            p++;
        }

        // counting the frequency of each word
        word = strtok(buffer, " \n");
        while (word != NULL) {
            result = strstr(buffer, word);
            frequency = 0;
            while (result != NULL) {
                frequency++;
                result = strstr(result + 1, word);
            }
            printf("%s %d\n", word, frequency);
            word = strtok(NULL, " \n");
        }
    }

    printf("\nTotal number of chars = %d\nTotal number of words = %d\n", num_chars, num_words);

    fclose(input_file);

    return 0;
}