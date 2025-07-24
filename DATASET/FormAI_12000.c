//FormAI DATASET v1.0 Category: Spell checking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function that checks if a word is correctly spelled */
int is_correctly_spelled(char *word, char **dictionary, int dictionary_length) {
    int i;
    for(i=0; i<dictionary_length; i++) {
        if(strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

/* Function that performs spell checking on a text file */
void spell_check(char *file_name, char **dictionary, int dictionary_length) {
    FILE *file_pointer = fopen(file_name, "r");
    if(file_pointer == NULL) {
        printf("Could not open file %s\n", file_name);
        return;
    }
    int line_number = 1;
    char line[1000];
    while(fgets(line, 1000, file_pointer) != NULL) {
        char *word = strtok(line, " \t\n\r");
        while(word != NULL) {
            if(!is_correctly_spelled(word, dictionary, dictionary_length)) {
                printf("Line %d: %s is misspelled!\n", line_number, word);
            }
            word = strtok(NULL, " \t\n\r");
        }
        line_number++;
    }
    fclose(file_pointer);
}

/* Sample usage */
int main() {
    char *dictionary[] = {"apple", "banana", "orange", "kiwi", "peach"};
    int dictionary_length = 5;
    spell_check("text.txt", dictionary, dictionary_length);
    return 0;
}