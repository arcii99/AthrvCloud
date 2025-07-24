//FormAI DATASET v1.0 Category: Sorting ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the Sorting program!\n");
    int n, i, j;
    printf("How many numbers do you want to sort? ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Enter the numbers to sort: ");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("Sorting the numbers...\n");

    // Bubble sort
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("The sorted numbers are: ");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    printf("Thank you for using the Sorting program!\n");
    return 0;
}