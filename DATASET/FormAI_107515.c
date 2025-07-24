//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define the map size and character movement
#define MAP_SIZE 30
#define MOVE_LEFT -1
#define MOVE_RIGHT 1
#define MOVE_UP -1
#define MOVE_DOWN 1

//Function prototypes
void generate_map(char map[MAP_SIZE][MAP_SIZE]);
void print_map(char map[MAP_SIZE][MAP_SIZE]);
void move_player(char map[MAP_SIZE][MAP_SIZE], int moveX, int moveY);

//Main function
int main(){
    //Initialize random seed
    srand(time(NULL));
    
    //Initialize map array
    char map[MAP_SIZE][MAP_SIZE];
    
    //Generate map
    generate_map(map);
    
    //Print initial map
    print_map(map);
    
    //Loop for player movements
    while(1){
        //Get player movement from user
        int moveX, moveY;
        printf("\nEnter your movement: ");
        scanf("%d %d", &moveX, &moveY);
        
        //Move player
        move_player(map, moveX, moveY);
        
        //Print updated map
        print_map(map);
    }
    
    return 0;
}

//Function to generate random map
void generate_map(char map[MAP_SIZE][MAP_SIZE]){
    //Loop through each cell in the map
    for(int i=0; i<MAP_SIZE; i++){
        for(int j=0; j<MAP_SIZE; j++){
            //Randomly assign a terrain type to the cell
            int terrain = rand() % 3;
            switch(terrain){
                case 0: map[i][j] = '.'; break; //Grass
                case 1: map[i][j] = '#'; break; //Wall
                case 2: map[i][j] = '~'; break; //Water
            }
        }
    }
    
    //Set player position in the center of the map
    map[MAP_SIZE/2][MAP_SIZE/2] = '@';
}

//Function to print the map
void print_map(char map[MAP_SIZE][MAP_SIZE]){
    //Clear the screen
    system("cls");
    
    //Loop through each cell in the map
    for(int i=0; i<MAP_SIZE; i++){
        for(int j=0; j<MAP_SIZE; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

//Function to move the player
void move_player(char map[MAP_SIZE][MAP_SIZE], int moveX, int moveY){
    //Find the current player position
    int playerX, playerY;
    for(int i=0; i<MAP_SIZE; i++){
        for(int j=0; j<MAP_SIZE; j++){
            if(map[i][j] == '@'){
                playerX = i;
                playerY = j;
            }
        }
    }
    
    //Calculate the new player position
    int newPlayerX = playerX + moveY;
    int newPlayerY = playerY + moveX;
    
    //Check if new position is within map bounds and not a wall
    if(newPlayerX >= 0 && newPlayerX < MAP_SIZE && newPlayerY >= 0 && newPlayerY < MAP_SIZE && map[newPlayerX][newPlayerY] != '#'){
        //Move player
        map[playerX][playerY] = '.';
        map[newPlayerX][newPlayerY] = '@';
    }
}