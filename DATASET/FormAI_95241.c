//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: recursive
#include <stdio.h>

void translate(char* input, int index);

int main() {
    char input[] = "C<((((('>";
    translate(input, 0);
    return 0;
}

void translate(char* input, int index) {
    if (input[index] == '\0') {
        return;
    }
    
    if (input[index] == 'C') {
        printf("Hello ");
        translate(input, index + 1);
    } else if (input[index] == '<') {
        printf("world, ");
        translate(input, index + 1);
    } else if (input[index] == '(') {
        printf("how ");
        translate(input, index + 1);
    } else if (input[index] == '\'') {
        printf("are ");
        translate(input, index + 1);
    } else if (input[index] == ')') {
        printf("you? ");
        translate(input, index + 1);
    } else if (input[index] == '>') {
        printf("\n");
        translate(input, index + 1);
    } else {
        translate(input, index + 1);
    }
}