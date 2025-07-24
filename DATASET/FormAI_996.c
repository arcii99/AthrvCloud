//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: interoperable
#include <stdio.h>
#include <pthread.h>

void *print_message_function(void *ptr);

int main() {
    pthread_t thread1, thread2;
    char *message1 = "Hello, ";
    char *message2 = "world!";
    int t1, t2;
  
    t1 = pthread_create(&thread1, NULL, print_message_function, (void *) message1);
    if (t1){
        printf("Error:unable to create thread1, %d\n", t1);
        return 1;
    }
  
    t2 = pthread_create(&thread2, NULL, print_message_function, (void *) message2);
    if (t2){
        printf("Error:unable to create thread2, %d\n", t2);
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

void *print_message_function( void *ptr ){
    char *message;
    message = (char *) ptr;
    printf("%s ", message);
    pthread_exit(NULL);
}