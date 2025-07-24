//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // initialize variables
    int sum = 0;
    int num;
    
    // prompt user for input
    printf("Enter a series of numbers to calculate the checksum. Press 0 when finished.\n");
    
    // loop until user inputs 0
    do {
        scanf("%d", &num);
        sum += num;
    } while (num != 0);
    
    // take the one's complement of the sum
    sum = ~sum;
    
    // output the checksum in hex format
    printf("Checksum: 0x%x\n", sum);
    
    return 0;
}