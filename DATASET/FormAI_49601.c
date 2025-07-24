//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 20
#define COL 50
#define MAX_ROOMS 10
#define MAX_ROOM_SIZE 10
#define MIN_ROOM_SIZE 5
#define MAX_MONSTERS 5

const char PLAYER = '@';
const char FLOOR = '-';
const char WALL = '|';
const char TREASURE = '$';
const char MONSTER = '*';
const char DOOR = '+';

struct room {
    int x, y, width, height;
};

int num_rooms = 0;
struct room rooms[MAX_ROOMS];

int dungeon[ROW][COL];
int player_x, player_y, treasure_x, treasure_y;

void create_room(int x, int y, int w, int h){
    for(int i=y; i<y+h; i++){
        for(int j=x; j<x+w; j++){
            dungeon[i][j] = FLOOR;
        }
    }
}

int check_collisions(int x, int y, int w, int h){
    for(int i=num_rooms; i>=0; i--){
        if(x < rooms[i].x + rooms[i].width + 2 &&
           x + w + 2 > rooms[i].x &&
           y < rooms[i].y + rooms[i].height + 2 &&
           h + 2 + y > rooms[i].y){
            return 1;
        }
    }
    return 0;
}

void create_rooms(){
    int x, y, width, height;
    for(int i=0; i<MAX_ROOMS; i++){
        width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE) + MIN_ROOM_SIZE;
        height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE) + MIN_ROOM_SIZE;
        x = rand() % (COL - width - 2) + 1;
        y = rand() % (ROW - height - 2) + 1;
        if(!check_collisions(x, y, width, height)){
            create_room(x, y, width, height);
            rooms[num_rooms].x = x;
            rooms[num_rooms].y = y;
            rooms[num_rooms].width = width;
            rooms[num_rooms].height = height;
            num_rooms++;
        }
    }
}

void create_corridors(){
    int prev_x = -1, prev_y = -1, curr_x, curr_y;
    for(int i=0; i<num_rooms-1; i++){
        curr_x = rooms[i].x + rooms[i].width/2;
        curr_y = rooms[i].y + rooms[i].height/2;
        if(prev_x != -1){
            while(curr_x != prev_x){
                dungeon[curr_y][prev_x] = FLOOR;
                if(curr_x < prev_x) prev_x--;
                else prev_x++;             
            }
            while(curr_y != prev_y){
                dungeon[prev_y][curr_x] = FLOOR;
                if(curr_y < prev_y) prev_y--;
                else prev_y++;
            }
        }
        prev_x = curr_x;
        prev_y = curr_y;
    }
}

void place_treasure(){
    while(dungeon[treasure_y][treasure_x] != FLOOR){
        treasure_x = rand() % (COL-2) + 1;
        treasure_y = rand() % (ROW-2) + 1;
    }
    dungeon[treasure_y][treasure_x] = TREASURE;
}

void place_wall(){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(i==0 || i==ROW-1) dungeon[i][j] = WALL;
            if(j==0 || j==COL-1) dungeon[i][j] = WALL;
        }
    }
}

void place_door(){
    int random;
    for(int i=0; i<num_rooms; i++){
        if(i==0 || i==num_rooms-1){
            random = rand() % (rooms[i].width-2) + rooms[i].x + 1;
            dungeon[rooms[i].y][random] = DOOR;
            dungeon[rooms[i].y-1][random] = FLOOR; 
            dungeon[rooms[i].y+1][random] = FLOOR;
        }
        else{
            random = rand() % (rooms[i].height-2) + rooms[i].y + 1;
            if(dungeon[rooms[i].y][rooms[i].x-1] == FLOOR){
                dungeon[random][rooms[i].x] = DOOR;
                dungeon[random][rooms[i].x-1] = FLOOR;
                dungeon[random][rooms[i].x+1] = FLOOR;
            }
            else{
                dungeon[random][rooms[i].x+rooms[i].width-1] = DOOR;
                dungeon[random][rooms[i].x+rooms[i].width] = FLOOR;
                dungeon[random][rooms[i].x+rooms[i].width-2] = FLOOR;
            }
        }
    }
}

void place_player(){
    while(dungeon[player_y][player_x] != FLOOR){
        player_x = rand() % (COL-2) + 1;
        player_y = rand() % (ROW-2) + 1;
    }
    dungeon[player_y][player_x] = PLAYER;  
}

void place_monster(){
    int monsters_placed = 0;
    while(monsters_placed < MAX_MONSTERS){
        int x = rand() % (COL-2) + 1;
        int y = rand() % (ROW-2) + 1;
        if(dungeon[y][x] == FLOOR){
            dungeon[y][x] = MONSTER;
            monsters_placed++;
        }
    }
}

void init_dungeon(){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            dungeon[i][j] = WALL;
        }
    }
}

void display_dungeon(){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            printf("%c", dungeon[i][j]);
        }
        printf("\n");
    }
}

void generate_dungeon(){
    init_dungeon();
    create_rooms();
    create_corridors();
    place_wall();
    place_door();
    place_player();
    place_treasure();
    place_monster();
    display_dungeon();
}

int main(){
    srand(time(NULL));
    generate_dungeon();
    return 0;
}