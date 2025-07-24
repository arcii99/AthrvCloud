//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bucketSort(int array[], int n) 
{
    int max_num = array[0];
    for(int i=1; i<n; i++) 
    {
        if(max_num<array[i])
        {
            max_num = array[i];
        }
    }
    int bucket[max_num+1];
    for(int i=0; i<=max_num; ++i){
        bucket[i]=0;
    }
    for(int i=0; i<n; ++i)
    {
        ++bucket[array[i]]; 
    }
    for(int i=0,j=0; i<=max_num; ++i)
    {
        while(bucket[i])
        {
            array[j++] = i;
            --bucket[i];
        }
    }
}

int main()
{
    srand(time(NULL));
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int array[n];
    printf("Unsorted array: ");
    for(int i=0;i<n;++i)
    {
        array[i]=rand()%100+1;
        printf("%d ",array[i]);
    }
    printf("\n\n");
    bucketSort(array,n);
    printf("Sorted array: ");
    for(int i=0;i<n;++i)
    {
        printf("%d ",array[i]);
    }
    return 0;
}