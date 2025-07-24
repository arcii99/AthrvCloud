//FormAI DATASET v1.0 Category: Robot movement control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 0
#define MAX_ANGLE 180
#define MIN_ANGLE 0
#define MAX_DISTANCE 100
#define MIN_DISTANCE 0

typedef struct robot {
    int speed;
    int angle;
    int distance;
} Robot;

void move_forward(Robot *robot) {
    int rand_distance = (rand() % MAX_DISTANCE) + MIN_DISTANCE;
    robot->distance += rand_distance;
}

void turn_left(Robot *robot) {
    int rand_angle = (rand() % (robot->angle + 1)) + MIN_ANGLE;
    robot->angle -= rand_angle;
}

void turn_right(Robot *robot) {
    int rand_angle = (rand() % (MAX_ANGLE - robot->angle + 1)) + MIN_ANGLE;
    robot->angle += rand_angle;
}

void speed_up(Robot *robot) {
    int rand_speed = (rand() % (MAX_SPEED - robot->speed + 1)) + MIN_SPEED;
    robot->speed += rand_speed;
}

void slow_down(Robot *robot) {
    int rand_speed = (rand() % (robot->speed + 1)) + MIN_SPEED;
    robot->speed -= rand_speed;
}

void print_status(Robot *robot) {
    printf("Robot status: speed=%d angle=%d distance=%d\n", robot->speed, robot->angle, robot->distance);
}

int main() {
    srand(time(NULL));
    
    Robot my_robot;
    my_robot.speed = 0;
    my_robot.angle = 90;
    my_robot.distance = 0;
    
    print_status(&my_robot);

    for (int i = 0; i < 10; i++) {
        int action = rand() % 5;

        if (action == 0) {
            move_forward(&my_robot);
            printf("Action %d: Moving forward by %d units\n", i + 1, my_robot.distance);
        }
        else if (action == 1) {
            turn_left(&my_robot);
            printf("Action %d: Turning left by %d degrees\n", i + 1, my_robot.angle);
        }
        else if (action == 2) {
            turn_right(&my_robot);
            printf("Action %d: Turning right by %d degrees\n", i + 1, my_robot.angle);
        }
        else if (action == 3) {
            speed_up(&my_robot);
            printf("Action %d: Speeding up to %d units\n", i + 1, my_robot.speed);
        }
        else {
            slow_down(&my_robot);
            printf("Action %d: Slowing down to %d units\n", i + 1, my_robot.speed);
        }
        
        print_status(&my_robot);
    }
    
    return 0;
}