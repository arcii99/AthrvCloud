//FormAI DATASET v1.0 Category: Sorting ; Style: synchronous
#include<stdio.h>

int main(){
    int arr[50], n, i, j, temp;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the %d elements: ", n);
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    //Sorting the elements of the array using bubble sort
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("\nSorted array in ascending order: ");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }

    return 0;
}