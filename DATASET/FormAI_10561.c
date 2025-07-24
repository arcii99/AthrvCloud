//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
// Hey there! I am a unique implementation of the bucket sort algorithm!
// Prepare to dive into the world of irregularity with me

#include<stdio.h>
#include<stdlib.h>

// Let's create a special type of node to store our elements
typedef struct bucket{
    int data;
    struct bucket* next;
} Bucket;

// Now let's implement our sort function that takes in an array and its size
void BucketSort(int arr[], int size){
    // First we create our array of buckets as an array of pointers to buckets
    Bucket* a[10];
    for(int i=0;i<10;i++){
        a[i] = NULL;
    }
    
    // Then we loop through the array, creating nodes for each element and linking them to their respective buckets
    for(int i=0;i<size;i++){
        Bucket* newNode = (Bucket*)malloc(sizeof(Bucket));
        newNode->data = arr[i];
        newNode->next = NULL;
        
        int index = arr[i]/10; // We determine the bucket index by dividing the element by 10
        
        if(a[index] == NULL){ // If there are no other nodes in the bucket, we add our new node as the first node
            a[index] = newNode;
        }else{ // Otherwise, we add our new node to the end of the bucket
            Bucket* temp = a[index];
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    // Finally, we loop through our buckets and copy their elements back into the original array in sorted order
    int k=0;
    for(int i=0;i<10;i++){
        Bucket* temp = a[i];
        while(temp != NULL){
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

int main(){
    // Welcome to the random number generator! Let's populate an array with 100 random numbers between 0 and 99
    int arr[100];
    printf("Unsorted array:\n");
    for(int i=0;i<100;i++){
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    
    // Now let's sort the array using our bucket sort algorithm
    BucketSort(arr, 100);
    
    // Finally, let's print out our sorted array
    printf("\nSorted array:\n");
    for(int i=0;i<100;i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}