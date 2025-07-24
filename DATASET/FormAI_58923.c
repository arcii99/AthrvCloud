//FormAI DATASET v1.0 Category: Online Examination System ; Style: multi-threaded
#include<stdio.h> 
#include<pthread.h> 

// Function for the first question 
void* question1(void* arg) 
{ 
    printf("1. What does HTML stand for?\n"); 
    return NULL; 
} 

// Function for the second question 
void* question2(void* arg) 
{ 
    printf("2. Which of the following is NOT a programming language?\n"); 
    return NULL; 
} 

// Main function 
int main() 
{ 
    pthread_t tid1, tid2; // Thread identifiers 
    
    // Create thread for the first question 
    if(pthread_create(&tid1, NULL, question1, NULL) != 0) 
        printf("Failed to create thread 1\n"); 
    
    // Create thread for the second question
    if(pthread_create(&tid2, NULL, question2, NULL) != 0) 
        printf("Failed to create thread 2\n"); 
    
    // Wait for the first question thread to complete 
    if(pthread_join(tid1, NULL) != 0) 
        printf("Failed to join thread 1\n"); 
    
    // Wait for the second question thread to complete 
    if(pthread_join(tid2, NULL) != 0) 
        printf("Failed to join thread 2\n"); 
        
    return 0; 
}