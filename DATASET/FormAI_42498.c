//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    int checksum = 0;
    int num;
    
    printf("Enter a list of integers, separated by spaces: ");
    
    while (scanf("%d", &num) == 1) {
        checksum += num;
    }
    
    printf("The checksum is: %d\n", checksum);
    
    return 0;
}