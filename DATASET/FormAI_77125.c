//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_MOVEMENTS 100

typedef struct{
    int x;
    int y;
}Position;

typedef struct{
    char name[50];
    Position position;
}Destination;

void print_map(char map[][MAP_SIZE], Position current_position, Destination destination){
    printf("\n");
    for(int i=0; i<MAP_SIZE; i++){
        for(int j=0; j<MAP_SIZE; j++){
            if(current_position.x==i && current_position.y==j){
                printf("X\t");
            }
            else if(destination.position.x==i && destination.position.y==j){
                printf("D\t");
            }
            else{
                printf("%c\t", map[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int get_movement(){
    return (rand() % 4) + 1;
}

void move(Position *current_position, int movement){
    switch(movement){
        case 1:
            if(current_position->y>0){
                current_position->y--;
            }
            break;
        case 2:
            if(current_position->y<MAP_SIZE-1){
                current_position->y++;
            }
            break;
        case 3:
            if(current_position->x>0){
                current_position->x--;
            }
            break;
        case 4:
            if(current_position->x<MAP_SIZE-1){
                current_position->x++;
            }
            break;
    }
}

int main(){
    char map[MAP_SIZE][MAP_SIZE] = {{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                     {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                     {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                     {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                     {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                     {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                     {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                     {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                     {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                     {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                     };
    Destination destination;
    Position current_position;

    srand(time(NULL));

    printf("Welcome to GPS Navigation Simulation!\n\n");

    printf("Please enter your destination:\n");
    fgets(destination.name,50,stdin);

    destination.position.x = rand()%10;
    destination.position.y = rand()%10;

    printf("\n\nYour destination is: %s. Location: (%d,%d)\n", destination.name,destination.position.x, destination.position.y);

    printf("\n\nGenerating Map...\n");

    current_position.x = rand()%10;
    current_position.y = rand()%10;

    while(map[destination.position.x][destination.position.y] == 'D' || map[current_position.x][current_position.y] == 'X'){
        current_position.x = rand()%10;
        current_position.y = rand()%10;
    }

    printf("\n\nYou are at location: (%d,%d)\n", current_position.x, current_position.y);

    sleep(1);

    for(int i=0; i<MAP_SIZE; i++){
        for(int j=0; j<MAP_SIZE; j++){
            map[i][j]='-';
        }
    }

    map[current_position.x][current_position.y]='X';
    map[destination.position.x][destination.position.y]='D';

    print_map(map, current_position, destination);

    int movements[MAX_MOVEMENTS], index=0;

    while(current_position.x!=destination.position.x || current_position.y!=destination.position.y){
        int movement = get_movement();
        movements[index++] = movement;
        move(&current_position, movement);
        print_map(map, current_position, destination);
        if(current_position.x==destination.position.x && current_position.y==destination.position.y){
            break;
        }
        if(index==MAX_MOVEMENTS){
            printf("Cannot reach destination with %d movements.\n", MAX_MOVEMENTS);
            return 0;
        }
        sleep(1);
    }

    printf("Congratulations! You have reached your destination in %d movements.\n", index);

    return 0;
}