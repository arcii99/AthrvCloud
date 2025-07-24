//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: realistic
#include <stdio.h> 

int main() 
{ 
    int data[10], checksum = 0; 

    printf("Enter 10 bits of data:\n"); 
    for(int i=0;i<10;i++) 
    { 
        scanf("%d", &data[i]); 
    } 

    printf("\nEntered data is: "); 
    for(int i=0;i<10;i++) 
    { 
        printf("%d ", data[i]); 
    } 

    // Calculating the checksum
    for(int i=0;i<10;i++) 
    {
        checksum += data[i];
    }

    checksum = (checksum % 2 == 0) ? 0 : 1;
    data[10] = checksum;

    printf("\n\nChecksum is: %d\n", checksum); 

    printf("Data transferred: "); 
    for(int i=0;i<=10;i++) 
    { 
        printf("%d ", data[i]); 
    } 

    return 0; 
}