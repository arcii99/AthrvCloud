//FormAI DATASET v1.0 Category: Compression algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    char input[100];
    int i, j, count = 1;
    
    printf("Enter a string to compress: ");
    scanf("%s", input);
    
    int len = strlen(input);
    char output[len];
    
    // start compression
    for (i = 0; i < len; i++) {
        if (input[i] == input[i+1]) {
            count++;
        }
        else {
            output[j++] = input[i];
            output[j++] = count + '0';
            count = 1;
        }
    }
    output[j] = '\0';
    
    // check if compression saved space
    if (strlen(output) >= len) {
        printf("Cannot compress. The output would be larger than the input.");
        return 0;
    }
    
    printf("Original string: %s\n", input);
    printf("Compressed string: %s\n", output);
    
    return 0;
}