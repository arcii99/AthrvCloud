//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} word_struct;

word_struct words[MAX_WORDS];

void process_word(const char* word) {
    int i;
    
    /* Convert to lowercase */
    char lowercase_word[MAX_WORD_LENGTH];
    for(i = 0; i < strlen(word); i++) {
        lowercase_word[i] = tolower(word[i]);
    }
    lowercase_word[i] = '\0';
    
    /* Check if word already exists in the array */
    for(i = 0; i < MAX_WORDS; i++) {
        if(strcmp(words[i].word, lowercase_word) == 0) {
            words[i].frequency++;
            return;
        }
    }
    
    /* If the word does not exist, add it to the array */
    for(i = 0; i < MAX_WORDS; i++) {
        if(words[i].frequency == 0) {
            strcpy(words[i].word, lowercase_word);
            words[i].frequency = 1;
            return;
        }
    }
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }
    
    FILE* fp;
    char ch;
    char word[MAX_WORD_LENGTH] = {0};
    int i = 0;
    
    /* Open file */
    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 0;
    }
    
    /* Read in file character by character */
    while((ch = fgetc(fp)) != EOF) {
        if(isalpha(ch)) {
            word[i++] = ch;
        }
        else if(i != 0) {
            word[i] = '\0';
            process_word(word);
            i = 0;
        }
    }
    
    /* Finish processing last word in file */
    if(i != 0) {
        word[i] = '\0';
        process_word(word);
    }
    
    /* Close file */
    fclose(fp);
    
    /* Output frequency of each word */
    for(i = 0; i < MAX_WORDS; i++) {
        if(words[i].frequency != 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
    
    return 0;
}