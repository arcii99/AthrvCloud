//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdio.h> 

// Maximum number of elements that can be sorted using bucket sort. 
#define MAX_ELEMS 100 

// Definition of the bucket struct 
struct bucket 
{ 
    int count; 
    int* value; 
}; 

// Function to generate random numbers for sorting 
void generateRandom(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        arr[i] = rand() % 100; 
} 

// Function to print the generated random numbers 
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

// Function to sort using bucket sort 
void bucketSort(int arr[], int n) 
{ 
    int i, j; 

    // Create the empty buckets 
    struct bucket buckets[10]; 
 
    for (i = 0; i < 10; i++) 
    { 
        buckets[i].count = 0; 
        buckets[i].value = (int*)malloc(sizeof(int) * MAX_ELEMS); 
    } 

    // Assign the elements to the appropriate buckets 
    for (i = 0; i < n; i++) 
    { 
        int bucketIndex = (arr[i]) / 10; 
        buckets[bucketIndex].value[buckets[bucketIndex].count++] = arr[i]; 
    } 

    // Sort each bucket and merge them back into the original array 
    for (i = 0; i < 10; i++) 
    { 
        int* bucketValues = buckets[i].value; 
        int bucketSize = buckets[i].count; 

        for (j = 1; j < bucketSize; j++) 
        { 
            int currentValue = bucketValues[j]; 
            int k = j - 1; 

            while (k >= 0 && bucketValues[k] > currentValue) 
            { 
                bucketValues[k + 1] = bucketValues[k]; 
                k--; 
            } 

            bucketValues[k + 1] = currentValue; 
        } 

        for (j = 0; j < bucketSize; j++) 
        { 
            arr[(i * MAX_ELEMS) + j] = bucketValues[j]; 
        } 
    } 
} 

// Main function 
int main() 
{ 
    int n = 20; 
    
    // Generate random elements and print them 
    int arr[n]; 
    generateRandom(arr, n); 
    printf("Original Array: "); 
    printArray(arr, n); 

    // Sort the array using bucket sort and print the sorted array 
    bucketSort(arr, n); 
    printf("Sorted Array: "); 
    printArray(arr, n); 

    return 0; 
}