//FormAI DATASET v1.0 Category: Smart home light control ; Style: medieval
#include <stdio.h>
#include <string.h>
#define MAX_ROOMS 10
#define MAX_LIGHTS 5

typedef struct {
    int brightness;
    int is_on;
} Light;

typedef struct {
    char name[20];
    Light lights[MAX_LIGHTS];
    int num_lights;
} Room;

void initialize(Room rooms[], int num_rooms) {
    for(int i = 0; i < num_rooms; i++) {
        strcpy(rooms[i].name, "");
        rooms[i].num_lights = 0;
        for(int j = 0; j < MAX_LIGHTS; j++) {
            rooms[i].lights[j].brightness = 0;
            rooms[i].lights[j].is_on = 0;
        }
    }
}

void add_room(Room rooms[], char name[], int *num_rooms) {
    if(*num_rooms >= MAX_ROOMS) {
        printf("Cannot add more rooms.\n");
        return;
    }
    
    int i;
    for(i = 0; i < *num_rooms; i++) {
        if(strcmp(rooms[i].name, name) == 0) {
            printf("Room with name %s already exists.\n", name);
            return;
        }
    }
    
    strcpy(rooms[i].name, name);
    rooms[i].num_lights = 0;
    *num_rooms += 1;
}

void add_light(Room * room, int brightness) {
    if(room->num_lights >= MAX_LIGHTS) {
        printf("Cannot add more lights to room %s.\n", room->name);
        return;
    }
    
    room->lights[room->num_lights].brightness = brightness;
    room->lights[room->num_lights].is_on = 0;
    room->num_lights += 1;
}

void switch_on(Room * room, int light_index) {
    if(light_index >= room->num_lights) {
        printf("Invalid light index.\n");
        return;
    }
    
    if(room->lights[light_index].is_on) {
        printf("Light is already on.\n");
        return;
    }
    
    room->lights[light_index].is_on = 1;
    printf("Switched on light %d in room %s.\n", light_index+1, room->name);
}

void switch_off(Room * room, int light_index) {
    if(light_index >= room->num_lights) {
        printf("Invalid light index.\n");
        return;
    }
    
    if(!room->lights[light_index].is_on) {
        printf("Light is already off.\n");
        return;
    }
    
    room->lights[light_index].is_on = 0;
    printf("Switched off light %d in room %s.\n", light_index+1, room->name);
}

void increase_brightness(Room * room, int light_index) {
    if(light_index >= room->num_lights) {
        printf("Invalid light index.\n");
        return;
    }
    
    if(!room->lights[light_index].is_on) {
        printf("Light is off. Cannot change brightness.\n");
        return;
    }
    
    if(room->lights[light_index].brightness >= 100) {
        printf("Brightness is already at maximum.\n");
        return;
    }
    
    room->lights[light_index].brightness += 10;
    printf("Increased brightness of light %d in room %s to %d.\n", light_index+1, room->name, room->lights[light_index].brightness);
}

void decrease_brightness(Room * room, int light_index) {
    if(light_index >= room->num_lights) {
        printf("Invalid light index.\n");
        return;
    }
    
    if(!room->lights[light_index].is_on) {
        printf("Light is off. Cannot change brightness.\n");
        return;
    }
    
    if(room->lights[light_index].brightness <= 0) {
        printf("Brightness is already at minimum.\n");
        return;
    }
    
    room->lights[light_index].brightness -= 10;
    printf("Decreased brightness of light %d in room %s to %d.\n", light_index+1, room->name, room->lights[light_index].brightness);
}

int main() {
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;
    
    initialize(rooms, MAX_ROOMS);
    
    add_room(rooms, "Great hall", &num_rooms);
    add_light(&rooms[0], 50);
    add_light(&rooms[0], 80);
    
    add_room(rooms, "Bedroom", &num_rooms);
    add_light(&rooms[1], 70);
    
    switch_on(&rooms[0], 0);
    switch_on(&rooms[1], 0);
    switch_on(&rooms[0], 1);
    switch_off(&rooms[1], 0);
    increase_brightness(&rooms[0], 0);
    decrease_brightness(&rooms[0], 0);
    increase_brightness(&rooms[0], 1);
    switch_on(&rooms[0], 3);
    
    return 0;
}