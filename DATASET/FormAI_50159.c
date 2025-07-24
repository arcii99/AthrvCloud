//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: distributed
#include<stdio.h>

//Function to print the elements in the array
void printArr(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
}

//Function to sort using bucketSort
void bucketSort(int arr[], int n, int numBuckets)
{
    //Creating an array of buckets
    int buckets[numBuckets][n];
    
    //Initializing all elements of the bucket as 0
    for(int i=0;i<numBuckets;i++)
    {
        for(int j=0;j<n;j++)
        {
            buckets[i][j]=0;
        }
    }
    
    //Calculating the maximum value in the array and its position
    int max=arr[0], pos=0;
    for(int i=1;i<n;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
            pos=i;
        }
    }
    
    //Calculating the size of each bucket
    float buckSize=((float)max+1)/numBuckets;
    
    //Putting the elements into their respective buckets
    for(int i=0;i<n;i++)
    {
        int bucketIndex=arr[i]/buckSize;
        int j=0;
        while(buckets[bucketIndex][j]!=0)
        {
            j++;
        }
        buckets[bucketIndex][j]=arr[i];
    }
    
    //Sorting each bucket
    for(int i=0;i<numBuckets;i++)
    {
        int count=0;
        while(buckets[i][count]!=0)
        {
            count++;
        }
        for(int j=0;j<count-1;j++)
        {
            for(int k=0;k<count-1-j;k++)
            {
                if(buckets[i][k]>buckets[i][k+1])
                {
                    int temp=buckets[i][k];
                    buckets[i][k]=buckets[i][k+1];
                    buckets[i][k+1]=temp;
                }
            }
        }
    }
    
    //Putting the elements of the buckets back into the array
    int index=0;
    for(int i=0;i<numBuckets;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(buckets[i][j]!=0)
            {
                arr[index]=buckets[i][j];
                index++;
            }
        }
    }
}

int main()
{
    int n=10;
    int arr[]={15,3,12,7,4,11,9,5,6,2};
    printf("Original Array: ");
    printArr(arr,n);
    printf("\nSorted Array: ");
    bucketSort(arr,n,5);
    printArr(arr,n);
    return 0;
}