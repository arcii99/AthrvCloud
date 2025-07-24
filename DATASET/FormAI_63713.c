//FormAI DATASET v1.0 Category: Text processing ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000], output[1000];
    int i, j, len;

    printf("Welcome to the Exciting Text Processing Program!\n");
    printf("Input some text and we'll make it exciting for you: ");
    fgets(input, 1000, stdin);
    len = strlen(input);

    for (i = 0, j = 0; i < len; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[j] = input[i] + ('A' - 'a') + (i % 2);
            j++;
        }
        else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[j] = input[i] + (i % 3);
            j++;
        }
    }

    printf("\nYour Exciting Text: ");
    for (i = 0; i < j; i++) {
        printf("%c", output[i]);
    }
    printf("\n");

    return 0;
}