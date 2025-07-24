//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

int calculate_min(int *arr, int n){
    int sum = 0, temp;
    for(int i = 0; i < n; i++){
        temp = arr[i];
        for(int j = 0; j < n; j++){
            if(i != j && temp > arr[j]){
                temp = arr[j];
            }
        }
        sum += temp;
    }
    return sum;
}

int main(){
    int n, *arr;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));

    printf("Enter the elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int min_sum = calculate_min(arr, n);
    printf("Minimum sum of elements is: %d\n", min_sum);

    free(arr);
    return 0;
}