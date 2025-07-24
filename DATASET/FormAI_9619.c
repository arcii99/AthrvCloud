//FormAI DATASET v1.0 Category: Sorting ; Style: intelligent
#include<stdio.h>

void bubble_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Before Sorting: ");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }

    bubble_sort(arr,n);

    printf("\nAfter Sorting: ");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}