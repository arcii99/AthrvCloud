//FormAI DATASET v1.0 Category: Spell checking ; Style: ultraprecise
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 1000

void tokenize(char* str, char* tokens[]);
int isMisspelled(char* token);
void clearBuffer(char* buffer);
void printSuggestions(char* token);

int main() {
    char sentence[SIZE];
    char* tokens[SIZE/2] = {NULL};
    fgets(sentence, SIZE-1, stdin);
    
    // Tokenize sentence into separate words
    tokenize(sentence, tokens);
    
    // Check each word for spelling errors
    for(int i = 0; tokens[i]; i++) {
        if(isMisspelled(tokens[i])) {
            printf("Misspelled: %s\n", tokens[i]);
            printSuggestions(tokens[i]);
        }
    }
    
    return 0;
}

// Tokenize the input string into separate words
void tokenize(char* str, char* tokens[]) {
    char* token = strtok(str, " \n\r\t");
    int i = 0;
    while(token) {
        tokens[i++] = token;
        token = strtok(NULL, " \n\r\t");
    }
}

// Check if a given word is misspelled
int isMisspelled(char* token) {
    int len = strlen(token);
    char buffer[len+1];
    char c;
    int i = 0;
    while((c = *token++) != '\0') {
        if(isalpha(c)) {
            buffer[i++] = tolower(c);
        }
    }
    buffer[i] = '\0';
    return strcmp(buffer, "cspell") != 0;
}

// Clear the contents of a char buffer
void clearBuffer(char* buffer) {
    for(int i = 0; i < SIZE; i++) {
        buffer[i] = '\0';
    }
}

// Print suggestions for misspelled word
void printSuggestions(char* token) {
    printf("Suggestions for correction:\n");
    printf("- check\n");
    printf("- spell\n");
    printf("- correct\n");
}