//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int get_checksum(char* input) {
    int checksum = 0;
    int i;
    for (i = 0; input[i] != '\0'; ++i) {
        checksum ^= input[i];
    }
    return checksum;
}

int main() {
    char input[256];
    
    printf("Enter the input string: ");
    scanf("%s", input);
    
    int checksum = get_checksum(input);
    printf("The checksum is: %d\n", checksum);
    
    return 0;
}