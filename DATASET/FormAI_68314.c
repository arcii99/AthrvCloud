//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateChecksum(char* str) {
    int checksum = 0;
    
    for(int i = 0; i < strlen(str); i++) {
        checksum += str[i];
    }
    
    return checksum;
}

int main() {
    char str[100];
    int checksum;
    
    printf("My Darling, please enter the word or phrase you want to calculate the checksum for:\n");
    scanf("%[^\n]", str);
    
    checksum = calculateChecksum(str);
    
    printf("\n\nMy Love, the checksum for the word or phrase \"%s\" is: %d\n", str, checksum);
    
    return 0;
}