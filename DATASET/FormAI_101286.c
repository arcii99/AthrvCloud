//FormAI DATASET v1.0 Category: Syntax parsing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter C syntax code:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Post-apocalypse parsing rules
    int valid = 1;
    if (strstr(input, "for") || strstr(input, "while")) {
        valid = 0;
    }

    if (valid) {
        printf("Valid syntax code.\n");
    } else {
        printf("Invalid syntax code for post-apocalyptic world.\n");
    }

    return 0;
}