//FormAI DATASET v1.0 Category: Robot movement control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

pthread_mutex_t lock; // mutex lock for shared variables

int robot_x, robot_y; // robot's position on grid
int obstacle_x, obstacle_y; // obstacle's position on grid

void* update_robot_position(void* arg);
void* update_obstacle_position(void* arg);

int main() {
    srand(time(NULL)); // seed random number generator
    
    robot_x = rand() % 10;
    robot_y = rand() % 10;
    obstacle_x = rand() % 10;
    obstacle_y = rand() % 10;
    
    pthread_t thread1, thread2; // threads for updating robot and obstacle positions
    
    pthread_mutex_init(&lock, NULL); // initialize mutex lock
    
    pthread_create(&thread1, NULL, update_robot_position, NULL); // create thread for robot
    pthread_create(&thread2, NULL, update_obstacle_position, NULL); // create thread for obstacle
    
    pthread_join(thread1, NULL); // wait for threads to finish
    pthread_join(thread2, NULL);
    
    pthread_mutex_destroy(&lock); // destroy mutex lock
    
    return 0;
}

void* update_robot_position(void* arg) {
    while(1) {
        int new_x = rand() % 10;
        int new_y = rand() % 10;
        
        pthread_mutex_lock(&lock); // acquire lock
        
        if(abs(new_x - obstacle_x) <= 1 && abs(new_y - obstacle_y) <= 1) { // check if robot will collide with obstacle
            printf("Robot cannot move to (%d,%d) - obstacle in the way\n", new_x, new_y);
        } else {
            robot_x = new_x;
            robot_y = new_y;
            printf("Robot moved to (%d,%d)\n", robot_x, robot_y);
        }
        
        pthread_mutex_unlock(&lock); // release lock
        
        usleep(500000); // wait for 0.5 seconds before updating position again
    }
}

void* update_obstacle_position(void* arg) {
    while(1) {
        int new_x = rand() % 10;
        int new_y = rand() % 10;
        
        pthread_mutex_lock(&lock); // acquire lock
        
        obstacle_x = new_x;
        obstacle_y = new_y;
        printf("Obstacle moved to (%d,%d)\n", obstacle_x, obstacle_y);
        
        pthread_mutex_unlock(&lock); // release lock
        
        usleep(1000000); // wait for 1 second before updating position again
    }
}