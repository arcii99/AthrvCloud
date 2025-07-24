//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10 //set the size of the input array
#define BUCKET_SIZE 10 //set the size of the bucket array

void bucket_sort(int array[]){

    int i,j,k;
    int bucket[BUCKET_SIZE][SIZE+1]; //create a bucket array with size equal to BUCKET_SIZE
    int bucket_count[BUCKET_SIZE]; //create a bucket count array
    for(i=0;i<BUCKET_SIZE;i++){ //initialize all bucket counts to 0
        bucket_count[i]=0;
    }
    for(i=0;i<SIZE;i++){ //calculate which bucket each element goes in
        int bucket_index = ((float)BUCKET_SIZE*array[i]/100);
        bucket[bucket_index][bucket_count[bucket_index]] = array[i];
        bucket_count[bucket_index]++;
    }
    for(i=0;i<BUCKET_SIZE;i++){ //sort the elements in each bucket
        for(j=0;j<bucket_count[i]-1;j++){
            for(k=j+1;k<bucket_count[i];k++){
                if(bucket[i][j]>bucket[i][k]){
                    int temp=bucket[i][j];
                    bucket[i][j]=bucket[i][k];
                    bucket[i][k]=temp;
                }
            }
        }
    }
    int index=0;
    for(i=0;i<BUCKET_SIZE;i++){ //concatenate all the buckets
        for(j=0;j<bucket_count[i];j++){
            array[index]=bucket[i][j];
            index++;
        }
    }
}

int main(){

    int array[SIZE]={2,5,4,7,8,3,9,1,6,10}; //initialize the array
    printf("Before sorting:\n");
    for(int i=0;i<SIZE;i++){
        printf("%d ",array[i]); //print the unsorted array
    }
    bucket_sort(array); //sort the array using bucket sort
    printf("\nAfter sorting:\n");
    for(int i=0;i<SIZE;i++){
        printf("%d ",array[i]); //print the sorted array
    }
    return 0;
}