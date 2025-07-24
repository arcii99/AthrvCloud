//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

// Define game function and room structure
void game();
struct Room{
    char name[50];
    char description[200];
    int north;
    int south;
    int east;
    int west;
};
typedef struct Room Room;

// Define a function to get user input as string and trim whitespace
void getInput(char *input){
    fgets(input, 100, stdin);
    int i;
    for(i=0; i<strlen(input); i++){
        if(input[i] == '\n'){
            input[i] = '\0';
        }
    }
}

int main(){
    // Initialize game
    printf("Welcome to Adventure Game!\n");
    game();
    return 0;
}

void game(){
    // Initialize rooms
    Room current = {"Entryway", "You are in a dimly lit entryway. There are doors to the north and south.", 1, 2, 0, 0};
    Room northRoom = {"North Room", "You are in a room filled with treasure. You win!", 0, 0, 0, 1};
    Room southRoom = {"South Room", "You are in a room filled with danger. You lose!", 1, 0, 0, 0};
    Room rooms[] = {current, northRoom, southRoom};
    
    // Initialize game loop
    int gameover = 0;
    while(!gameover){
        // Display current room
        printf("\n\n%s\n", current.name);
        printf("%s\n", current.description);
        printf("\nWhat do you want to do?\n");
        char input[100];
        getInput(input);

        // Check user input and move between rooms
        if(strcmp(input, "north") == 0){
            if(current.north != 0){
                current = rooms[current.north];
            }
            else{
                printf("\nThere is no door to the north.");
            }   
        }
        else if(strcmp(input, "south") == 0){
            if(current.south != 0){
                current = rooms[current.south];
            }
            else{
                printf("\nThere is no door to the south.");
            }   
        }
        else if(strcmp(input, "east") == 0){
            if(current.east != 0){
                current = rooms[current.east];
            }
            else{
                printf("\nThere is no door to the east.");
            }   
        }
        else if(strcmp(input, "west") == 0){
            if(current.west != 0){
                current = rooms[current.west];
            }
            else{
                printf("\nThere is no door to the west.");
            }   
        }
        else if(strcmp(input, "quit") == 0){
            printf("\nThanks for playing!\n");
            gameover = 1;
        }
        else{
            printf("\nI don't understand that command. Please enter north, south, east, west, or quit.");
        }

        // Check for game over
        if(strcmp(current.name, "North Room") == 0){
            printf("\nCongratulations, you win!\n");
            gameover = 1;
        }
        else if(strcmp(current.name, "South Room") == 0){
            printf("\nSorry, you lose!\n");
            gameover = 1;
        }
    }
}