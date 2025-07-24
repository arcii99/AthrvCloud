//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VEHICLES 10
#define MAX_COMMANDS 20

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int id;
    Position position;
    int battery_level;
    int max_speed;
    int is_turned_on;
} Vehicle;

void print_vehicle(Vehicle* v) {
    printf("ID: %d\n", v->id);
    printf("Position: (%d, %d)\n", v->position.x, v->position.y);
    printf("Battery Level: %d%%\n", v->battery_level);
    printf("Max Speed: %d km/h\n", v->max_speed);
    printf("Is Turned On: %s\n", v->is_turned_on ? "Yes" : "No");
}

void move_vehicle(Vehicle* v, Position p) {
    printf("Moving vehicle %d from (%d, %d) to (%d, %d)\n", v->id, v->position.x, v->position.y, p.x, p.y);
    v->position = p;
}

void turn_on_vehicle(Vehicle* v) {
    printf("Turning on vehicle %d\n", v->id);
    v->is_turned_on = 1;
}

void turn_off_vehicle(Vehicle* v) {
    printf("Turning off vehicle %d\n", v->id);
    v->is_turned_on = 0;
}

void recharge_battery(Vehicle* v) {
    printf("Recharging battery of vehicle %d\n", v->id);
    v->battery_level = 100;
}

void send_command(Vehicle* v, char* command) {
    printf("Sending command \"%s\" to vehicle %d\n", command, v->id);
    if (strcmp(command, "move") == 0) {
        Position p = {rand() % 100, rand() % 100};
        move_vehicle(v, p);
    } else if (strcmp(command, "turn_on") == 0) {
        turn_on_vehicle(v);
    } else if (strcmp(command, "turn_off") == 0) {
        turn_off_vehicle(v);
    } else if (strcmp(command, "recharge") == 0) {
        recharge_battery(v);
    } else {
        printf("Unknown command \"%s\"\n", command);
    }
}

int main() {
    srand(time(NULL));
    Vehicle vehicles[MAX_VEHICLES];
    int num_vehicles = 0;

    printf("Creating vehicles...\n");
    for (int i = 0; i < MAX_VEHICLES / 2; i++) {
        Position p = {rand() % 100, rand() % 100};
        Vehicle v = {i, p, 100, 50, 0};
        vehicles[num_vehicles++] = v;
    }
    for (int i = MAX_VEHICLES / 2; i < MAX_VEHICLES; i++) {
        Position p = {rand() % 100, rand() % 100};
        Vehicle v = {i, p, 100, 80, 0};
        vehicles[num_vehicles++] = v;
    }

    printf("\nVehicles created:\n");
    for (int i = 0; i < num_vehicles; i++) {
        print_vehicle(&vehicles[i]);
    }

    printf("\nSimulating remote control...\n");
    char commands[MAX_COMMANDS][10] = {"move", "turn_on", "turn_off", "recharge", "jump"};
    int num_commands = sizeof(commands) / sizeof(commands[0]);
    for (int i = 0; i < num_commands; i++) {
        int vehicle_idx = rand() % num_vehicles;
        char* command = commands[rand() % num_commands];
        send_command(&vehicles[vehicle_idx], command);
    }

    printf("\nFinal state of vehicles:\n");
    for (int i = 0; i < num_vehicles; i++) {
        print_vehicle(&vehicles[i]);
    }

    return 0;
}