//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; // Assuming max length of input is 100 characters
    printf("Enter a string in Alien Language: ");
    scanf("%s", input);

    int n = strlen(input);
    char output[n / 2 + 1];
    int idx = 0;
    for (int i = 0; i < n; i += 2) {
        char c = input[i];
        int count = input[i + 1] - '0'; // Convert char to int
        for (int j = 0; j < count; j++) {
            output[idx++] = c;
        }
    }
    output[idx] = '\0'; // Add null terminator to output string

    printf("Translation in English: %s\n", output);
    return 0;
}