//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: calm
#include <stdio.h>

int main() {
    char input[1000];
    int i, j;

    printf("Enter a string: ");
    fgets(input, 1000, stdin);

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            for (j = 0; j <= input[i] - 'a'; j++) {
                printf("*");
            }
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            for (j = 0; j <= input[i] - 'A'; j++) {
                printf("*");
            }
        } else {
            printf("%c", input[i]);
        }
    }

    return 0;
}