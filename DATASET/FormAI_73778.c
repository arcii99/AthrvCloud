//FormAI DATASET v1.0 Category: Data mining ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

int main() {
    int i, j, n, temp, count = 0;
    int arr[50];
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    printf("\nEnter the elements of the array: ");
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }

    // Data Mining
    for(i=0;i<n;i++) {
        for(j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
        if(count == 0) {
            break;
        }
    }
    
    printf("\nArray after data mining: ");
    for(i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}