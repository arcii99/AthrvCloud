//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: calm
#include <stdio.h>

#define MAX_CARS 100
#define GRID_SIZE 10

typedef enum { NORTH, SOUTH, EAST, WEST } Direction;
typedef struct car_t {
    int x, y;
    int speed;
    Direction direction;
} Car;

typedef struct grid_t {
    Car cars[MAX_CARS];
    int num_cars;
} Grid;

int main() {
    Grid grid = { {}, 0 };
    int tick = 0;

    // initialize grid with some cars
    add_car(&grid, 1, 1, NORTH);
    add_car(&grid, 2, 1, NORTH);
    add_car(&grid, 3, 1, NORTH);
    add_car(&grid, 4, 1, NORTH);
    add_car(&grid, 5, 1, NORTH);

    while (tick < 100) {
        // update cars' speeds and positions
        update_cars(&grid);

        // print grid
        print_grid(&grid);

        tick++;
    }

    return 0;
}

void add_car(Grid *grid, int x, int y, Direction direction) {
    if (grid->num_cars >= MAX_CARS)
        return;

    Car car = { x, y, 1, direction };
    grid->cars[grid->num_cars] = car;
    grid->num_cars++;
}

void update_cars(Grid *grid) {
    for (int i = 0; i < grid->num_cars; i++) {
        Car *car = &grid->cars[i];
        int new_speed = car->speed;

        // update speed based on neighboring cars and traffic rules
        // ...
        
        car->speed = new_speed;
        switch (car->direction) { // update position based on speed and direction
            case NORTH: car->y -= car->speed; break;
            case SOUTH: car->y += car->speed; break;
            case EAST: car->x += car->speed; break;
            case WEST: car->x -= car->speed; break;
        }
    }
}

void print_grid(Grid *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            int found_car = 0;

            for (int k = 0; k < grid->num_cars; k++) {
                if (grid->cars[k].x == i && grid->cars[k].y == j) {
                    printf("C");
                    found_car = 1;
                    break;
                }
            }

            if (!found_car)
                printf("-");
        }

        printf("\n");
    }

    printf("--------------------------------\n");
}