//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 20
#define COL 70
#define MONSTERS 10

char map[ROW][COL]; //Stores the game map

//Declaring the player's attributes
typedef struct player {
    int row;
    int col;
    int health;
    int gold;
} Player;

//Declaring the monsters' attributes
typedef struct monster {
    int row;
    int col;
    int health;
    int attack;
} Monster;

Player hero; //Declaring the hero of the game
Monster monsters[MONSTERS]; //Declaring an array of monsters

void createMap() {
    int i, j;
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL-1; j++) {
            map[i][j] = '.';
        }
        map[i][j] = '\n';
    }
    map[hero.row][hero.col] = '@'; //Placing the hero's symbol on the map
    for(i = 0; i < MONSTERS; i++) {
        map[monsters[i].row][monsters[i].col] = 'M'; //Placing the monsters' symbols on the map
    }
}

void createHero() {
    hero.row = rand()%ROW;
    hero.col = rand()%COL;
    hero.health = 100;
    hero.gold = 0;
}

void createMonsters() {
    int i;
    for(i = 0; i < MONSTERS; i++) {
        monsters[i].row = rand()%ROW;
        monsters[i].col = rand()%COL;
        monsters[i].health = 30;
        monsters[i].attack = 10;
    }
}

void moveHero(int newrow, int newcol) {
    if(map[newrow][newcol] == '.') { //If the hero encounters an empty tile, he moves to that tile
        map[hero.row][hero.col] = '.';
        hero.row = newrow;
        hero.col = newcol;
        map[hero.row][hero.col] = '@';
    } else if(map[newrow][newcol] == 'M') { //If the hero encounters a monster, he attacks it
        int i;
        for(i = 0; i < MONSTERS; i++) { //Finding the monster in the monsters array
            if(monsters[i].row == newrow && monsters[i].col == newcol) {
                monsters[i].health -= 20; //Hero inflicts 20 damage to monster
                if(monsters[i].health <= 0) { //If monster's health is zero or less, it dies
                    map[monsters[i].row][monsters[i].col] = '.';
                    hero.gold += 50; //Hero receives 50 gold for killing a monster
                    break;
                }
                hero.health -= monsters[i].attack; //Monster retaliates by inflicting damage on the hero
                if(hero.health <= 0) { //If the hero's health is zero or less, the game is over
                    printf("Game over! You have been killed by a monster.");
                    exit(1);
                }
            }
        }
    }
}

void playGame() {
    createHero();
    createMonsters();
    createMap();

    while(1) {
        printf("Health: %d Gold: %d\n", hero.health, hero.gold);
        printf("Use WASD keys to move around the map.\n");

        int newrow, newcol;
        char move = getchar();

        switch(move) {
            case 'w': //Hero moves up
                newrow = hero.row - 1;
                newcol = hero.col;
                moveHero(newrow, newcol);
                break;
            case 'a': //Hero moves left
                newrow = hero.row;
                newcol = hero.col - 1;
                moveHero(newrow, newcol);
                break;
            case 's': //Hero moves down
                newrow = hero.row + 1;
                newcol = hero.col;
                moveHero(newrow, newcol);
                break;
            case 'd': //Hero moves right
                newrow = hero.row;
                newcol = hero.col + 1;
                moveHero(newrow, newcol);
                break;
        }

        int i, j;
        for(i = 0; i < MONSTERS; i++) { //Each monster gets to move
            int direction = rand()%4; //Randomly choosing a movement direction
            switch(direction) {
                case 0: //Monster moves up
                    newrow = monsters[i].row - 1;
                    newcol = monsters[i].col;
                    if(map[newrow][newcol] == '.') {
                        map[monsters[i].row][monsters[i].col] = '.';
                        monsters[i].row = newrow;
                        monsters[i].col = newcol;
                        map[monsters[i].row][monsters[i].col] = 'M';
                    }
                    break;
                case 1: //Monster moves left
                    newrow = monsters[i].row;
                    newcol = monsters[i].col - 1;
                    if(map[newrow][newcol] == '.') {
                        map[monsters[i].row][monsters[i].col] = '.';
                        monsters[i].row = newrow;
                        monsters[i].col = newcol;
                        map[monsters[i].row][monsters[i].col] = 'M';
                    }
                    break;
                case 2: //Monster moves down
                    newrow = monsters[i].row + 1;
                    newcol = monsters[i].col;
                    if(map[newrow][newcol] == '.') {
                        map[monsters[i].row][monsters[i].col] = '.';
                        monsters[i].row = newrow;
                        monsters[i].col = newcol;
                        map[monsters[i].row][monsters[i].col] = 'M';
                    }
                    break;
                case 3: //Monster moves right
                    newrow = monsters[i].row;
                    newcol = monsters[i].col + 1;
                    if(map[newrow][newcol] == '.') {
                        map[monsters[i].row][monsters[i].col] = '.';
                        monsters[i].row = newrow;
                        monsters[i].col = newcol;
                        map[monsters[i].row][monsters[i].col] = 'M';
                    }
                    break;
            }
        }
        system("clear"); //Clearing the console screen
        createMap(); //Updating the map with the new positions of the hero and the monsters
    }
}

int main() {
    srand(time(NULL)); //Seeding the random number generator with the current time
    playGame(); //Starting the game
    return 0;
}