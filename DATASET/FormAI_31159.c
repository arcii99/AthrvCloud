//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main(){
    //declare variables
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    int i;
    
    //input values from user
    printf("\nEnter values:\n");
    for(i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    //sort array in ascending order
    int j, temp;
    for(i=0; i<size-1; i++){
        for(j=i+1; j<size; j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    //print sorted array
    printf("\nSorted array in ascending order:\n");
    for(i=0; i<size; i++){
        printf("%d ", arr[i]);
    }

    //find maximum element in array
    int max = arr[0];
    for(i=1; i<size; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    printf("\n\nMaximum element in array: %d", max);

    //find minimum element in array
    int min = arr[0];
    for(i=1; i<size; i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    printf("\nMinimum element in array: %d", min);

    //calculate sum of all elements in array
    int sum = 0;
    for(i=0; i<size; i++){
        sum += arr[i];
    }
    printf("\nSum of all elements in array: %d", sum);

    //calculate average of all elements in array
    float avg = (float)sum/size;
    printf("\nAverage of all elements in array: %.2f", avg);

    return 0;
}