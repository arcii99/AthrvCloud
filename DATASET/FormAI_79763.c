//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* zombie(void* arg); //Thread function 

int main(){
    pthread_t zombie1, zombie2, zombie3, zombie4; //Create 4 threads
    
    pthread_create(&zombie1, NULL, zombie, "Thread 1"); //Start thread 1
    pthread_create(&zombie2, NULL, zombie, "Thread 2"); //Start thread 2
    pthread_create(&zombie3, NULL, zombie, "Thread 3"); //Start thread 3
    pthread_create(&zombie4, NULL, zombie, "Thread 4"); //Start thread 4
    
    usleep(5000000); // Let the zombies roam for 5 seconds
    
    pthread_cancel(zombie1); // Stop thread 1
    pthread_cancel(zombie2); // Stop thread 2
    pthread_cancel(zombie3); // Stop thread 3
    pthread_cancel(zombie4); // Stop thread 4
    
    return 0;
}

void* zombie(void* arg){
    int position = 0; // Initial position of zombie
    int direction = 1; //Initial direction of zombie
    
    while(1){ // Run indefinitely until thread is cancelled
        if(position == 0){ // Check if zombie has hit the wall
            direction = 1; // Switch direction
        }
        if(position == 80){ // Check if zombie has hit the opposite wall
            direction = -1; // Switch direction
        }
        
        position += direction; // Move the zombie in the given direction
        
        printf("%s- position: %d\n", (char*)arg, position); // Print the current position of the zombie
        
        usleep(50000); // Slow down the zombie's speed 
        
        pthread_testcancel(); // Check if the thread is cancelled, if yes then stop running
    }
}