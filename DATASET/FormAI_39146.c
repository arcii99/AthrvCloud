//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Ken Thompson
#include <stdio.h>

int main() {
    char input[100];
    printf("Enter your URL: ");
    scanf("%s", input);
    char output[100];
    int i, j = 0;

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            output[j++] = '%';
            output[j++] = '2';
            output[j++] = '0';
        } else {
            output[j++] = input[i];
        }
    }

    printf("Sanitized URL: %s\n", output);
    return 0;
}