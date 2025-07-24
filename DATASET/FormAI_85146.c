//FormAI DATASET v1.0 Category: Smart home light control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROOMS 5
#define MAX_LIGHTS 10

// Define Light struct
typedef struct Light {
    int id;
    bool status;
} Light;

// Define Room struct
typedef struct Room {
    int id;
    int num_lights;
    Light lights[MAX_LIGHTS]; // Up to 10 lights per room
} Room;

// Define Home struct
typedef struct Home {
    int num_rooms;
    Room rooms[MAX_ROOMS]; // Up to 5 rooms in the home
} Home;

// Define function to toggle light status
void toggle_light_status(Light *light) {
    light->status = !light->status;
}

// Define function to print all lights and their statuses in a room
void print_room_lights(Room *room) {
    printf("Room %d Lights:\n", room->id);
    for (int i = 0; i < room->num_lights; i++) {
        printf("Light %d: %s\n", room->lights[i].id, room->lights[i].status ? "ON" : "OFF");
    }
}

// Main function
int main() {
    // Create home with 2 rooms and 3 lights per room
    Home my_home = {2, {
        {1, 3, {
            {1, false},
            {2, true},
            {3, false}
        }},
        {2, 3, {
            {4, false},
            {5, true},
            {6, false}
        }}
    }};

    // Print current state of home's lights
    for (int i = 0; i < my_home.num_rooms; i++) {
        print_room_lights(&my_home.rooms[i]);
    }

    // Let the user toggle lights on/off
    int selected_light_id;
    for (;;) {
        printf("Enter a light ID to toggle its status (or -1 to exit): ");
        scanf("%d", &selected_light_id);
        if (selected_light_id == -1) {
            break;
        }
        bool light_found = false;
        for (int i = 0; i < my_home.num_rooms; i++) {
            Room *room = &my_home.rooms[i];
            for (int j = 0; j < room->num_lights; j++) {
                if (room->lights[j].id == selected_light_id) {
                    toggle_light_status(&room->lights[j]);
                    light_found = true;
                    break;
                }
            }
            if (light_found) {
                break;
            }
        }
        if (!light_found) {
            printf("Invalid light ID entered.\n");
        } else {
            // Print updated state of home's lights
            for (int i = 0; i < my_home.num_rooms; i++) {
                print_room_lights(&my_home.rooms[i]);
            }
        }
    }

    return 0;
}