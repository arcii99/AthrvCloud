//FormAI DATASET v1.0 Category: Word Count Tool ; Style: expert-level
#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    int count = 0, flag = 0;

    printf("Enter a string: ");
    while((c = getchar()) != '\n') {
        if(isalpha(c)) { // check if character is alphabet
            flag = 1;
            count++;
        }
        else if(flag == 1) { // check if word has ended
            printf("Word count: %d\n", count);
            count = 0;
            flag = 0;
        }
    }
    if(flag == 1) // for the last word
        printf("Word count: %d\n", count);

    return 0;
}