//FormAI DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdbool.h>

#define TAB_SIZE 4

int main() {
    char input[1000];
    printf("Enter the HTML code:\n");
    fgets(input, 1000, stdin);

    int tabCount = 0;
    bool inTag = false;
    bool inQuotes = false;

    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];

        // Handle quotes
        if (c == '"') {
            inQuotes = !inQuotes;
        }

        // Handle start and end of tag
        if (c == '<') {
            inTag = true;
            printf("%c", c);
            tabCount++;
        } else if (c == '>') {
            inTag = false;
            printf("%c", c);
        } else if (inTag) {
            printf("%c", c);
        } else {
            // Handle tabbing
            if (c == '{') {
                printf("\n");
                for (int j = 0; j < tabCount; j++) {
                    for (int k = 0; k < TAB_SIZE; k++) {
                        printf(" ");
                    }
                }
            } else if (c == '}') {
                printf("\n");
                tabCount--;

                for (int j = 0; j < tabCount; j++) {
                    for (int k = 0; k < TAB_SIZE; k++) {
                        printf(" ");
                    }
                }
            } else {
                printf("%c", c);
            }
        }
    }

    return 0;
}