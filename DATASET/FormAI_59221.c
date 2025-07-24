//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: dynamic
#include <stdio.h>

int main() {
    unsigned char data[50] = {0};
    int index, length;
    unsigned int sum = 0;
    unsigned char checksum;
    
    printf("Please enter the length of the data: ");
    scanf("%d", &length);
    
    for(index = 0; index < length; index++) {
        printf("Enter byte %d: ", index+1);
        scanf("%hhx", &data[index]);
        sum += (unsigned int)data[index];
    }
    
    checksum = (unsigned char)(sum % 256);
    
    printf("\nData Entered:");
    for(index = 0; index < length; index++) {
        printf(" %02X", data[index]);
    }
    printf("\nCalculated Checksum: %02X\n", checksum);
    
    return 0;
}