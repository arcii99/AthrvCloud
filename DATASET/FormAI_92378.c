//FormAI DATASET v1.0 Category: Text processing ; Style: portable
#include <stdio.h>
#include <ctype.h>

int main() {
    int counts[128] = { 0 }; // Initialize all counts to 0
    int c;

    while ((c = getchar()) != EOF) {
        counts[c]++;
    }

    printf("Character counts:\n");
    for (int i = 0; i < 128; i++) {
        if (isalnum(i) && counts[i] > 0) {
            printf("%c: %d\n", i, counts[i]);
        }
    }

    return 0;
}