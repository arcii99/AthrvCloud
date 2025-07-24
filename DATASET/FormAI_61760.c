//FormAI DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, j, count = 1;
    char str[100], compressed_str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == str[i+1]) {
            count++;
        } else {
            compressed_str[j] = str[i];
            compressed_str[j+1] = count + '0';
            count = 1;
            j = j + 2;
        }
    }
    
    compressed_str[j] = '\0';
    
    printf("Compressed string: %s\n", compressed_str);
    
    return 0;
}