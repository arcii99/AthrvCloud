//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: modular
#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

void sanitize(char input[], char output[]);
void printOutput(char output[], int len);

int main() {
    char input[MAX_SIZE], output[MAX_SIZE];

    printf("Enter a string:\n");
    fgets(input, MAX_SIZE, stdin);

    sanitize(input, output);

    printf("Sanitized input:\n");
    printOutput(output, MAX_SIZE);

    return 0;
}

void sanitize(char input[], char output[]) {
    int inIndex = 0, outIndex = 0;
    while (input[inIndex] != '\0') {
        char c = input[inIndex];

        if (isalpha(c) || isdigit(c) || c == ' ') {
            output[outIndex] = c;
            outIndex++;
        }

        inIndex++;
    }

    output[outIndex] = '\0';
}

void printOutput(char output[], int len) {
    for (int i = 0; i < len; i++) {
        if (output[i] == '\0') break;
        
        printf("%c", output[i]);
    }
}