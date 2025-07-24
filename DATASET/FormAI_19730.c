//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: peaceful
#include <stdio.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_DIRECTION 90
#define MIN_DIRECTION -90

typedef struct {
    int speed;
    int heading;
} Car;

void print_car_status(Car* car) {
    printf("Car status:\n");
    printf("\tSpeed: %d\n", car->speed);
    printf("\tHeading: %d\n", car->heading);
}

void change_speed(Car* car, int speed_change) {
    car->speed += speed_change;

    if (car->speed > MAX_SPEED) {
        car->speed = MAX_SPEED;
    } else if (car->speed < MIN_SPEED) {
        car->speed = MIN_SPEED;
    }
}

void turn(Car* car, int direction_change) {
    car->heading += direction_change;

    if (car->heading > MAX_DIRECTION) {
        car->heading = MAX_DIRECTION;
    } else if (car->heading < MIN_DIRECTION) {
        car->heading = MIN_DIRECTION;
    }
}

int main() {
    Car my_car = {
        .speed = 0,
        .heading = 0
    };

    print_car_status(&my_car);

    // Accelerate
    change_speed(&my_car, 10);
    print_car_status(&my_car);

    // Turn right
    turn(&my_car, 30);
    print_car_status(&my_car);

    // Decelerate
    change_speed(&my_car, -20);
    print_car_status(&my_car);

    // Turn left
    turn(&my_car, -60);
    print_car_status(&my_car);

    return 0;
}