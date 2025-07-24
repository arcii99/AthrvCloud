//FormAI DATASET v1.0 Category: Compression algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char original_string[50];
    printf("Enter the original string to compress: ");
    scanf("%s", original_string);

    char compressed_string[50] = {0};
    int counter = 1;
    char current_char = original_string[0];

    for (int i = 1; i < strlen(original_string); i++) {
        if (original_string[i] == current_char) {
            counter++;
        } else {
            char count_as_char = counter + '0';
            char compressed_chunk[] = {count_as_char, current_char, '\0'};
            strcat(compressed_string, compressed_chunk);
            counter = 1;
            current_char = original_string[i];
        }
    }

    char count_as_char = counter + '0';
    char compressed_chunk[] = {count_as_char, current_char, '\0'};
    strcat(compressed_string, compressed_chunk);

    printf("Original string: %s\n", original_string);
    printf("Compressed string: %s\n", compressed_string);

    return 0;
}