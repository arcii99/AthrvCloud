//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>

int main() {
    printf("Welcome to the Cyberpunk User Input Sanitizer Program!\n");

    char input[100];
    printf("Please enter your input: ");
    fgets(input, sizeof(input), stdin);

    int i, j;
    for (i = 0, j = 0; input[i] != '\0'; i++) {
        if (input[i] >= ' ' && input[i] <= '~') {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';

    printf("\n\nSanitized input: %s\n", input);

    printf("\n\nThis program will self-destruct in 10 seconds...\n");
    for (i = 10; i >= 0; i--) {
        printf("%d\n", i);
        sleep(1);
    }

    printf("BOOM! Program self-destructed.\n");

    return 0;
}