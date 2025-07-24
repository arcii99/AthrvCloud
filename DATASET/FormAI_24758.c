//FormAI DATASET v1.0 Category: Benchmarking ; Style: innovative
#include <stdio.h>
#include <time.h>

int main(){
    const int SIZE = 1000000;
    int arr[SIZE];
    clock_t t;

    //Fill the array with random integers
    for(int i=0; i<SIZE; i++){
        arr[i] = rand() % 100;
    }

    //Bubble Sort
    t = clock();
    for(int i=0; i<SIZE-1; i++){
        for(int j=0; j<SIZE-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    t = clock() - t;
    double bubbleSortTime = ((double) t)/CLOCKS_PER_SEC;

    //Insertion Sort
    t = clock();
    for(int i=1; i<SIZE; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    t = clock() - t;
    double insertionSortTime = ((double) t)/CLOCKS_PER_SEC;

    printf("Bubble Sort Time: %lf seconds\n", bubbleSortTime);
    printf("Insertion Sort Time: %lf seconds\n", insertionSortTime);

    return 0;
}