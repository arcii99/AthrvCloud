//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: thoughtful
#include<stdio.h>

struct Vehicle {
    int x, y;
    int speed;
};

void move_forward(struct Vehicle* v) {
    v->y += v->speed;
}

void move_backward(struct Vehicle* v) {
    v->y -= v->speed;
}

void move_left(struct Vehicle* v) {
    v->x -= v->speed;
}

void move_right(struct Vehicle* v) {
    v->x += v->speed;
}

void print_position(struct Vehicle* v) {
    printf("Vehicle position is (%d, %d)\n", v->x, v->y);
}

int main() {

    struct Vehicle my_car = { 0, 0, 5 };
    print_position(&my_car);

    move_forward(&my_car);
    print_position(&my_car);

    move_right(&my_car);
    print_position(&my_car);

    move_backward(&my_car);
    print_position(&my_car);

    move_left(&my_car);
    print_position(&my_car);

    return 0;
}