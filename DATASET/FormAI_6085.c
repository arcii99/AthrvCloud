//FormAI DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

// function to check for valid characters in input text
int is_valid(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ') {
        return 1;
    }
    return 0;
}

int main() {
    char input[1000];
    char output[1000];
    int len, i, j, k = 0;

    printf("Enter the text to be processed: ");
    fgets(input, 1000, stdin);

    len = strlen(input);

    for (i = len - 1; i >= 0; i--) {
        if (is_valid(input[i])) {
            output[k] = input[i];
            k++;
        }
        else {
            output[k] = '-';
            k++;
        }
    }

    printf("Processed text: ");
    for (j = k - 1; j >= 0; j--) {
        printf("%c", output[j]);
    }

    return 0;
}