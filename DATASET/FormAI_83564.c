//FormAI DATASET v1.0 Category: Compression algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define CODE_LENGTH 10

// Function to generate the compressed code for a string
char* compress(char* str){
    int len = strlen(str);
    char* code = (char*) malloc(CODE_LENGTH * sizeof(char));
    if(code == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }
    // Generate random characters for the code
    for(int i=0; i<CODE_LENGTH; i++){
        code[i] = '!' + rand()%93;
    }
    // Apply the code on the string
    for(int i=0; i<len; i++){
        str[i] = str[i] ^ code[i%CODE_LENGTH];
    }
    return code;
}

int main(){
    char input[MAX_STRING_LENGTH], *code;
    printf("Enter a string to compress:\n");
    fgets(input, MAX_STRING_LENGTH, stdin);
    // Remove the newline character from input
    input[strcspn(input, "\n")] = 0;
    // Compress the input string
    code = compress(input);
    // Print the compressed string along with the code
    printf("Compressed string: %s\n", input);
    printf("Code: %s\n", code);
    free(code);
    return 0;
}