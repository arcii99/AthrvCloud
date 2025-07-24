//FormAI DATASET v1.0 Category: Robot movement control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_ROBOTS 5
#define MAX_SPEED 10

void *robot_function(void *robot_id);

struct Robot {
    int id;
    int x;
    int y;
    int speed;
    int direction;
    pthread_t thread_id;
};

struct Robot robots[NUM_ROBOTS];

int main() {
    srand(time(NULL));
    for(int i=0; i<NUM_ROBOTS; i++) {
        robots[i].id = i+1;
        robots[i].x = rand()%100;
        robots[i].y = rand()%100;
        robots[i].speed = rand()%MAX_SPEED + 1; 
        robots[i].direction = rand()%360;
        pthread_create(&robots[i].thread_id, NULL, robot_function, (void*)&robots[i]);
    }
    for(int i=0; i<NUM_ROBOTS; i++) {
        pthread_join(robots[i].thread_id, NULL);
    }
    return 0;
}

void *robot_function(void *robot) {
    struct Robot *r = (struct Robot*)robot;
    printf("Robot %d started at location (%d, %d) with speed %d and direction %d degrees\n", 
           r->id, r->x, r->y, r->speed, r->direction);
    while(1) {
        int step = r->speed;
        int dx = step * cos(r->direction);
        int dy = step * sin(r->direction);
        r->x += dx;
        r->y += dy;
        if(r->x < 0 || r->x > 100 || r->y < 0 || r->y > 100) {
            r->x -= dx;
            r->y -= dy;
            r->direction = rand()%360;
        }
        printf("Robot %d moved to location (%d, %d) with direction %d degrees\n", 
               r->id, r->x, r->y, r->direction);
        // Sleep for a random number of seconds between 1 and 5
        int sleep_time = rand()%5 + 1;
        printf("Robot %d is sleeping for %d seconds...\n", r->id, sleep_time);
        sleep(sleep_time);
    }
}