//FormAI DATASET v1.0 Category: Compression algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Welcome to the Puzzling Compression Algorithm
    
    printf("Enter a string to compress: ");
    char input[256];
    fgets(input, sizeof(input), stdin);
    int inputlen = strlen(input) - 1;
    
    // Step 1: Remove all vowels
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int i, j;
    for (i = 0; i < inputlen; i++) {
        for (j = 0; j < 10; j++) {
            if (input[i] == vowels[j]) {
                input[i] = '*';
            }
        }
    }
    
    // Step 2: Remove all even numbered characters
    for (i = 0; i < inputlen; i+=2) {
        input[i] = '$';
    }
    
    // Step 3: Shift all characters to the right by their ASCII value
    for (i = 0; i < inputlen; i++) {
        input[i] += (int)input[i];
    }
    
    // Step 4: Convert remaining characters to hex
    char output[256];
    int outputlen = 0;
    for (i = 0; i < inputlen; i++) {
        if (input[i] != '*' && input[i] != '$') {
            char str[3];
            sprintf(str, "%02X", (int)input[i]);
            output[outputlen] = str[0];
            output[outputlen+1] = str[1];
            outputlen += 2;
        }
    }
    output[outputlen] = '\0';  // add null terminator
    
    printf("Compressed string: %s\n", output);
    
    return 0;
}