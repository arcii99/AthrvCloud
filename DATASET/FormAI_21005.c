//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20

typedef struct vehicle {
    char name[MAX_NAME_LENGTH];
    int speed;
    int battery_level;
} Vehicle;

void print_vehicle(Vehicle v) {
    printf("Vehicle Name: %s\n", v.name);
    printf("Vehicle Speed: %d\n", v.speed);
    printf("Battery Level: %d\n\n", v.battery_level);
}

void drive(Vehicle *v) {
    if(v->battery_level < 10) {
        printf("Battery level is too low to drive!");
        return;
    }
    int random_time = rand() % 10 + 1;
    printf("Driving for %d seconds...\n", random_time);
    v->battery_level -= 5;
    v->speed = rand() % 51;
    printf("New Speed: %d\n", v->speed);
    printf("New Battery Level: %d\n\n", v->battery_level);
}

void recharge(Vehicle *v) {
    printf("Recharging...\n");
    v->battery_level = 100;
    printf("New Battery Level: %d\n\n", v->battery_level);
}

int main() {
    srand(time(NULL));
    Vehicle my_vehicle;
    strcpy(my_vehicle.name, "Cybersphere");
    my_vehicle.speed = 0;
    my_vehicle.battery_level = 100;

    char input[10];
    while(1) {
        printf("Enter 'd' to drive, 'r' to recharge, or 'q' to quit: ");
        fgets(input, 10, stdin);
        if(input[0] == 'd') {
            drive(&my_vehicle);
        } else if(input[0] == 'r') {
            recharge(&my_vehicle);
        } else if(input[0] == 'q') {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid input. Try again.\n");
        }
    }

    return 0;
}