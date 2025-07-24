//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: medieval
#include<stdio.h>
#include<stdlib.h>

int calculateChecksum(int *data, int size) {
    int checksum = 0;
    int i;
    for(i = 0; i < size; i++) {
        checksum += data[i];
    }
    return checksum;
}

int main() {
    printf("Welcome to the checksum calculator program!\n");
    printf("Please enter the size of your data: ");
    int dataSize;
    scanf("%d", &dataSize);

    if(dataSize <= 0) {
        printf("Data size should be a positive integer!\n");
        return 0;
    }

    int *data = (int*)malloc(dataSize * sizeof(int));
    printf("Enter your data: ");
    int i;
    for(i = 0; i < dataSize; i++) {
        scanf("%d", &data[i]);
    }

    int checksum = calculateChecksum(data, dataSize);
    printf("The checksum of your data is: %d\n", checksum);

    free(data);
    printf("Farewell, traveller!\n");
    return 0;
}