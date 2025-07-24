//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: active
#include<stdio.h>
#include<stdlib.h>

int main() {
    int size, i, sum = 0;
    
    printf("Enter the size of data: ");
    scanf("%d", &size);
    
    // allocating memory dynamically
    int *data = (int*)malloc(size * sizeof(int));
    
    // taking input from user
    printf("Enter the data:\n");
    for(i=0;i<size;i++) {
        scanf("%d", &data[i]);
    }
    
    //calculating checksum
    for(i=0;i<size;i++) {
        sum += data[i];
    }
    
    printf("The checksum is: %d\n", ~(sum - 1)); // bit-wise not and minus 1
    
    //deallocating memory
    free(data);
    
    return 0;
}