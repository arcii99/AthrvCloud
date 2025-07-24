//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to implement CyberCmp compression algorithm
int cyberCmp(char* input, int size, char* output) {
    int i, j, count = 0;
    char c[MAX_SIZE];
    for (i = 0; i < size; i += count) {
        count = 1;
        for (j = i + 1; j < size && j < i + MAX_SIZE; j++) {
            if (input[j] != input[i])
                break;
            count++;
        }
        if (count == 1)
            snprintf(c, 2, "%c", input[i]);
        else
            snprintf(c, 10, "%d%c", count, input[i]);
        strcat(output, c);
    }
    return strlen(output);
}

int main() {
    char input[MAX_SIZE], output[MAX_SIZE] = "";
    printf("Enter input string: ");
    fgets(input, MAX_SIZE, stdin);
    // remove newline character from input string
    input[strcspn(input, "\n")] = '\0';
    int size = strlen(input);
    int output_size = cyberCmp(input, size, output);
    printf("Compressed string: %s\n", output);
    printf("Output size: %d\n", output_size);
    return 0;
}