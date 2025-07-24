//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

void BucketSort(int Array[], int n){
    int i,j,k;
    int Buckets[MAX];
    
    for(i=0; i<MAX;i++)
        Buckets[i] = 0;

    for(i=0;i<n;i++)
        Buckets[Array[i]]++;

    for(i=0,j=0;i<MAX;i++)
        for(k=Buckets[i];k>0;k--)
            Array[j++] = i;
}

int main(){

    int n,i;
    int array[MAX];
    
    printf("Enter number of elements you want to sort: ");
    scanf("%d",&n);
    
    printf("Enter the %d elements: ",n);
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    
    printf("Unsorted elements are: ");
    for(i=0;i<n;i++)
        printf("%d ",array[i]);

    BucketSort(array,n);
    
    printf("\n\nSorted elements are: ");
    for(i=0;i<n;i++)
        printf("%d ",array[i]);

    return 0;
}