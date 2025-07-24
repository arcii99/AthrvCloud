//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

//function to perform bucket sort
void bucketSort(float arr[], int n){
    int i, j;
    //create n buckets
    int count[n];
    for (i = 0; i < n; i++){
        count[i] = 0;
    }
    //increment the respective bucket counter
    for (i = 0; i < n; i++){
        count[(int)arr[i]]++;
    }
    //sort each bucket and merge 
    for (i = 0, j = 0; i < n; i++){
        while (count[i] > 0){
            arr[j++] = i;
            count[i]--;
        }
    }
}

int main(){
    int n,i;
    float arr[n];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    //generate random numbers within 0 to 1
    for(i=0;i<n;i++){
        arr[i] = (float)rand()/RAND_MAX;
    }
    printf("\nBefore sorting:\n");
    for(i=0;i<n;i++){
        printf("%f ",arr[i]);
    }
    //perform bucket sort
    bucketSort(arr,n);
    printf("\nAfter sorting:\n");
    for(i=0;i<n;i++){
        printf("%f ",arr[i]);
    }
    return 0;
}