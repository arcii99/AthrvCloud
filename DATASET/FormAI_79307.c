//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

void printArray(int* array, int size);

void bucketSort(int* array, int size, int bucketSize){
    int maxVal = array[0], minVal = array[0];
    for(int i=1; i<size; i++){
        if(array[i] > maxVal){
            maxVal = array[i];
        }
        if(array[i] < minVal){
            minVal = array[i];
        }
    }
    int bucketCount = (maxVal-minVal)/bucketSize + 1;
    int** buckets = (int**)malloc(sizeof(int*)*bucketCount);
    for(int i=0; i<bucketCount; i++){
        buckets[i] = (int*)malloc(sizeof(int)*size);
        for(int j=0; j<size; j++){
            buckets[i][j] = 0;
        }
    }
    int* bucketSizes = (int*)malloc(sizeof(int)*bucketCount);
    for(int i=0; i<bucketCount; i++){
        bucketSizes[i] = 0;
    }
    for(int i=0; i<size; i++){
        int index = (array[i]-minVal)/bucketSize;
        buckets[index][bucketSizes[index]] = array[i];
        bucketSizes[index]++;
    }
    int index = 0;
    for(int i=0; i<bucketCount; i++){
        insertionSort(buckets[i], bucketSizes[i]);
        for(int j=0; j<bucketSizes[i]; j++){
            array[index] = buckets[i][j];
            index++;
        }
    }
    for(int i=0; i<bucketCount; i++){
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

void insertionSort(int* array, int size){
    if(size<=1){
        return;
    }
    for(int i=1; i<size; i++){
        int j = i-1;
        int key = array[i];
        while(j>=0 && array[j]>key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void printArray(int* array, int size){
    for(int i=0; i<size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int size, bucketSize;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int* array = (int*)malloc(sizeof(int)*size);
    for(int i=0; i<size; i++){
        printf("Enter element %d: ", i);
        scanf("%d", &array[i]);
    }
    printf("Enter the bucket size: ");
    scanf("%d", &bucketSize);
    printf("Input array: ");
    printArray(array, size);
    bucketSort(array, size, bucketSize);
    printf("Sorted array: ");
    printArray(array, size);
    free(array);
    return 0;
}