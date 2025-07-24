//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: light-weight
#include <stdio.h>

int main() 
{
    unsigned short int data[10], checksum = 0;
    int i, n;
    
    printf("Enter the length of data: ");
    scanf("%d", &n);
    
    printf("Enter the data:\n");
    for(i=0; i<n; i++) 
    {
        scanf("%hu", &data[i]);
        checksum += data[i];
        if(checksum > 255)       // If checksum is greater than 1 byte
        {
            checksum -= 255;
            checksum++; // Adding overflow value to checksum
        }
    }
    
    checksum ^= 0xFFFF;         // Inverting the bits of checksum
    printf("Checksum: %hu\n", checksum);    
    
    return 0;
}