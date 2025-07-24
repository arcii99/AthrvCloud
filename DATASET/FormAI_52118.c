//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Claude Shannon
#include<stdio.h>

int main(){
    int n, i, j, temp;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter the elements of the array:\n");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    //Sorting the array using Selection Sort algorithm
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    //Printing the sorted array
    printf("Sorted array using Selection Sort algorithm:\n");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    //Finding the minimum positive integer that cannot be represented by the sum of the array elements
    int min_pos = 1;
    for(i=0; i<n; i++){
        if(arr[i]<=min_pos){
            min_pos += arr[i];
        }
        else{
            break;
        }
    }
    printf("The minimum positive integer that cannot be represented by the sum of the array elements is: %d\n", min_pos);
    
    return 0;
}