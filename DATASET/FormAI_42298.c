//FormAI DATASET v1.0 Category: Word Count Tool ; Style: sophisticated
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    int count = 0;

    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin);

    // Count words
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            count++;
        }
    }

    // Print results
    if (count != 0) {
        printf("Word count: %d\n", count);
    } else {
        printf("No words found.\n");
    }

    return 0;
}