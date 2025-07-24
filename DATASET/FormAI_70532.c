//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // for usleep() function
#include <pthread.h>    // for thread management

// Declare global variables
char c1 = 'C';
char c2 = 'P';
char c3 = 'A';
char c4 = 'T';
char c5 = 'H';
char c6 = '\n';

pthread_mutex_t lock; // Declare mutex lock variable 

// Function to print C pattern
void *print_C_pattern(void *thread_id){
    int i, j;
    long id = (long) thread_id;
    pthread_mutex_lock(&lock); // Lock the mutex to prevent race conditions
    
    for(i=1;i<=6;i++){
        if(i==1 || i==6)
            for(j=1;j<=5;j++)
                printf("%c", c1);
        else{
            printf("%c", c1);
            usleep(100000);
            for(j=1;j<=4;j++){
                printf(" ");
                usleep(100000);
            }
        }
        printf("\n");
        usleep(100000);
    }
    
    pthread_mutex_unlock(&lock); // Unlock the mutex to release ownership
    pthread_exit(NULL); // Exit the thread
}

// Function to print P pattern
void *print_P_pattern(void *thread_id){
    int i, j;
    long id = (long) thread_id;
    pthread_mutex_lock(&lock); // Lock the mutex to prevent race conditions
    
    for(i=1;i<=6;i++){
        if(i==1 || i==3)
            for(j=1;j<=4;j++)
                printf("%c", c2);
        else if(i==2)
            for(j=1;j<=3;j++)
                printf("%c", c2);
        else if(i==4)
            for(j=1;j<=2;j++)
                printf("%c", c2);
        else if(i==5)
            printf("%c%c%c",c2,c2,c2);
        else{
            printf("%c", c2);
            for(j=1;j<=3;j++){
                printf(" ");
                usleep(100000);
            }
        }
        printf("\n");
        usleep(100000);
    }
    
    pthread_mutex_unlock(&lock); // Unlock the mutex to release ownership
    pthread_exit(NULL); // Exit the thread
}

// Function to print A pattern
void *print_A_pattern(void *thread_id){
    int i, j;
    long id = (long) thread_id;
    pthread_mutex_lock(&lock); // Lock the mutex to prevent race conditions
    
    for(i=1;i<=6;i++){
        if(i==1 || i==4)
            for(j=1;j<=3;j++)
                printf(" ");
        else if(i==2 || i==3 || i==5)
            printf(" ");
        else{
            printf("%c", c3);
            for(j=1;j<=3;j++){
                printf(" ");
                usleep(100000);
            }
            printf("%c", c3);
            usleep(100000);
        }
        
        printf("\n");
        usleep(100000);
    }
    
    pthread_mutex_unlock(&lock); // Unlock the mutex to release ownership
    pthread_exit(NULL); // Exit the thread
}

// Function to print T pattern
void *print_T_pattern(void *thread_id){
    int i, j;
    long id = (long) thread_id;
    pthread_mutex_lock(&lock); // Lock the mutex to prevent race conditions
    
    for(i=1;i<=6;i++){
        if(i==1)
            for(j=1;j<=5;j++)
                printf("%c", c4);
        else
            printf(" ");
        
        printf("\n");
        usleep(100000);
    }
    
    pthread_mutex_unlock(&lock); // Unlock the mutex to release ownership
    pthread_exit(NULL); // Exit the thread
}

// Function to print H pattern
void *print_H_pattern(void *thread_id){
    int i, j;
    long id = (long) thread_id;
    pthread_mutex_lock(&lock); // Lock the mutex to prevent race conditions
    
    for(i=1;i<=6;i++){
        if(i==3)
            for(j=1;j<=5;j++)
                printf("%c", c5);
        else{
            printf("%c", c5);
            for(j=1;j<=3;j++)
                printf(" ");
            printf("%c", c5);
        }
        
        printf("\n");
        usleep(100000);
    }
    
    pthread_mutex_unlock(&lock); // Unlock the mutex to release ownership
    pthread_exit(NULL); // Exit the thread
}


// Main function
int main(){
    // Create thread variables
    pthread_t thread_C, thread_P, thread_A, thread_T, thread_H;
    int rc;
    long t;
    
    // Initialize mutex lock
    if(pthread_mutex_init(&lock,NULL) != 0){
        printf("Mutex initialization failed.\n");
        exit(1);
    }
    
    // Create threads to print patterns asynchronously
    for(t=1; t<=5; t++){
        if(t==1)
            rc = pthread_create(&thread_C, NULL, print_C_pattern, (void *)t);
        else if(t==2)
            rc = pthread_create(&thread_P, NULL, print_P_pattern, (void *)t);
        else if(t==3)
            rc = pthread_create(&thread_A, NULL, print_A_pattern, (void *)t);
        else if(t==4)
            rc = pthread_create(&thread_T, NULL, print_T_pattern, (void *)t);
        else
            rc = pthread_create(&thread_H, NULL, print_H_pattern, (void *)t);
        
        if(rc){
            printf("Thread creation failed. Error code: %d\n", rc);
            exit(1);
        }
    }
    
    // Wait for all threads to complete
    pthread_join(thread_C, NULL);
    pthread_join(thread_P, NULL);
    pthread_join(thread_A, NULL);
    pthread_join(thread_T, NULL);
    pthread_join(thread_H, NULL);
    
    // Destroy lock mutex variable
    pthread_mutex_destroy(&lock);
    
    printf("\n");
    return 0;
}