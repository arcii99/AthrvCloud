//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // initialize random seed
    
    // define the map
    int map_width = 20;
    int map_height = 10;
    char map[map_height][map_width];
    
    // fill the map with random obstacles
    for(int i = 0; i < map_height; i++){
        for(int j = 0; j < map_width; j++){
            int rand_num = rand() % 10; // generate a random number between 0 and 9
            if(rand_num <= 3){ // 30% chance of obstacle
                map[i][j] = 'x';
            }
            else{
                map[i][j] = '.';
            }
        }
    }
    
    // randomly place the treasure on the map
    int treasure_x = rand() % map_width;
    int treasure_y = rand() % map_height;
    map[treasure_y][treasure_x] = '$';
    
    // randomly place the player on the map
    int player_x = rand() % map_width;
    int player_y = rand() % map_height;
    map[player_y][player_x] = 'P';
    
    // initialize the GPS coordinates
    int gps_x = player_x;
    int gps_y = player_y;
    
    // print the map
    printf("Map:\n");
    for(int i = 0; i < map_height; i++){
        for(int j = 0; j < map_width; j++){
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    
    // simulate GPS navigation
    while(gps_x != treasure_x || gps_y != treasure_y){
        if(gps_x < treasure_x){
            gps_x++;
        }
        else if(gps_x > treasure_x){
            gps_x--;
        }
        if(gps_y < treasure_y){
            gps_y++;
        }
        else if(gps_y > treasure_y){
            gps_y--;
        }
        
        // check if GPS coordinates are still within the map
        if(gps_x < 0 || gps_x >= map_width || gps_y < 0 || gps_y >= map_height){
            printf("GPS lost signal! Exiting...\n");
            return 0;
        }
        
        // print the current GPS coordinates and the map
        printf("Current GPS coordinates: (%d, %d)\n", gps_x, gps_y);
        printf("Map:\n");
        for(int i = 0; i < map_height; i++){
            for(int j = 0; j < map_width; j++){
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }
    }
    
    // found the treasure!
    printf("Congratulations! You have found the treasure!\n");
    
    return 0;
}