//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_MOVES 15

char map[MAP_SIZE][MAP_SIZE];

int current_x, current_y;
int target_x, target_y;

int move_count = 0;

void fill_map(){
    int i, j;
    for (i=0; i<MAP_SIZE; i++){
        for (j=0; j<MAP_SIZE; j++){
            map[i][j] = '.';
        }
    }

    map[current_x][current_y] = 'S';
    map[target_x][target_y] = 'T';
}

void display_map(){
    int i, j;
    printf("\n");

    for (i=0; i<MAP_SIZE; i++){
        for (j=0; j<MAP_SIZE; j++){
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int get_distance(){
    return abs(current_x - target_x) + abs(current_y - target_y);
}

void move_north(){
    if (current_x-1 < 0){
        printf("Cannot move that direction. Out of bounds.\n");
        return;
    }

    current_x -= 1;
    map[current_x][current_y] = 'X';
    move_count += 1;

    printf("Moved north!\n");

    if (current_x == target_x && current_y == target_y){
        printf("Target reached! Congrats!\n");
        display_map();
        exit(0);
    }

    display_map();

    if (move_count >= MAX_MOVES){
        printf("Reached maximum amount of moves without reaching the target. Game over!\n");
        exit(0);
    }
}

void move_south(){
    if (current_x+1 >= MAP_SIZE){
        printf("Cannot move that direction. Out of bounds.\n");
        return;
    }

    current_x += 1;
    map[current_x][current_y] = 'X';
    move_count += 1;

    printf("Moved south!\n");

    if (current_x == target_x && current_y == target_y){
        printf("Target reached! Congrats!\n");
        display_map();
        exit(0);
    }

    display_map();

    if (move_count >= MAX_MOVES){
        printf("Reached maximum amount of moves without reaching the target. Game over!\n");
        exit(0);
    }
}

void move_east(){
    if (current_y+1 >= MAP_SIZE){
        printf("Cannot move that direction. Out of bounds.\n");
        return;
    }

    current_y += 1;
    map[current_x][current_y] = 'X';
    move_count += 1;

    printf("Moved east!\n");

    if (current_x == target_x && current_y == target_y){
        printf("Target reached! Congrats!\n");
        display_map();
        exit(0);
    }

    display_map();

    if (move_count >= MAX_MOVES){
        printf("Reached maximum amount of moves without reaching the target. Game over!\n");
        exit(0);
    }
}

void move_west(){
    if (current_y-1 < 0){
        printf("Cannot move that direction. Out of bounds.\n");
        return;
    }

    current_y -= 1;
    map[current_x][current_y] = 'X';
    move_count += 1;

    printf("Moved west!\n");

    if (current_x == target_x && current_y == target_y){
        printf("Target reached! Congrats!\n");
        display_map();
        exit(0);
    }

    display_map();

    if (move_count >= MAX_MOVES){
        printf("Reached maximum amount of moves without reaching the target. Game over!\n");
        exit(0);
    }
}

void update_location(){
    int x_direction = 0, y_direction = 0;

    if (current_x < target_x){
        x_direction = 1;
    }
    else if (current_x > target_x){
        x_direction = -1;
    }

    if (current_y < target_y){
        y_direction = 1;
    }
    else if (current_y > target_y){
        y_direction = -1;
    }

    if (x_direction == 1){
        move_south();
    }
    else if (x_direction == -1){
        move_north();
    }

    if (y_direction == 1){
        move_east();
    }
    else if (y_direction == -1){
        move_west();
    }
}

int main(){
    srand(time(NULL));
    current_x = rand() % MAP_SIZE;
    current_y = rand() % MAP_SIZE;

    target_x = rand() % MAP_SIZE;
    target_y = rand() % MAP_SIZE;

    fill_map();
    display_map();

    while (1){
        printf("Distance to target: %d\n", get_distance());
        update_location();
    }

    return 0;
}