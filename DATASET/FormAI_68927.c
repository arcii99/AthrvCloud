//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROW 20
#define COL 20

char map[ROW][COL]; // layout of pac-man game board

// struct for pac-man and ghosts
struct character {
    int x;
    int y;
    int dx;
    int dy;
};

struct character pac_man;
struct character ghost_one;
struct character ghost_two;
struct character ghost_three;
struct character ghost_four;

bool is_game_over = false; // game over flag
int score = 0; // player's score

void initialize_map() {
    // initialize the map with dots and walls
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if ((i == 0 || i == ROW-1) || (j == 0 || j == COL-1)) {
                map[i][j] = '#';
            }
            else {
                map[i][j] = '.';
            }
        }
    }
    
    // initialize the pac-man and ghost positions
    pac_man.x = ROW / 2;
    pac_man.y = COL / 2;
    map[pac_man.x][pac_man.y] = 'P';
    ghost_one.x = 1;
    ghost_one.y = 1;
    map[ghost_one.x][ghost_one.y] = 'G';
    ghost_two.x = 1;
    ghost_two.y = COL-2;
    map[ghost_two.x][ghost_two.y] = 'G';
    ghost_three.x = ROW-2;
    ghost_three.y = 1;
    map[ghost_three.x][ghost_three.y] = 'G';
    ghost_four.x = ROW-2;
    ghost_four.y = COL-2;
    map[ghost_four.x][ghost_four.y] = 'G';
}

void print_map() {
    // print the map and player's score
    system("clear"); // clear the terminal before printing
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("\nScore: %d\n", score);
}

void move_pac_man() {
    // move the pac-man based on user input
    char input;
    scanf(" %c", &input);
    map[pac_man.x][pac_man.y] = '.'; // erase the pac-man from the current position
    switch (input) {
        case 'w':
            // move up
            if (map[pac_man.x-1][pac_man.y] != '#') {
                pac_man.dx = -1;
                pac_man.dy = 0;
            }
            break;
        case 'a':
            // move left
            if (map[pac_man.x][pac_man.y-1] != '#') {
                pac_man.dx = 0;
                pac_man.dy = -1;
            }
            break;
        case 's':
            // move down
            if (map[pac_man.x+1][pac_man.y] != '#') {
                pac_man.dx = 1;
                pac_man.dy = 0;
            }
            break;
        case 'd':
            // move right
            if (map[pac_man.x][pac_man.y+1] != '#') {
                pac_man.dx = 0;
                pac_man.dy = 1;
            }
            break;
        default:
            // invalid input
            pac_man.dx = 0;
            pac_man.dy = 0;
            printf("Invalid input!\n");
    }
    pac_man.x += pac_man.dx;
    pac_man.y += pac_man.dy;
    // check if pac-man collected any dots
    if (map[pac_man.x][pac_man.y] == '.') {
        score += 10;
    }
    map[pac_man.x][pac_man.y] = 'P'; // draw the pac-man at the new position
}

void move_ghost_one() {
    // randomly move ghost one
    int rand_num = rand() % 4;
    if (rand_num == 0 && map[ghost_one.x-1][ghost_one.y] != '#') {
        ghost_one.x -= 1;
    }
    else if (rand_num == 1 && map[ghost_one.x][ghost_one.y-1] != '#') {
        ghost_one.y -= 1;
    }
    else if (rand_num == 2 && map[ghost_one.x+1][ghost_one.y] != '#') {
        ghost_one.x += 1;
    }
    else if (rand_num == 3 && map[ghost_one.x][ghost_one.y+1] != '#') {
        ghost_one.y += 1;
    }
    // check if ghost one caught the pac-man and end the game if so
    if (ghost_one.x == pac_man.x && ghost_one.y == pac_man.y) {
        is_game_over = true;
    }
    map[ghost_one.x][ghost_one.y] = 'G'; // draw the ghost at the new position
}

void move_ghost_two() {
    // randomly move ghost two
    int rand_num = rand() % 4;
    if (rand_num == 0 && map[ghost_two.x-1][ghost_two.y] != '#') {
        ghost_two.x -= 1;
    }
    else if (rand_num == 1 && map[ghost_two.x][ghost_two.y-1] != '#') {
        ghost_two.y -= 1;
    }
    else if (rand_num == 2 && map[ghost_two.x+1][ghost_two.y] != '#') {
        ghost_two.x += 1;
    }
    else if (rand_num == 3 && map[ghost_two.x][ghost_two.y+1] != '#') {
        ghost_two.y += 1;
    }
    // check if ghost two caught the pac-man and end the game if so
    if (ghost_two.x == pac_man.x && ghost_two.y == pac_man.y) {
        is_game_over = true;
    }
    map[ghost_two.x][ghost_two.y] = 'G'; // draw the ghost at the new position
}

void move_ghost_three() {
    // randomly move ghost three
    int rand_num = rand() % 4;
    if (rand_num == 0 && map[ghost_three.x-1][ghost_three.y] != '#') {
        ghost_three.x -= 1;
    }
    else if (rand_num == 1 && map[ghost_three.x][ghost_three.y-1] != '#') {
        ghost_three.y -= 1;
    }
    else if (rand_num == 2 && map[ghost_three.x+1][ghost_three.y] != '#') {
        ghost_three.x += 1;
    }
    else if (rand_num == 3 && map[ghost_three.x][ghost_three.y+1] != '#') {
        ghost_three.y += 1;
    }
    // check if ghost three caught the pac-man and end the game if so
    if (ghost_three.x == pac_man.x && ghost_three.y == pac_man.y) {
        is_game_over = true;
    }
    map[ghost_three.x][ghost_three.y] = 'G'; // draw the ghost at the new position
}

void move_ghost_four() {
    // randomly move ghost four
    int rand_num = rand() % 4;
    if (rand_num == 0 && map[ghost_four.x-1][ghost_four.y] != '#') {
        ghost_four.x -= 1;
    }
    else if (rand_num == 1 && map[ghost_four.x][ghost_four.y-1] != '#') {
        ghost_four.y -= 1;
    }
    else if (rand_num == 2 && map[ghost_four.x+1][ghost_four.y] != '#') {
        ghost_four.x += 1;
    }
    else if (rand_num == 3 && map[ghost_four.x][ghost_four.y+1] != '#') {
        ghost_four.y += 1;
    }
    // check if ghost four caught the pac-man and end the game if so
    if (ghost_four.x == pac_man.x && ghost_four.y == pac_man.y) {
        is_game_over = true;
    }
    map[ghost_four.x][ghost_four.y] = 'G'; // draw the ghost at the new position
}

int main() {
    srand(time(NULL)); // seed random number generator
    initialize_map(); // initialize the game map and characters
    while (!is_game_over) { // game loop
        print_map(); // print the game map and player's score
        move_pac_man(); // move the pac-man based on user input
        move_ghost_one(); // move ghost one
        move_ghost_two(); // move ghost two
        move_ghost_three(); // move ghost three
        move_ghost_four(); // move ghost four
    }
    printf("Game Over! Final Score: %d\n", score); // print final score when game is over
    return 0;
}