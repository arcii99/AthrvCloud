//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: shocked
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() 
{ 
    int ip[4], mask[4], subnet[4]; 
    char input[30]; 
    
    printf("Enter IP address: "); 
    fgets(input, sizeof(input), stdin); 
    sscanf(input, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]); 
    printf("Enter subnet mask: "); 
    fgets(input, sizeof(input), stdin); 
    sscanf(input, "%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]); 
    
    for (int i = 0; i < 4; i++) 
        subnet[i] = ip[i] & mask[i]; 
    
    printf("Subnet address is: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]); 
    
    int bits = 0; 
    for (int i = 0; i < 4; i++) 
    { 
        int n = mask[i]; 
        while (n) 
        { 
            bits += n & 1; 
            n >>= 1; 
        } 
    } 
    
    int hosts = 1 << (32 - bits) - 2; 
    
    printf("Number of host addresses: %d\n", hosts); 
    printf("Wildcard mask is: %d.%d.%d.%d\n", 255 - mask[0], 255 - mask[1], 255 - mask[2], 255 - mask[3]); 
    
    return 0; 
}