//FormAI DATASET v1.0 Category: Word Count Tool ; Style: complex
#include <stdio.h>

int main() {
    char text[1000];
    int count = 0;

    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' && text[i+1] != ' ') {
            count++;
        }
    }

    printf("Word count: %d\n", count + 1);

    return 0;
}