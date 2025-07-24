//FormAI DATASET v1.0 Category: Benchmarking ; Style: complex
#include <stdio.h>  
#include <time.h>   
#define MAX_NUMBER 1000000  

int main() {  
    int normalArray[MAX_NUMBER], reverseArray[MAX_NUMBER], randomArray[MAX_NUMBER];  
    int i, j, temp;  
    clock_t begin, end;   
    double time_spent;  
    
    printf("Generating the arrays...\n");
      
    /* Filling the arrays with random numbers */
    for(i = 0; i < MAX_NUMBER; i++) {  
        normalArray[i] = i;  
    }  
    
    j = 0;
    for(i = MAX_NUMBER-1; i >= 0; i--) {  
        reverseArray[j] = i;  
        j++;  
    }  
    
    srand(time(NULL));
    for(i = 0; i < MAX_NUMBER; i++) {  
        randomArray[i] = rand() % 100 + 1;  
    }  
    
    printf("Benchmarking the sorting algorithms...\n\n");
    
    /* BENCHMARKING THE BUBBLE SORT ALGORITHM */
    printf("------------------------------------------------\n");  
    printf("Sorting an array of %d items using Bubble Sort...\n", MAX_NUMBER);  
    begin = clock();  
      
    for(i = 0; i < MAX_NUMBER-1; i++) {  
        for(j = 0; j < MAX_NUMBER-i-1; j++) {  
            if(normalArray[j] > normalArray[j+1]) {  
                temp = normalArray[j];  
                normalArray[j] = normalArray[j+1];  
                normalArray[j+1] = temp;  
            }  
        }  
    }  
      
    end = clock();  
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;  
    printf("Time taken to sort the array: %f seconds\n", time_spent);  
    printf("------------------------------------------------\n\n");  
    
    /* BENCHMARKING THE QUICK SORT ALGORITHM */
    printf("------------------------------------------------\n");  
    printf("Sorting an array of %d items using Quick Sort...\n", MAX_NUMBER);  
    begin = clock();  
      
    quickSort(reverseArray, 0, MAX_NUMBER-1);
      
    end = clock();  
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;  
    printf("Time taken to sort the array: %f seconds\n", time_spent);  
    printf("------------------------------------------------\n\n");
    
    /* BENCHMARKING THE MERGE SORT ALGORITHM */
    printf("------------------------------------------------\n");  
    printf("Sorting an array of %d items using Merge Sort...\n", MAX_NUMBER);  
    begin = clock();  
      
    mergeSort(randomArray, 0, MAX_NUMBER-1);
      
    end = clock();  
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;  
    printf("Time taken to sort the array: %f seconds\n", time_spent);  
    printf("------------------------------------------------\n\n");  
    
    return 0;  
} 

void quickSort(int array[], int left, int right) {
    int i = left, j = right;
    int temp;
    int pivot = array[(left + right) / 2];
 
    while (i <= j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
 
    if (left < j)
        quickSort(array, left, j);
    if (i < right)
        quickSort(array, i, right);
}

void merge(int array[], int left, int middle, int right) {
    int temp[MAX_NUMBER];
    int i, j, k;
    i = left;
    j = middle + 1;
    k = 0;

    while (i <= middle && j <= right) {
        if (array[i] <= array[j]) {
            temp[k] = array[i];
            k++;
            i++;
        }
        else {
            temp[k] = array[j];
            k++;
            j++;
        }
    }

    while (i <= middle) {
        temp[k] = array[i];
        k++;
        i++;
    }

    while (j <= right) {
        temp[k] = array[j];
        k++;
        j++;
    }

    for (i = left; i <= right; i++) {
        array[i] = temp[i - left];
    }
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}