//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: artistic
/*
* A unique implementation of threading library in C.
* This program creates 3 threads that simulate an artist creating a masterpiece.
* Each thread represents a different color (red, blue, green) and they work together to create a beautiful painting.
* The painting is created by each thread adding their speciality to the painting on a shared canvas.
* Once the painting is completed all threads terminate.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // initialize mutex lock
int canvas[10][10] = {0}; // shared canvas for painting

void paint_canvas(int color, int x, int y) // function to add color to the canvas
{
    pthread_mutex_lock(&mutex); // acquire mutex lock to prevent race conditions
    canvas[x][y] += color;
    pthread_mutex_unlock(&mutex); // release mutex lock
}

void *red_artist(void *args) // artist who paints in red
{
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            paint_canvas(100, i, j); // add red to the canvas
        }
    }
    pthread_exit(NULL);
}

void *blue_artist(void *args) // artist who paints in blue
{
    for(int i=0; i<10; i+=2){
        for(int j=0; j<10; j++){
            paint_canvas(10, i, j); // add blue to the canvas
        }
    }
    pthread_exit(NULL);
}

void *green_artist(void *args) // artist who paints in green
{
    for(int i=1; i<10; i+=2){
        for(int j=0; j<10; j+=2){
            paint_canvas(1, i, j); // add green to the canvas
        }
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t red_thread, blue_thread, green_thread; // threads for each artist
    
    // create the threads
    pthread_create(&red_thread, NULL, red_artist, NULL);
    pthread_create(&blue_thread, NULL, blue_artist, NULL);
    pthread_create(&green_thread, NULL, green_artist, NULL);
    
    // wait for the threads to finish painting
    pthread_join(red_thread, NULL);
    pthread_join(blue_thread, NULL);
    pthread_join(green_thread, NULL);
    
    // print out the completed painting
    printf("Painting Complete!\n");
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            printf("%d ",canvas[i][j]); // print the colors on the canvas
        }
        printf("\n");
    }
    return 0;
}