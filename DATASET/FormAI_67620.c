//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: inquisitive
#include <stdio.h>

// function to find the maximum index of a given array
int find_max_index(int arr[], int n){
    int max_index = 0;
    for(int i=1; i<n; i++){
        if(arr[i] > arr[max_index]){
            max_index = i;
        }
    }
    return max_index;
}

// function to perform the greedy algorithm and print the results
void greedy_algorithm(int arr[], int n, int k){
    int current_index = 0;
    int count = 0;
    while(count < k){
        int max_index = find_max_index(arr+current_index, n-current_index);
        printf("%d ", arr[current_index+max_index]);
        count++;
        current_index += max_index+1;
    }
}

// main function to drive the program
int main(){
    int arr[] = {10, 5, 20, 25, 30, 3, 34};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printf("Original array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\nElements selected by the greedy algorithm: ");
    greedy_algorithm(arr, n, k);
    return 0;
}