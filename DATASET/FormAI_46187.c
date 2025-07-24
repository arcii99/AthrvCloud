//FormAI DATASET v1.0 Category: Memory management ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

//Global Variables
int* arr;   //Pointer to store the dynamic memory allocated
int size;   //Size of the array. 

//Function to allocate memory to the array
void* allocate_memory(void* arg){
    arr = (int*)malloc(size*sizeof(int));
    for(int i=0; i<size; i++){
        arr[i] = i+1;
    }
    pthread_exit(NULL);
}

//Function to deallocate memory allocated to the array
void* deallocate_memory(void* arg){
    free(arr);
    pthread_exit(NULL);
}

int main(){
    pthread_t t1, t2;
    
    //Ask user for size of the array
    printf("Enter size of the array: ");
    scanf("%d", &size);
    
    //Create threads to allocate and deallocate memory
    pthread_create(&t1, NULL, allocate_memory, NULL);
    pthread_create(&t2, NULL, deallocate_memory, NULL);
    
    //Wait for threads to complete
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    //Print array values
    printf("Array values:\n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}