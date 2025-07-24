//FormAI DATASET v1.0 Category: Data mining ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));

    printf("Enter the elements of the array: ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    int max = arr[0];

    for(i=0; i<n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
        if(arr[i] > max){
            max = arr[i];
        }
    }

    printf("The minimum value in the array is: %d\n", min);
    printf("The maximum value in the array is: %d\n", max);

    free(arr);

    return 0;
}