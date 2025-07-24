//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(NULL)); // seed for random number generator
    
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You find yourself in front of an old, decrepit house. Do you want to enter?\n");
    
    char response[10];
    scanf("%s", response); // take user input
    
    if (strcmp(response, "yes") == 0 || strcmp(response, "Yes") == 0) {
        printf("You cautiously open the door and step inside.\n");
    } else {
        printf("You decide not to take your chances and walk away.\n");
        return;
    }
    
    int room = 0;
    int ghost = rand() % 4; // randomly choose a room for the ghost to appear in
    int spider = rand() % 4; // randomly choose a room for the spider to appear in
    int key = rand() % 4; // randomly choose a room for the key to appear in
    
    while (room < 5) {
        
        printf("\nYou are in room %d.\n", room);
        
        if (room == ghost) {
            printf("OH NO! You see a ghost appear in front of you!\n");
        }
        
        if (room == spider) {
            printf("EWW! A giant spider crawls towards you.\n");
        }
        
        if (room == key) {
            printf("You search the room and find a key!\n");
        }
        
        if (room == 4) {
            printf("\nYou reach the end of the haunted house! Congratulations!\n");
            return;
        }
        
        printf("\nWhich direction do you want to go? (north/south/east/west)\n");
        scanf("%s", response);
        
        if (strcmp(response, "north") == 0 || strcmp(response, "North") == 0) {
            room++;
        } else if (strcmp(response, "south") == 0 || strcmp(response, "South") == 0) {
            room--;
        } else if (strcmp(response, "east") == 0 || strcmp(response, "East") == 0) {
            room += 2;
        } else if (strcmp(response, "west") == 0 || strcmp(response, "West") == 0) {
            room -= 2;
        } else {
            printf("\nInvalid direction. Please try again.\n");
        }
    }
    
    return 0;
}