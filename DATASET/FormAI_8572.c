//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[256];
    int count = 0;

    printf("Please enter your name: ");
    fgets(input, 256, stdin);

    printf("Hello, %s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ';') {
            count++;
        }
        if (count >= 2) {
            printf("Intrusion detected! Multiple semicolons detected in input.\n");
            exit(0);
        }
    }

    printf("Thank you for using our system.\n");

    return 0;
}