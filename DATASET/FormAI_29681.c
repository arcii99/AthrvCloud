//FormAI DATASET v1.0 Category: Smart home light control ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 20
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int brightness;
} Light;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Light lights[MAX_DEVICES];
    int num_lights;
} Room;

typedef struct {
    Room rooms[MAX_DEVICES];
    int num_rooms;
} House;

void print_house(House house) {
    printf("Welcome to your smart home!\n");
    printf("You have %d rooms.\n", house.num_rooms);
    for (int i = 0; i < house.num_rooms; i++) {
        printf("%s:\n", house.rooms[i].name);
        for (int j = 0; j < house.rooms[i].num_lights; j++) {
            printf("%s - Brightness: %d\n", house.rooms[i].lights[j].name, house.rooms[i].lights[j].brightness);
        }
    }
}

void set_brightness(Room *room, char *name, int brightness) {
    for (int i = 0; i < room->num_lights; i++) {
        if (strcmp(room->lights[i].name, name) == 0) {
            room->lights[i].brightness = brightness;
            return;
        }
    }
    printf("%s not found in room %s.\n", name, room->name);
}

int main() {
    House my_house = {
        .num_rooms = 2,
        .rooms = {
            {
                .name = "Living Room",
                .lights = {
                    {
                        .name = "Main Lamp",
                        .brightness = 100
                    },
                    {
                        .name = "Table Lamp",
                        .brightness = 50
                    },
                    {
                        .name = "Ceiling Fan",
                        .brightness = 0
                    }
                },
                .num_lights = 3
            },
            {
                .name = "Bedroom",
                .lights = {
                    {
                        .name = "Overhead Light",
                        .brightness = 75
                    },
                    {
                        .name = "Bedside Lamp",
                        .brightness = 25
                    }
                },
                .num_lights = 2
            }
        }
    };

    print_house(my_house);
    set_brightness(&my_house.rooms[0], "Main Lamp", 50);
    set_brightness(&my_house.rooms[1], "Overhead Light", 100);
    print_house(my_house);

    return 0;
}