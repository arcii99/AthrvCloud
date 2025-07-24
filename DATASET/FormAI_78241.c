//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: paranoid
#include <stdio.h>
#define SIZE 10

void printArr(int arr[]){
    int i = 0;
    for(i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
}
void BucketSort(int array[]){
    int bucket[SIZE] = {0};
    int i = 0;
    for(i = 0; i < SIZE; i++){
        ++bucket[array[i]];
    }
    i = 0;
    int j = 0;
    while(j < SIZE){
        if(bucket[i] > 0){
            array[j] = i;
            --bucket[i];
            ++j;
        } else {
            ++i;
        }
    }
}

int main(){
    int arr[] = {1, 5, 3, 2, 6, 8, 4, 9, 0, 7};
    printArr(arr);
    BucketSort(arr);
    printf("\nAfter sorting:\n");
    printArr(arr);
    return 0;
}