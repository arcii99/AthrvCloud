//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: recursive
#include <stdio.h>
#include <string.h>

void translate(char c[], int length, int i) {
    char result[100] = "";
    // Base case: reached end of string
    if (i == length) {
        printf("%s", c);
        return;
    }
    // Check each letter
    switch(c[i]) {
        case 'A':
            strcat(result, "<>");
            break;
        case 'B':
            strcat(result, "{}");
            break;
        case 'C':
            strcat(result, "()");
            break;
        case 'D':
            strcat(result, "[]");
            break;
        case 'E':
            strcat(result, "$$");
            break;
        default:
            strcat(result, "!");
    }
    printf("%s", result);
    // Recurse to next letter
    translate(c, length, i+1);
}

int main() {
    // Get user input
    char input[100];
    printf("Enter C Alien Language: ");
    scanf("%s", input);
    // Translate and print
    printf("Translated: ");
    translate(input, strlen(input), 0);
    printf("\n");
    
    return 0;
}