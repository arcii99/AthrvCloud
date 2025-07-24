//FormAI DATASET v1.0 Category: Robot movement control ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SPEED 100
#define MAX_ANGLE 180

// define a structure to hold robot movement data
typedef struct {
    int speed;
    int angle;
    int distance;
    int x;
    int y;
} MovementData;

// function to control the movement of the robot
void *move_robot(void *arg) {
    MovementData *data = (MovementData *)arg;
    int x, y, d;
    int x_increment, y_increment;
    int i;

    // calculate the x and y increments based on angle and distance
    float radians = (float)data->angle * 3.14159265358979323846 / 180.0;
    x_increment = (int)(data->distance * cos(radians));
    y_increment = (int)(data->distance * sin(radians));

    // move the robot incrementally and print out position
    for (i = 0; i < data->distance; i++) {
        x = data->x + x_increment * i / data->distance;
        y = data->y + y_increment * i / data->distance;
        d = i + 1;
        printf("Distance travelled: %d x: %d y: %d\n", d, x, y);
        usleep((MAX_SPEED - data->speed) * 1000);
    }
    pthread_exit(NULL);
}

int main(void) {
    int num_threads = 3;
    pthread_t threads[num_threads];
    MovementData robot_movement[num_threads];
    int i, rc;

    // initialize movement data for each robot
    robot_movement[0].speed = 20;
    robot_movement[0].angle = 45;
    robot_movement[0].distance = 100;
    robot_movement[0].x = 0;
    robot_movement[0].y = 0;

    robot_movement[1].speed = 50;
    robot_movement[1].angle = 90;
    robot_movement[1].distance = 200;
    robot_movement[1].x = 0;
    robot_movement[1].y = 0;

    robot_movement[2].speed = 80;
    robot_movement[2].angle = 135;
    robot_movement[2].distance = 300;
    robot_movement[2].x = 0;
    robot_movement[2].y = 0;

    // create threads for each robot and start their movement
    for (i = 0; i < num_threads; i++) {
        rc = pthread_create(&threads[i], NULL, move_robot, (void *)&robot_movement[i]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    // wait for all threads to finish
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
}