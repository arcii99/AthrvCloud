//FormAI DATASET v1.0 Category: Robot movement control ; Style: asynchronous
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define LEFT_WHEEL 0
#define RIGHT_WHEEL 1

#define MOVE_FORWARD 1
#define MOVE_BACKWARD -1
#define STOP 0

#define MAX_SPEED 100
#define MIN_SPEED 0

typedef struct {
    int speed;
    int direction;
} Wheel;

typedef struct {
    bool left_sensor;
    bool right_sensor;
} Sensor;

typedef struct {
    Wheel left_wheel;
    Wheel right_wheel;
    Sensor sensor;
} Robot;

// Function to randomly generate sensor data for testing
Sensor generate_sensor_data() {
    Sensor sensor = {rand() % 2, rand() % 2};
    return sensor;
}

// Function to set the speed of a wheel
void set_wheel_speed(Wheel* wheel, int speed) {
    if (speed > MAX_SPEED) {
        wheel->speed = MAX_SPEED;
    } else if (speed < MIN_SPEED) {
        wheel->speed = MIN_SPEED;
    } else {
        wheel->speed = speed;
    }
}

// Function to move the robot forward
void move_forward(Robot* robot) {
    set_wheel_speed(&robot->left_wheel, MAX_SPEED);
    set_wheel_speed(&robot->right_wheel, MAX_SPEED);
    robot->left_wheel.direction = MOVE_FORWARD;
    robot->right_wheel.direction = MOVE_FORWARD;
}

// Function to move the robot backward
void move_backward(Robot* robot) {
    set_wheel_speed(&robot->left_wheel, MAX_SPEED);
    set_wheel_speed(&robot->right_wheel, MAX_SPEED);
    robot->left_wheel.direction = MOVE_BACKWARD;
    robot->right_wheel.direction = MOVE_BACKWARD;
}

// Function to stop the robot
void stop_robot(Robot* robot) {
    set_wheel_speed(&robot->left_wheel, STOP);
    set_wheel_speed(&robot->right_wheel, STOP);
    robot->left_wheel.direction = STOP;
    robot->right_wheel.direction = STOP;
}

// Function to turn the robot left
void turn_left(Robot* robot) {
    set_wheel_speed(&robot->left_wheel, MAX_SPEED / 2);
    set_wheel_speed(&robot->right_wheel, MAX_SPEED / 2);
    robot->left_wheel.direction = MOVE_BACKWARD;
    robot->right_wheel.direction = MOVE_FORWARD;
}

// Function to turn the robot right
void turn_right(Robot* robot) {
    set_wheel_speed(&robot->left_wheel, MAX_SPEED / 2);
    set_wheel_speed(&robot->right_wheel, MAX_SPEED / 2);
    robot->left_wheel.direction = MOVE_FORWARD;
    robot->right_wheel.direction = MOVE_BACKWARD;
}

// Function to check the sensor data and make a decision on robot movement
void decide_movement(Robot* robot) {
    if (robot->sensor.left_sensor && robot->sensor.right_sensor) {
        stop_robot(robot);
    } else if (robot->sensor.left_sensor) {
        turn_right(robot);
    } else if (robot->sensor.right_sensor) {
        turn_left(robot);
    } else {
        move_forward(robot);
    }
}

int main() {
    Robot robot = { {0, STOP}, {0, STOP}, {false, false} };
    srand(time(NULL));
    for (int i = 0; i < 50; i++) {
        // Generate random sensor data for testing
        robot.sensor = generate_sensor_data();
        // Make a decision on robot movement
        decide_movement(&robot);
        // Print out the current speed and direction of each wheel
        printf("Left wheel speed: %d | Right wheel speed: %d\n", robot.left_wheel.speed, robot.right_wheel.speed);
        printf("Left wheel direction: %d | Right wheel direction: %d\n", robot.left_wheel.direction, robot.right_wheel.direction);
    }
    return 0;
}