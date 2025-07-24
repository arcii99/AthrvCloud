//FormAI DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char output[100] = "";
    printf("Enter a string: ");
    scanf("%s", input);

    int length = strlen(input);
    for (int i=0; i<length; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = input[i] - 32;  // Capitalize lowercase letters
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = input[i] + 32;  // Convert uppercase letters to lowercase
        } else {
            output[i] = input[i];  // Copy all other characters as is
        }
    }

    printf("Input String: %s\n", input);
    printf("Output String: %s\n", output);

    return 0;
}