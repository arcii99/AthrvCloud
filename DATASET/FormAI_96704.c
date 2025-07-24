//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Claude Shannon
#include<stdio.h>

int main(){

    int n, checksum=0;
    printf("Enter the number of integers to be checksummed: ");
    scanf("%d", &n);

    int data[n];
    printf("Enter the integers to be checksummed: ");
    for(int i=0;i<n;i++){
        scanf("%d", &data[i]);
        checksum += data[i];
    }

    // Compute the ones-complement of the checksum
    checksum = ~(checksum);

    printf("The checksum is: %X\n", checksum);
    return 0;
}