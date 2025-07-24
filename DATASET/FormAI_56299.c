//FormAI DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

char *compress(char *input) {
    int length = strlen(input);
    if (length == 0) {
        return "";
    }
    
    char *compressed = (char *)malloc(sizeof(char) * (MAX_LENGTH + 1));
    int prev = 0;
    int count = 1;
    int index = 0;
    
    for (int i = 1; i <= length; i++) {
        if (input[i] == input[prev]) {
            count++;
        } else {
            compressed[index] = input[prev];
            index++;
            char temp[MAX_LENGTH];
            sprintf(temp, "%d", count);
            strcat(compressed, temp);
            index += strlen(temp);
            count = 1;
            prev = i;
        }
    }
    
    compressed[index] = '\0';
    return compressed;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string to compress: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // remove the newline character from the input
    
    char *compressed = compress(input);
    printf("Compressed string: %s\n", compressed);
    
    free(compressed);
    return 0;
}