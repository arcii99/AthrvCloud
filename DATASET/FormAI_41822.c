//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *shapeshift(void *shape){
    char *to_shape = (char*) shape;
    if(*to_shape == 'S'){
        printf("I am shapeshifting into a square...\n");
        *to_shape = 'Q';
    }
    else{
        printf("I am shapeshifting into a triangle...\n");
        *to_shape = 'T';
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t thread1, thread2; // Two threads
    char shape = 'S'; // Starting shape is square
    
    // Creating first thread to shapeshift from square to triangle
    int create1 = pthread_create(&thread1, NULL, shapeshift, &shape);
    
    if(create1){
        printf("Error creating thread 1.\n");
        exit(-1);
    }

    printf("Original shape: Square.\n");

    // Creating second thread to shapeshift from triangle to square
    int create2 = pthread_create(&thread2, NULL, shapeshift, &shape);

    if(create2){
        printf("Error creating thread 2.\n");
        exit(-1);
    }

    printf("Current shape: %c\n", shape);

    pthread_join(thread1, NULL); // Wait for thread 1 to finish
    pthread_join(thread2, NULL); // Wait for thread 2 to finish

    printf("Final shape: %c\n", shape);
    printf("Transformation complete!\n");

    return 0;
}