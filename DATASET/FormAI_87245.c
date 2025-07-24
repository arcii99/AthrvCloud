//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: paranoid
#include <stdio.h>  
#include <stdlib.h>  
#include <pthread.h>  
  
// Define the thread arguments structure.  
struct thread_args {  
    int thread_num;  
    char *message;  
};  
  
// Define the paranoid mutex. The paranoid mutex is a mutex that logs each lock and unlock operation.  
struct paranoid_mutex {  
    pthread_mutex_t mutex;  
    char *name;  
};  
  
void paranoid_init_mutex(struct paranoid_mutex *mutex, char *name) {  
    int rc = pthread_mutex_init(&mutex->mutex, NULL);  
    if (rc != 0) {  
        fprintf(stderr, "Failed to initialize mutex %s: %s\n", name, strerror(rc));  
        exit(rc);  
    }  
    mutex->name = name;  
}  
  
void paranoid_lock_mutex(struct paranoid_mutex *mutex) {  
    printf("Thread %lu locking mutex %s...\n", pthread_self(), mutex->name);  
    int rc = pthread_mutex_lock(&mutex->mutex);  
    if (rc != 0) {  
        fprintf(stderr, "Failed to lock mutex %s: %s\n", mutex->name, strerror(rc));  
        exit(rc);  
    }  
}  
  
void paranoid_unlock_mutex(struct paranoid_mutex *mutex) {  
    printf("Thread %lu unlocking mutex %s...\n", pthread_self(), mutex->name);  
    int rc = pthread_mutex_unlock(&mutex->mutex);  
    if (rc != 0) {  
        fprintf(stderr, "Failed to unlock mutex %s: %s\n", mutex->name, strerror(rc));  
        exit(rc);  
    }  
}  
  
// Define the thread routine.  
void *thread_routine(void *arg) {  
    struct thread_args *args = arg;  
    printf("Thread %d: %s\n", args->thread_num, args->message);  
  
    struct paranoid_mutex mutex;  
    paranoid_init_mutex(&mutex, "test_mutex");  
    paranoid_lock_mutex(&mutex);  
    paranoid_unlock_mutex(&mutex);  
  
    pthread_exit(NULL);  
}  
  
int main() {  
    // Create the threads.  
    pthread_t tid1, tid2;  
    struct thread_args args1 = {1, "Hello, world!"};  
    struct thread_args args2 = {2, "Goodbye, world!"};  
    pthread_create(&tid1, NULL, thread_routine, &args1);  
    pthread_create(&tid2, NULL, thread_routine, &args2);  
  
    // Wait for the threads to complete.  
    pthread_join(tid1, NULL);  
    pthread_join(tid2, NULL);  
  
    return 0;  
}