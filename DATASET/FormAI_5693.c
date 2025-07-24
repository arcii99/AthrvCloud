//FormAI DATASET v1.0 Category: Scientific ; Style: minimalist
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int num_elements, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &num_elements);

    printf("Enter the elements of the array: ");
    for(i = 0; i < num_elements; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, product = 1, max = arr[0], min = arr[0];

    for(i = 0; i < num_elements; i++){
        sum += arr[i];
        product *= arr[i];
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }

    printf("\nSum of all elements: %d", sum);
    printf("\nProduct of all elements: %d", product);
    printf("\nMaximum element: %d", max);
    printf("\nMinimum element: %d", min);

    return 0;
}