//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20
#define MAX_SPEED 5
#define STREET_LENGTH 20
#define DELAY 1000

struct Car {
    int speed;
    int position;
    char symbol;
};

void update_car_position(struct Car *car, int direction) {
    car->position += direction * car->speed;
    if (car->position < 0) {
        car->position = 0;
    } else if (car->position >= STREET_LENGTH) {
        car->position = STREET_LENGTH - 1;
    }
}

void print_street(struct Car cars[MAX_CARS]) {
    int street[STREET_LENGTH] = {};
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].position >= 0 && cars[i].position < STREET_LENGTH) {
            street[cars[i].position] = cars[i].symbol;
        }
    }
    for (int i = 0; i < STREET_LENGTH; i++) {
        putchar(street[i] != 0 ? street[i] : '-');
    }
    putchar('\n');
}

int main() {
    srand(time(NULL));
    struct Car cars[MAX_CARS] = {};
    int num_cars = 0;

    puts("Welcome to medieval traffic flow simulation!");
    puts("Press ENTER to add a car, Q to quit.");

    char input = 0;
    while (input != 'q' && input != 'Q') {
        if (num_cars < MAX_CARS && (input = getchar()) == '\n') {
            struct Car new_car = {};
            new_car.symbol = 'A' + (num_cars++);
            new_car.speed = (rand() % MAX_SPEED) + 1;
            cars[num_cars - 1] = new_car;
        }
        print_street(cars);

        for (int i = 0; i < num_cars; i++) {
            update_car_position(&cars[i], 1);
            if (i > 0) {
                int distance_to_prev = cars[i - 1].position - cars[i].position;
                if (distance_to_prev <= 0) {
                    puts("Crash!");
                    return 0;
                } else if (distance_to_prev <= cars[i].speed) {
                    cars[i].speed = distance_to_prev - 1;
                } else {
                    cars[i].speed += 1;
                }
            }
        }

        for (int i = num_cars - 1; i >= 0; i--) {
            if (i == num_cars - 1) {
                continue;
            }
            int distance_to_next = cars[i].position - cars[i + 1].position;
            if (distance_to_next <= cars[i + 1].speed) {
                cars[i].speed = distance_to_next - 1;
            } else {
                cars[i].speed += 1;
            }
        }

        fflush(stdout);
        usleep(DELAY * 1000);
    }
    return 0;
}