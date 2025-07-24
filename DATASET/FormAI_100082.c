//FormAI DATASET v1.0 Category: Smart home light control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Light {
    int brightness;
    bool status;
    char color[20];
};

struct Room {
    char name[20];
    struct Light lights[5]; 
};

struct House {
    struct Room rooms[5];
};

int main() {
    struct House house;
    
    strcpy(house.rooms[0].name, "Great Hall");
    strcpy(house.rooms[1].name, "Bedroom");
    strcpy(house.rooms[2].name, "Kitchen");
    strcpy(house.rooms[3].name, "Library");
    strcpy(house.rooms[4].name, "Dungeon");
    
    int currentRoom = 0;
    
    printf("Welcome to the Medieval Smart Home Light Control System!\n");
    
    while(1) {
        printf("\nYou are in the %s\n", house.rooms[currentRoom].name);
        printf("What would you like to do?\n");
        printf("1. Turn on/off the lights\n");
        printf("2. Change the brightness level\n");
        printf("3. Change the color\n");
        printf("4. Move to another room\n");
        printf("5. Exit the program\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                for(int i=0; i<5; i++) {
                    printf("The light %d is now %s\n", i+1, house.rooms[currentRoom].lights[i].status ? "off" : "on");
                    house.rooms[currentRoom].lights[i].status = !house.rooms[currentRoom].lights[i].status;
                }
                break;
                
            case 2:
                printf("Enter the brightness level (0-100): ");
                int brightness;
                scanf("%d", &brightness);
                
                for(int i=0; i<5; i++) {
                    house.rooms[currentRoom].lights[i].brightness = brightness;
                    printf("The brightness of light %d is now %d\n", i+1, house.rooms[currentRoom].lights[i].brightness);
                }
                break;
                
            case 3:
                printf("Enter the color name: ");
                char color[20];
                scanf("%s", color);
                
                for(int i=0; i<5; i++) {
                    strcpy(house.rooms[currentRoom].lights[i].color, color);
                    printf("The color of light %d is now %s\n", i+1, house.rooms[currentRoom].lights[i].color);
                }
                break;
                
            case 4:
                printf("Which room do you want to move to? (1-5): ");
                int room;
                scanf("%d", &room);
                if(room<1 || room>5) {
                    printf("Invalid room number\n");
                } else {
                    currentRoom = room-1;
                }
                break;
            
            case 5:
                printf("Exiting the program...");
                exit(0);
            
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}