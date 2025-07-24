//FormAI DATASET v1.0 Category: Syntax parsing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* input;
size_t input_size = 256; // Maximum input size
char* token;
char* tokens[256]; // Maximum of 256 tokens
int num_tokens = 0; // Initially, there are no tokens

void parse_input() {
    token = strtok(input, " "); // Tokenize input using spaces as delimiters
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i]);
    }
}

int main() {
    printf("Enter a C program statement: ");
    input = (char*) malloc(input_size); // Allocate memory for input
    getline(&input, &input_size, stdin); // Read input from user
    
    parse_input();
    printf("Tokens:\n");
    print_tokens();
    
    return 0;
}