//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: synchronous
#include <stdio.h>

int main() {
    int n, i, j, temp, sum = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array separated by space: ");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("The sorted array is: ");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    i = 0;
    printf("\nThe greedy solution is: ");
    while(sum < 50) {
        if(sum+arr[i] <= 50) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
        else i++;
    }
    printf("\n");
    return 0;
}