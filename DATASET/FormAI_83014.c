//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Romeo and Juliet
#include<stdio.h>

//Declare function for bucket sort
void bucket_sort(int arr[], int n){
    
    //Initialize buckets
    int bucket[n];
    
    for(int i=0;i<n;i++)
        bucket[i] = 0;
    
    //Increment count of array element in bucket
    for(int i=0;i<n;i++)
        bucket[arr[i]]++;
        
    //Sort array with bucket count
    for(int i=0, j=0;i<n;i++){
        while(bucket[i]>0){
            arr[j++] = i;
            bucket[i]--;
        }
    }
}

int main(){
    //Declare array with unsorted elements
    int arr[] = {9,5,6,3,2,8,7,1,4,6};
    
    //Calculate size of array
    int n = sizeof(arr)/sizeof(arr[0]);
    
    //Call bucket sort function
    bucket_sort(arr, n);
    
    //Print sorted array
    printf("Sorted Array: ");
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
        
    return 0;
}