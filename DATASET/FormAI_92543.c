//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void initialize_array(int *array){
    srand(time(NULL));
    for(int i=0; i<ARRAY_SIZE; i++){
        array[i] = rand()%100;
    }
}

int binary_search(int *array, int key){
    int left = 0, right = ARRAY_SIZE-1;
    while(left<=right){
        int middle = (left+right)/2;
        if(array[middle]==key){
            return middle;
        }
        if(array[middle]<key){
            left = middle+1;
        }
        else{
            right = middle-1;
        }
    }
    return -1;
}

void quick_sort(int *array, int left, int right){
    if(left>=right){
        return;
    }
    int pivot = array[(left+right)/2];
    int i = left, j = right;
    while(i<=j){
        while(array[i]<pivot){
            i++;
        }
        while(array[j]>pivot){
            j--;
        }
        if(i<=j){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    quick_sort(array, left, j);
    quick_sort(array, i, right);
}

int main(){
    int array[ARRAY_SIZE];
    initialize_array(array);
    quick_sort(array, 0, ARRAY_SIZE-1);
    int random_key = rand()%100;
    int index = binary_search(array, random_key);
    if(index==-1){
        printf("The key %d was not found in the sorted array\n", random_key);
    }
    else{
        printf("The key %d was found at index %d\n", random_key, index);
    }
    return 0;
}