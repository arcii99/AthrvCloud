//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate_checksum(char* data, int length) {
    int sum = 0;
    int i;
    for (i = 0; i < length; i++) {
        sum += data[i];
    }
    return sum % 256;
}

int main(int argc, char** argv) {
    printf("=== Genius Checksum Calculator ===\n\n");
    
    if (argc < 2) {
        printf("Usage: %s <data>\n", argv[0]);
        return 1;
    }
    
    int length = strlen(argv[1]);
    char* data = malloc(length + 1);
    strncpy(data, argv[1], length);
    
    int checksum = calculate_checksum(data, length);
    
    printf("\nData: %s\n", data);
    printf("Length: %d\n", length);
    printf("Checksum: %d\n", checksum);
    
    free(data);
    
    return 0;
}