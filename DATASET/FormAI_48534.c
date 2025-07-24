//FormAI DATASET v1.0 Category: Word Count Tool ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    int count = 0;

    printf("Enter your text:\n");
    fgets(text, 1000, stdin);

    for(int i = 0; i < strlen(text); i++) {
        if(text[i] == ' ' || text[i] == '\n' || text[i] == '\t') count++;
    }

    printf("Word count: %d\n", count);

    return 0;
}