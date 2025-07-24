//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: safe
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

int calculateChecksum(int arr[]) {
    int sum = 0;
    for(int i = 0; i < MAX_SIZE; i++) {
        sum += arr[i];
    }
    return sum % 256;
}

int main() {
    int arr[MAX_SIZE];
    printf("Enter %d integers to calculate checksum:\n", MAX_SIZE);
    for(int i = 0; i < MAX_SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    int checksum = calculateChecksum(arr);
    printf("Checksum: %d\n", checksum);
    return 0;
}