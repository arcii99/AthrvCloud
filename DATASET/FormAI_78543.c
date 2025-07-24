//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Alan Touring
#include <stdio.h>
#include <stdbool.h>

// Function to check if a character is a valid identifier character
bool isIdentifierChar(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '_')) {
        return true;
    } else {
        return false;
    }
}

// Function to check if a given string is a valid C identifier
bool isIdentifier(char* str) {
    if (!isIdentifierChar(str[0])) {
        return false;
    }
    int i = 1;
    while (str[i] != '\0') {
        if (!isIdentifierChar(str[i])) {
            return false;
        }
        i++;
    }
    return true;
}

// Function to tokenize a given C code
void tokenize(char* code) {
    int i = 0;
    while (code[i] != '\0') {
        if (code[i] == ' ' || code[i] == '\n' || code[i] == '\t') {
            i++;
            continue;
        }
        if (code[i] == '/' && code[i+1] == '/') {
            // Comment found, skip until newline character
            while (code[i] != '\n') {
                i++;
            }
            continue;
        }
        if (code[i] == '"' || code[i] == '\'') {
            // String or character literal found, skip them
            char quote = code[i];
            i++;
            while (code[i] != quote) {
                if (code[i] == '\\') {
                    // Escape character found, skip next character too
                    i++;
                }
                i++;
            }
            i++;
            continue;
        }
        if (isIdentifierChar(code[i])) {
            // Identifier found, print it out
            int j = i;
            while (isIdentifierChar(code[j])) {
                j++;
            }
            char temp = code[j];
            code[j] = '\0';
            printf("Identifier: %s\n", code+i);
            code[j] = temp;
            i = j;
            continue;
        }
        // Anything else is considered a single character token
        printf("Token: %c\n", code[i]);
        i++;
    }
}

int main() {
    char code[1000] = "int main() { int x = 10; x += 5; return x; } // This is a comment";
    tokenize(code);
    return 0;
}