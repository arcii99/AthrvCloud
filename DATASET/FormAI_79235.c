//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FIELD_WIDTH 20
#define FIELD_HEIGHT 10

typedef enum {
    UP, DOWN, LEFT, RIGHT
} Direction;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int battery;
} RCVehicle;

char field[FIELD_HEIGHT][FIELD_WIDTH];
RCVehicle vehicle;

void clearField() {
    for(int i = 0; i < FIELD_HEIGHT; i++) {
        for(int j = 0; j < FIELD_WIDTH; j++) {
            field[i][j] = '.';
        }
    }
}

void printField() {
    printf("Battery Level: %d\n", vehicle.battery);
    for(int i = 0; i < FIELD_HEIGHT; i++) {
        for(int j = 0; j < FIELD_WIDTH; j++) {
            printf("%c ", field[i][j]);
        }
        printf("\n");
    }
}

void placeVehicle() {
    vehicle.pos.x = rand() % FIELD_WIDTH;
    vehicle.pos.y = rand() % FIELD_HEIGHT;
    vehicle.battery = rand() % 10 + 1;

    field[vehicle.pos.y][vehicle.pos.x] = 'X';
}

bool moveVehicle(Direction dir) {
    int new_x = vehicle.pos.x;
    int new_y = vehicle.pos.y;

    switch(dir) {
        case UP:
            new_y--;
            break;
        case DOWN:
            new_y++;
            break;
        case LEFT:
            new_x--;
            break;
        case RIGHT:
            new_x++;
            break;
        default:
            return false;
    }

    if(new_x < 0 || new_x >= FIELD_WIDTH || new_y < 0 || new_y >= FIELD_HEIGHT) {
        return false;
    }

    field[vehicle.pos.y][vehicle.pos.x] = '.';
    vehicle.pos.x = new_x;
    vehicle.pos.y = new_y;

    if(field[vehicle.pos.y][vehicle.pos.x] == 'o') {
        if(vehicle.battery < 10) {
            vehicle.battery++;
        }
    } else if(field[vehicle.pos.y][vehicle.pos.x] == 'X') {
        vehicle.battery--;
        if(vehicle.battery == 0) {
            printf("Game Over - Battery Depleted\n");
            exit(0);
        }
    }

    field[vehicle.pos.y][vehicle.pos.x] = 'X';

    return true;
}

int main() {
    srand(time(NULL));
    clearField();
    placeVehicle();

    for(int i = 0; i < 5; i++) {
        int x = rand() % FIELD_WIDTH;
        int y = rand() % FIELD_HEIGHT;
        field[y][x] = 'o';
    }

    while(true) {
        printField();

        printf("Enter your move (u/d/l/r): ");
        char input;
        scanf(" %c", &input);

        switch(input) {
            case 'u':
                moveVehicle(UP);
                break;
            case 'd':
                moveVehicle(DOWN);
                break;
            case 'l':
                moveVehicle(LEFT);
                break;
            case 'r':
                moveVehicle(RIGHT);
                break;
            default:
                printf("Invalid input. Try again.\n");
                break;
        }
    }

    return 0;
}