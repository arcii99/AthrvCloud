//FormAI DATASET v1.0 Category: Smart home light control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    // Light control initialization
    bool room1_light = false; // Light in the first room is off by default
    bool room2_light = false; // Light in the second room is off by default
    bool living_room_light = false; // Light in the living room is off by default
    
    // Display the welcome message
    printf("Welcome to the Smart Home Light Control Program!\n");
    
    // Display the current status of the lights
    printf("\nCurrent Light Status:\nRoom 1: %s\nRoom 2: %s\nLiving Room: %s\n", room1_light ? "On" : "Off", room2_light ? "On" : "Off", living_room_light ? "On" : "Off");
    
    // Prompt the user to select a room to control the light
    printf("\nSelect a room to control the light:\n1. Room 1\n2. Room 2\n3. Living Room\n");
    int room_selection;
    scanf("%d", &room_selection);
    
    // Control the light in the selected room
    switch(room_selection) {
        case 1:
            room1_light = !room1_light;
            printf("Room 1 light turned %s\n", room1_light ? "On" : "Off");
            break;
        case 2:
            room2_light = !room2_light;
            printf("Room 2 light turned %s\n", room2_light ? "On" : "Off");
            break;
        case 3:
            living_room_light = !living_room_light;
            printf("Living Room light turned %s\n", living_room_light ? "On" : "Off");
            break;
        default:
            printf("Invalid selection, please try again.\n");
            break;
    }
    
    // Display the updated status of the lights
    printf("\nUpdated Light Status:\nRoom 1: %s\nRoom 2: %s\nLiving Room: %s\n", room1_light ? "On" : "Off", room2_light ? "On" : "Off", living_room_light ? "On" : "Off");
    
    return 0;
}