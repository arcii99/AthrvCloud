//FormAI DATASET v1.0 Category: Educational ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char input[MAX_SIZE];
    int i, j;
    printf("Enter a word or phrase: ");
    fgets(input, MAX_SIZE, stdin);

    char output[MAX_SIZE];
    int length = strlen(input);

    // Secret sauce
    for (i = 0; i < length; i++) {
        output[i] = input[i] + (i % 2 == 0 ? 1 : -1) * (length - i) * 2;
    }
    output[length] = '\0';

    printf("The encrypted string is: %s\n", output);

    // Reverse the encryption
    for (i = 0; i < length; i++) {
        input[i] = output[length - i - 1] - (i % 2 == 0 ? 1 : -1) * (length - i) * 2;
    }
    input[length] = '\0';

    printf("The decrypted string is: %s\n", input);

    return 0;
}