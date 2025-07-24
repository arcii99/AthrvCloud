//FormAI DATASET v1.0 Category: Compression algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

char* compress(char* input) {
    int length = strlen(input);
    char* output = (char*)malloc(sizeof(char) * (MAX_SIZE + 1));
    int count = 1;
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (i + 1 < length && input[i] == input[i + 1]) {
            count++;
        }
        else {
            output[j++] = input[i];
            if (count > 1) {
                char buffer[10];
                sprintf(buffer, "%d", count);
                for (int k = 0; k < strlen(buffer); k++) {
                    output[j++] = buffer[k];
                }
                count = 1;
            }
        }
    }
    output[j] = '\0';
    return output;
}

int main() {
    printf("Enter a string to compress: ");
    char input[MAX_SIZE];
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';
    char* output = compress(input);
    printf("Compressed string: %s\n", output);
    free(output);
    return 0;
}