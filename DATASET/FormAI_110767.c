//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove leading spaces
char* ltrim(char* s) {
    while(*s == ' ') {
        s++;
    }
    return s;
}

// Function to remove trailing spaces
char* rtrim(char* s) {
    char* back = s + strlen(s);
    while((*--back) == ' ');
    *(back+1) = '\0';
    return s;
}

// Function to remove extra spaces
char* trim(char* s) {
    char* trimmed = rtrim(ltrim(s));
    int i, j = 0;
    for(i = 0; i < strlen(trimmed); i++) {
        if(trimmed[i] == ' ' && trimmed[i+1] == ' ')
            continue;
        s[j++] = trimmed[i];
    }
    s[j]='\0';
    return s;
}

// Function to sanitize input by removing extra spaces and converting to lowercase
void sanitize(char* input) {
    trim(input);
    for(int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }
}

int main() {
    char input[100];
    printf("Enter input: ");
    fgets(input, 100, stdin);
    sanitize(input);
    printf("Sanitized input: %s\n", input);
    return 0;
}