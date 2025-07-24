//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: all-encompassing
#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
void* thread_function_1(void* arg) 
{ 
    int* num = (int*)arg; 
  
    printf("Thread 1\n"); 
    printf("Argument passed to thread 1: %d\n", *num); 
    
    /* Do some work in thread 1 */
  
    pthread_exit(NULL); 
} 
  
void* thread_function_2(void* arg) 
{ 
    int* num = (int*)arg; 
  
    printf("Thread 2\n"); 
    printf("Argument passed to thread 2: %d\n", *num); 
    
    /* Do some work in thread 2 */
  
    pthread_exit(NULL); 
} 
  
int main() 
{ 
    pthread_t thread1, thread2; 
    int arg1 = 1, arg2 = 2; 
  
    /* Create threads */
    if(pthread_create(&thread1, NULL, thread_function_1, &arg1) != 0) 
        printf("Thread creation failed!\n"); 
    
    if(pthread_create(&thread2, NULL, thread_function_2, &arg2) != 0) 
        printf("Thread creation failed!\n"); 
  
   /* Wait for threads to complete */
   pthread_join(thread1, NULL); 
   pthread_join(thread2, NULL); 
  
    return 0; 
}