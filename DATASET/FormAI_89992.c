//FormAI DATASET v1.0 Category: Word Count Tool ; Style: mathematical
#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    int count = 0;
    printf("Enter a sentence or phrase:\n");
    while ((c = getchar()) != '\n') {
        if (isalpha(c)) {
            count++;
        }
    }
    printf("The word count is: %d\n", count);
    return 0;
}