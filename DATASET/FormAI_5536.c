//FormAI DATASET v1.0 Category: Data mining ; Style: complete
#include <stdio.h>

void printArray(int arr[], int size);
void dataMining(int arr[], int size);

int main() {
    int data[] = {7, 5, 9, 3, 2, 1, 4, 6, 8, 10};
    int size = sizeof(data)/sizeof(data[0]);
    printf("Original Data: ");
    printArray(data, size);
    dataMining(data, size);
    printf("\nMining Data: ");
    printArray(data, size);
    return 0;
}

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
}

void dataMining(int arr[], int size) {
    int min = arr[0], max = arr[0], sum = 0;
    float mean;
    for(int i=0; i<size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
        sum += arr[i];
    }
    mean = (float) sum / size;
    printf("\nMin value: %d", min);
    printf("\nMax value: %d", max);
    printf("\nSum of all values: %d", sum);
    printf("\nMean value: %.2f", mean);
}