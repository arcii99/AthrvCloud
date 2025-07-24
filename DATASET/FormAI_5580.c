//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

// Function to calculate checksum
int calculateChecksum(int* data, int size){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum += data[i];
    }
    return sum;
}

int main(){
    int size = 0;
    printf("Enter the size of data: ");
    scanf("%d", &size);

    // Allocating memory dynamically to store data
    int* data = (int*)malloc(size*sizeof(int));

    printf("Enter the data:\n");
    for(int i=0;i<size;i++){
        scanf("%d", &data[i]);
    }

    // Calculating checksum
    int checksum = calculateChecksum(data, size);

    printf("Checksum: %d\n", checksum);

    // Freeing dynamically allocated memory
    free(data);

    return 0;
}