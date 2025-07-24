//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int sherlock(int arr[], int n, int num){
    int i, j;
    for(i=0;i<n;i++){
        if(arr[i]==num){
            printf("Element %d found at index %d\n",num,i);
            return 0;
        }
    }
    printf("Element %d not found in the array\n",num);
}

int main(){
    int n, num, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element you want to search: ");
    scanf("%d",&num);
    sherlock(arr,n,num);
    return 0;
}