//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short calculate_checksum(char *input, int length) {
    unsigned int sum = 0;
    unsigned short checksum;
    int i;
    
    for (i = 0; i < length; i++) {
        sum += (unsigned char) input[i];
    }
    
    checksum = (unsigned short) ((sum & 0xffff) + (sum >> 16));
    return ~checksum;
}

int main() {
    char input[100];
    unsigned short result;
    int length;
    
    printf("Enter your input string: ");
    fgets(input, sizeof(input), stdin);
    
    length = strlen(input);
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
        length--;
    }
    
    result = calculate_checksum(input, length);
    
    printf("Checksum for input string \"%s\" is %04X\n", input, result);
    
    return 0;
}