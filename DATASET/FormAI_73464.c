//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

void generate_random_array(int *arr, int size){
    srand(time(0));
    for(int i=0; i<size; i++){
        arr[i] = rand()%1000;
    }
}

void print_array(int *arr, int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int *arr, int l, int m, int r){
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++){
        L[i] = arr[l+i];
    }
    for(int j=0; j<n2; j++){
        R[j] = arr[m+1+j];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int arr[ARRAY_SIZE];
    generate_random_array(arr, ARRAY_SIZE);
    printf("Unsorted array:\n");
    print_array(arr, ARRAY_SIZE);
    
    clock_t start_time = clock();
    merge_sort(arr, 0, ARRAY_SIZE-1);
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time)/CLOCKS_PER_SEC;
    
    printf("Sorted array:\n");
    print_array(arr, ARRAY_SIZE);
    printf("Time taken: %lf seconds\n", time_taken);
    return 0;
}