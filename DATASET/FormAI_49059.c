//FormAI DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress(char* input) {
    int count = 1;
    int length = strlen(input);
    char* output = (char*)malloc(length * 2 + 1);
    char previous = input[0];
    int j = 0;
    for(int i = 1; i <= length; i++) {
        if(input[i] == previous) {
            count++;
        } else {
            output[j++] = previous;
            if(count > 1) {
                char count_str[10];
                snprintf(count_str, 10, "%d", count);
                strcat(output, count_str);
                j += strlen(count_str);
                count = 1;
            }
            previous = input[i];
        }
    }
    return output;
}

int main() {
    char* input = "aabbbccddddeee";
    char* compressed = compress(input);
    printf("Input: %s\n", input);
    printf("Compressed: %s\n", compressed);
    free(compressed);
    return 0;
}