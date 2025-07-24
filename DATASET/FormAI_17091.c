//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: mathematical
#include<stdio.h>

//Calculate and return checksum
int calculateChecksum(int data[], int length)
{
    int sum = 0;
    
    //Calculate sum of all the elements in array
    for(int i=0; i<length; i++)
    {
        sum += data[i];
    }
    
    //Take 1's complement of sum
    sum = ~sum;
    
    return sum;
}

void main()
{
    int data[] = {2, 5, 8, 3, 7, 1, 4, 6};
    int length = sizeof(data)/sizeof(data[0]);
    
    printf("Data: ");
    for(int i=0; i<length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    //Calculate and print checksum
    printf("Checksum: %d", calculateChecksum(data, length));
}