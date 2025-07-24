//FormAI DATASET v1.0 Category: Spell checking ; Style: high level of detail
// Included dependencies
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Number of Lines for all word pairs list
const int LINES = 1000; 

// Number of Characters for all word pairs list
const int CHARACTERS = 100;

// Delimiter considered for word pairs list
const char DELIMITER[] = "\n";

/**
 * This function reads each line from the file
 * and stores it into the `words` array
 */
void read_words(FILE *file, char words[LINES][CHARACTERS]){
    char line[CHARACTERS];
    int i = 0;
    while(fgets(line, CHARACTERS, file) != NULL ){
        strncpy(words[i], line, strlen(line)-1);
        i++;
    }
}

/**
 * This function performs the spell checking of the
 * words in the file. It reads each word and checks
 * if the word is present in the `words` array.
 */
void spell_check(FILE *file, char words[LINES][CHARACTERS]){
    char word[CHARACTERS];
    int line_no = 0;
    while(fscanf(file, "%s", word) == 1 ){ 
        for(int i = 0; i < strlen(word); i++){
            word[i] = tolower(word[i]);
        }

        int count = 0;
        for(int i = 0; i < LINES; i++){
            if(strcmp(word, words[i]) == 0){
                count++;
            }
        }

        if(count == 0){
            printf("Line %d: '%s' is misspelled.\n", line_no, word);
        }

        line_no++;
    }
}

int main(int argc, char *argv[]){
    if(argc != 3 ){
        printf("Usage: spell_check <words_file> <input_file>\n");
        return 1;
    }

    FILE *words_file = fopen(argv[1], "r");
    if(words_file == NULL ){
        printf("Unable to open words file %s.\n", argv[1]);
        return 1;
    }

    char words[LINES][CHARACTERS];
    read_words(words_file, words);

    FILE *input_file = fopen(argv[2], "r");
    if(input_file == NULL ){
        printf("Unable to open input file %s.\n", argv[2]);
        return 1;
    }

    spell_check(input_file, words);
    fclose(input_file);

    return 0;
}