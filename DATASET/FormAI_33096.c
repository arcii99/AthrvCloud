//FormAI DATASET v1.0 Category: Compression algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main()
{
    char original_str[MAX_LENGTH];
    char compressed_str[MAX_LENGTH];
    char prev_char;
    int count, i, j;

    printf("Enter a string to compress (max length %d): ", MAX_LENGTH);
    fgets(original_str, MAX_LENGTH, stdin);
    original_str[strcspn(original_str, "\n")] = '\0';

    // compression algorithm
    j = 0;
    count = 1;
    prev_char = original_str[0];
    for (i = 1; i < strlen(original_str); i++) {
        if (original_str[i] == prev_char) {
            count++;
        }
        else {
            compressed_str[j] = prev_char;
            j++;
            compressed_str[j] = count + '0'; // convert count to ASCII
            j++;
            prev_char = original_str[i];
            count = 1;
        }
    }
    compressed_str[j] = prev_char;
    j++;
    compressed_str[j] = count + '0';
    j++;
    compressed_str[j] = '\0';

    printf("Original string: %s\n", original_str);
    printf("Compressed string: %s\n", compressed_str);
    printf("Compression ratio: %.2f%%\n", ((float) strlen(compressed_str) / strlen(original_str)) * 100);

    return 0;
}