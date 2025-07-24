//FormAI DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Function to remove trailing spaces
void rtrim(char *str) {
    int i;
    for(i = strlen(str) - 1; i >= 0 && isspace(str[i]); i--);
    str[i+1] = '\0';
}

//Function to remove leading spaces
void ltrim(char *str) {
    int i;
    for(i = 0; isspace(str[i]); i++);
    memmove(str, str+i, strlen(str) - i + 1);
}

//Function to check if a word is spelled correctly
int check_word(char *dict_file, char *word) {
    char line[1000];
    int len = strlen(word);
    int i;

    FILE *f = fopen(dict_file, "r");
    if(f == NULL) {
        printf("Cannot open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    while(fgets(line, 1000, f)) {
        rtrim(line);
        ltrim(line);
        if(strlen(line) != len)
            continue;
        for(i = 0; i < len; i++) {
            if(tolower(line[i]) != tolower(word[i]))
                break;
        }
        if(i == len) {
            return 1; //Word is spelled correctly
        }
    }
    fclose(f);
    return 0; //Word is spelled incorrectly
}

int main() {
    char dict_file[100] = "dictionary.txt"; //Dictionary file, with one word per line
    char input[1000];
    char *ptr;
    int i;

    printf("Enter text to check spelling:\n");
    if(fgets(input, 1000, stdin) == NULL || strlen(input) <= 1) {
        printf("No input provided.\n");
        return 1;
    }

    ptr = strtok(input, " ,.!?\n");
    while(ptr != NULL) {
        if(!check_word(dict_file, ptr)) {
            printf("%s is misspelled.\n", ptr);
        }
        ptr = strtok(NULL, " ,.!?\n");
    }
    return 0;
}