//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 30
#define MAX_COLS 80
#define NUM_MONSTERS 10

//define structures for monsters and game map
typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char symbol;
    Position position;
} Monster;

char game_map[MAX_ROWS][MAX_COLS];

//generate random number
int random_num(int min, int max) {
    return (rand() % (max - min)) + min;
}

//place monsters randomly on map
void place_monsters(Monster *monsters, int num_monsters) {
    int i;
    for (i = 0; i < num_monsters; i++) {
        monsters[i].position.x = random_num(0, MAX_COLS);
        monsters[i].position.y = random_num(0, MAX_ROWS);
        monsters[i].symbol = 'M';
        game_map[monsters[i].position.y][monsters[i].position.x] = monsters[i].symbol;
    }
}

//print game map
void print_map() {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%c", game_map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); //seed random number generator

    //initialize game map
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            game_map[i][j] = '.';
        }
    }

    //place player at center of map
    Position player_pos = {MAX_COLS/2, MAX_ROWS/2};
    game_map[player_pos.y][player_pos.x] = '@';

    //create monsters and place them randomly on the map
    Monster monsters[NUM_MONSTERS];
    place_monsters(monsters, NUM_MONSTERS);

    //print game map
    print_map();

    return 0;
}