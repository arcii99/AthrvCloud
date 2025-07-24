//FormAI DATASET v1.0 Category: Sorting ; Style: mathematical
#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 
    int n, i, j, temp; 
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n]; 
    
    printf("Enter the array elements: ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    // Sorting algorithm starts here
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // Sorting algorithm ends here
    
    printf("The sorted array is: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}