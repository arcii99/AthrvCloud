//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 20
#define MAX_DOORS 5

struct room {
    int id;
    char name[20];
    int doors[MAX_DOORS];
};

typedef struct room Room;

void print_room(Room r) {
    printf("Room %d: %s\nDoors: ", r.id, r.name);
    for(int i=0; i<MAX_DOORS; i++) {
        if(r.doors[i]) printf("%d, ", i+1);
    }
    printf("\n\n");
}

int main() {
    // generate random names for rooms
    char names[MAX_ROOMS][20] = {"The Matrix", "Neo's Hideout", "Blade Runner HQ", "Dystopian Avenue", "Tech Noir", 
                                 "The Hacker's Den", "Ghost in the Shell", "Shadowrun Central", "Cyberpunk City",
                                 "Chrome House", "The Net", "Mega-City One", "Protocol 9", "Cyberspace Station",
                                 "Neurotech Tower", "The Grid", "Midnight City", "Synthwave Square", "Memory Lane",
                                 "Digital Fortress"};
    
    // create an array of rooms
    Room rooms[MAX_ROOMS];
    
    // initialize the rooms
    for(int i=0; i<MAX_ROOMS; i++) {
        rooms[i].id = i+1;
        strcpy(rooms[i].name, names[i]);
        for(int j=0; j<MAX_DOORS; j++) {
            rooms[i].doors[j] = rand() % 2; // randomly assign doors to rooms
        }
    }
    
    printf("Welcome to the Cyberpunk Maze.\n\n");
    printf("Your goal is to find the exit, which is located in Room %d.\n\n", MAX_ROOMS);
    
    // start the game in the first room
    Room current_room = rooms[0];
    print_room(current_room);
    
    // loop until the exit is found
    int exit_found = 0;
    while(!exit_found) {
        int next_room = -1;
        
        // find the next room with an open door
        for(int i=0; i<MAX_DOORS; i++) {
            if(current_room.doors[i] && i+1 != current_room.id) {
                next_room = i+1;
                break;
            }
        }
        
        // if there is an open door, move to the next room
        if(next_room > 0) {
            printf("You move to Room %d.\n\n", next_room);
            current_room = rooms[next_room-1];
            print_room(current_room);
            
            // check if the exit has been found
            if(current_room.id == MAX_ROOMS) {
                printf("Congratulations! You have found the exit!\n");
                exit_found = 1;
            }
        }
        
        // if there are no open doors, backtrack to the previous room
        else {
            printf("There are no open doors in this room. You backtrack to the previous room.\n\n");
            current_room = rooms[current_room.id-2];
            print_room(current_room);
        }
    }
    
    return 0;
}