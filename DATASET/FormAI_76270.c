//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    int input;
    printf("Welcome to the Subnet Calculator.\nEnter your IP address: ");
    scanf("%d", &input);
    
    int subnet_mask = 0;
    int bit_value = 128;
    
    while (input > 0) {
        input -= bit_value;
        subnet_mask += bit_value;
        bit_value /= 2;
    }
    
    printf("\nYour subnet mask is: %d.0.0.0\n", subnet_mask);
    
    return 0;
}