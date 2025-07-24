//FormAI DATASET v1.0 Category: Compression algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

char *compress(char *s) {
    int i, count = 1, len = strlen(s);
    char curr_char = s[0];
    char *output = malloc(MAX_LEN * sizeof(char));
    
    // Iterate over the input string and count character repeats
    for(i = 1; i <= len; i++) {
        if(s[i] != curr_char) {
            // End of character sequence, write to output string
            sprintf(output + strlen(output), "%c%d", curr_char, count);
            curr_char = s[i];
            count = 1;
        } else {
            // Continue counting
            count++;
        }
    }
    
    return output;
}

int main() {
    char s[MAX_LEN];
    printf("Enter a string to compress: ");
    fgets(s, MAX_LEN, stdin);
    s[strcspn(s, "\n")] = 0; // Remove newline character
    
    char *compressed = compress(s);
    printf("Compressed string: %s\n", compressed);
    free(compressed);
    
    return 0;
}