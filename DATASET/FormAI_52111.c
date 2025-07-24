//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1024

char *compress(char *message) {
    int len = strlen(message);
    char *compressed = (char *) malloc(sizeof(char) * (MAX_SIZE + 1));
    compressed[0] = '\0';
    int count = 1;
    char current_char = message[0];
  
    for (int i = 1; i <= len; i++) {
        if (message[i] == current_char) {
            count++;
        } else {
            char str[10];
            sprintf(str, "%d", count);
            strcat(compressed, str);
            str[0] = current_char;
            str[1] = '\0';
            strcat(compressed, str);
            current_char = message[i];
            count = 1;
        }
    }
  
    return compressed;
}

int main() {
    char message[MAX_SIZE], *compressed;

    printf("Enter message to compress: ");
    fgets(message, MAX_SIZE, stdin);

    compressed = compress(message);

    printf("\nCompressed message: %s\n\n", compressed);

    free(compressed);

    return 0;
}