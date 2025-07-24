//FormAI DATASET v1.0 Category: Benchmarking ; Style: beginner-friendly
#include<stdio.h>
#include<time.h>

#define MAX_SIZE 100000

int main(){

    int arr[MAX_SIZE], i, j, temp;
    clock_t start, end;
    double time_taken;
    
    // Generating random array
    for(i=0; i<MAX_SIZE; i++){
        arr[i] = rand() % MAX_SIZE;
    }
    
    // Bubble Sort
    start = clock();
    for(i=0; i<MAX_SIZE-1; i++){
        for(j=0; j<MAX_SIZE-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %lf seconds\n", time_taken);
    
    // Selection Sort
    start = clock();
    for(i=0; i<MAX_SIZE-1; i++){
        int min = i;
        for(j=i+1; j<MAX_SIZE; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort: %lf seconds\n", time_taken);
    
    //Insertion Sort
    start = clock();
    for(i=1; i<MAX_SIZE; i++){
        int key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %lf seconds\n", time_taken);
    
    return 0;
}