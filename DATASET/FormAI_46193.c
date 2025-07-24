//FormAI DATASET v1.0 Category: Smart home light control ; Style: Linus Torvalds
/*
Smart home light control program
By Linus Torvalds

This program controls the lights in a smart home using a simple interface. 
It receives user input, determines which light to control, and toggles its state.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 5
#define MAX_LIGHTS 10

// Define a struct to represent each light
typedef struct {
    char name[20];
    int state;
} Light;

// Define a struct to represent each room
typedef struct {
    char name[20];
    Light lights[MAX_LIGHTS];
    int num_lights;
} Room;

// Define a struct to represent the entire smart home
typedef struct {
    Room rooms[MAX_ROOMS];
    int num_rooms;
} SmartHome;

// Function to initialize the smart home
void init_smart_home(SmartHome *home)
{
    home->num_rooms = 0;
}

// Function to add a room to the smart home
void add_room(SmartHome *home, char *room_name)
{
    Room *room = &home->rooms[home->num_rooms];
    strncpy(room->name, room_name, sizeof(room->name));
    room->num_lights = 0;
    home->num_rooms++;
}

// Function to add a light to a room
void add_light_to_room(SmartHome *home, char *room_name, char *light_name)
{
    Room *room = NULL;
    for (int i = 0; i < home->num_rooms; i++) {
        if (strcmp(home->rooms[i].name, room_name) == 0) {
            room = &home->rooms[i];
            break;
        }
    }
    if (room == NULL) {
        printf("Error: Room not found\n");
        return;
    }
    Light *light = &room->lights[room->num_lights];
    strncpy(light->name, light_name, sizeof(light->name));
    light->state = 0;
    room->num_lights++;
}

// Function to toggle the state of a light
void toggle_light_state(SmartHome *home, char *room_name, char *light_name)
{
    Room *room = NULL;
    Light *light = NULL;
    for (int i = 0; i < home->num_rooms; i++) {
        if (strcmp(home->rooms[i].name, room_name) == 0) {
            room = &home->rooms[i];
            for (int j = 0; j < room->num_lights; j++) {
                if (strcmp(room->lights[j].name, light_name) == 0) {
                    light = &room->lights[j];
                    break;
                }
            }
            break;
        }
    }
    if (light == NULL) {
        printf("Error: Light not found\n");
        return;
    }
    light->state = !light->state;
}

int main()
{
    SmartHome home;
    init_smart_home(&home);
    add_room(&home, "Living Room");
    add_light_to_room(&home, "Living Room", "Ceiling Light");
    add_light_to_room(&home, "Living Room", "Table Lamp");
    add_room(&home, "Bedroom");
    add_light_to_room(&home, "Bedroom", "Ceiling Light");
    add_light_to_room(&home, "Bedroom", "Bedside Lamp");
    char input_room[20];
    char input_light[20];
    while (1) {
        printf("Enter room and light (e.g. Living Room Ceiling Light) to toggle state, or q to quit: ");
        scanf("%s", input_room);
        if (strcmp(input_room, "q") == 0) {
            break;
        }
        scanf("%s", input_light);
        toggle_light_state(&home, input_room, input_light);
    }
    return 0;
}