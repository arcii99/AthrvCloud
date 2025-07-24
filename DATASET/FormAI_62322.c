//FormAI DATASET v1.0 Category: Syntax parsing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

int is_type(char* word) {
    char* keywords[] = {"int", "float", "double", "char", "short", "long", "void"};
    for(int i=0; i<7; i++) {
        if(strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_variable(char* word, int ignore_first) {
    int length = strlen(word);
    if(length == 0) {
        return 0;
    }
    for(int i=0; i<length; i++) {
        if(i == 0 && ignore_first) {
            continue;
        }
        if(!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= '0' && word[i] <= '9') || word[i] == '_')) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter C code:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    int length = strlen(input);
    char parse_results[MAX_INPUT_LENGTH];
    int num_results = 0;
    
    char current_word[MAX_INPUT_LENGTH];
    int word_length = 0;
    
    int i = 0;
    while(i < length) {
        if(input[i] == ' ') { // space
            if(word_length > 0 && is_variable(current_word, 0)) {
                parse_results[num_results++] = 'V';
            }
            word_length = 0;
        }
        else if(input[i] == ';') { // end of line
            if(word_length > 0 && is_variable(current_word, 0)) {
                parse_results[num_results++] = 'V';
            }
            parse_results[num_results++] = ';';
            word_length = 0;
        }
        else if(input[i] == '(') { // start of function call
            if(is_variable(current_word, 0)) {
                parse_results[num_results++] = 'F';
            }
            parse_results[num_results++] = '(';
            word_length = 0;
        }
        else if(input[i] == ')') { // end of function call
            if(is_variable(current_word, 0)) {
                parse_results[num_results++] = 'V';
            }
            parse_results[num_results++] = ')';
            word_length = 0;
        }
        else if(input[i] == '=') { // assignment operator
            if(word_length > 0 && is_variable(current_word, 0)) {
                parse_results[num_results++] = 'V';
            }
            parse_results[num_results++] = '=';
            word_length = 0;
        }
        else if(input[i] == ',') { // comma
            if(word_length > 0 && is_variable(current_word, 0)) {
                parse_results[num_results++] = 'V';
            }
            parse_results[num_results++] = ',';
            word_length = 0;
        }
        else if(i == length - 1) { // end of input
            current_word[word_length++] = input[i];
            if(is_variable(current_word, 1)) {
                parse_results[num_results++] = 'V';
            }
        }
        else { // any other character
            current_word[word_length++] = input[i];
        }
        i++;
    }
    
    printf("Parsing result:");
    for(int i=0; i<num_results; i++) {
        printf(" %c", parse_results[i]);
    }
    printf("\n");
    
    return 0;
}