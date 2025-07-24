//FormAI DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 500

int num_lines = 0;
char buffer[MAX_LINE_LENGTH];
char lines[MAX_NUM_LINES][MAX_LINE_LENGTH];

bool is_word(char *word) {
    for(int i = 0; i < strlen(word); i++) {
        if(!isalpha(word[i])) {
            return false;
        }
    }
    return true;
}

char* to_lower(char *word) {
    char *lower_word = malloc(MAX_WORD_LENGTH * sizeof(char));
    for(int i = 0; i < strlen(word); i++) {
        lower_word[i] = tolower(word[i]);
    }
    return lower_word;
}

int find_word(char *word) {
    for(int i = 0; i < num_lines; i++) {
        char *lower_line = to_lower(lines[i]);
        char *token = strtok(lower_line, " ");
        while(token != NULL) {
            if(strcmp(token, word) == 0) {
                return i;
            }
            token = strtok(NULL, " ");
        }
    }
    return -1;
}

int main() {
    printf("Enter lines of text, up to 500 lines:\n");
    while(fgets(buffer, MAX_LINE_LENGTH, stdin) != NULL) {
        if(num_lines == MAX_NUM_LINES) {
            printf("Maximum number of lines reached.\n");
            break;
        }
        strcpy(lines[num_lines], buffer);
        num_lines++;
    }

    char word[MAX_WORD_LENGTH];
    printf("Enter a word to search for in the text:\n");
    scanf("%s", word);

    if(is_word(word)) {
        int line_num = find_word(to_lower(word));
        if(line_num == -1) {
            printf("The word '%s' was not found in the text.\n", word);
        } else {
            printf("The word '%s' was found on line %d:\n%s", word, line_num + 1, lines[line_num]);
        }
    } else {
        printf("Please enter a valid word.\n");
    }

    return 0;
}