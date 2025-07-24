//FormAI DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to compress a given string
char* compress(char* str) {
    int len = strlen(str), count = 0;
    char* result = (char*) malloc (sizeof(char) * (len+1));
    memset(result, 0, sizeof(result)); // initialize result with null character
    result[0] = str[0];

    // loop through the string and count consecutive occurrences of each character
    for (int i = 0; i < len; i++) {
        if (str[i] == result[count]) {
            result[count+1]++;
        } else {
            count += 2;
            result[count] = str[i];
            result[count+1]++;
        }
    }
    return result;
}

int main() {
    char str[100];
    printf("Enter a string to compress: ");
    scanf("%[^\n]", str);
    char* compressed = compress(str);

    // print compressed string
    printf("Compressed string: %s\n", compressed);
    
    free(compressed);
    return 0;
}