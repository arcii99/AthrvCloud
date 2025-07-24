//FormAI DATASET v1.0 Category: Word Count Tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char s[1000];
    int c=0, i=0;
    printf("Welcome to the C Word Count Tool!\n");
    printf("Enter the text you want to count words for:\n");
    fgets(s, 1000, stdin);

    // count number of words 
    while (s[i] != '\0') {
        if (isspace(s[i])) {
            c++;
        }
        i++;
    }
    if (i > 0) {
        c++;
    }

    printf("The number of words in this text is %d.\n", c);

    return 0;
}