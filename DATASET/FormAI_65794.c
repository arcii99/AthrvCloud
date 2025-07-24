//FormAI DATASET v1.0 Category: Word Count Tool ; Style: satisfied
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[1000];
    int words = 0;

    printf("Enter a sentence:\n");
    fgets(input, 1000, stdin);

    for(int i=0; i<strlen(input); i++) {
        if(isspace(input[i]) && !isspace(input[i-1])) {
            words++;
        }
    }

    printf("\nTotal number of words: %d\n", words+1);

    return 0;
}