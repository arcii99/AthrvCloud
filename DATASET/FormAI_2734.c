//FormAI DATASET v1.0 Category: Word Count Tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int count = 0;
    char c;

    printf("Welcome to the C Word Count Tool! \n");
    printf("Enter your text below: \n");

    // Loop through user input until end of file
    while((c = getchar()) != EOF) {
        if(isspace(c)) {
            count++; // Increment count on whitespace
        }
    }

    printf("Word count: %d \n", count);

    return 0;
}