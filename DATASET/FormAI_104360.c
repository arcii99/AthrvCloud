//FormAI DATASET v1.0 Category: Sorting ; Style: creative
#include<stdio.h> //Header file for standard Input/Output

int main(){
    int data[50], n, i, j, temp;  //Declaring variables

    printf("Enter the number of elements to be sorted: "); //Asking user for number of elements
    scanf("%d", &n);

    printf("\nEnter elements:\n");  //Asking user for the elements of the array
    for(i=0; i<n; ++i){
        printf("\nEnter Element %d: ", i+1);
        scanf("%d", &data[i]);
    }

    //Sorting Algorithm
    for(i=0; i<n-1; ++i){
        for(j=i+1; j<n; ++j){
            if(data[i] > data[j]){
                temp=data[i];
                data[i]=data[j];
                data[j]=temp;
            }
        }
    }

    //Printing the Sorted Array
    printf("\nSorted Array:\n"); 
    for(i=0; i<n; i++){
        printf("%d ", data[i]);
    }
    return 0;
}