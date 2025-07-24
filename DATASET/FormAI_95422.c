//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>

#define ROW 15
#define COL 20

int score = 0;

char grid[ROW][COL] = {
    {"###################"},
    {"#.................#"},
    {"#.#####.#.#####.#.#"},
    {"#o#####.#.#####.#.#"},
    {"#.#####.#.#####.#.#"},
    {"#................#.z"},
    {"#.#####.#.#####.#.#"},
    {"#.#####.#.#####.#.#"},
    {"#.....#...........#"},
    {"#####.#.#.#.#.#####"},
    {"#####.#.#.#.#.#####"},
    {"#####.#.#.#.#.#####"},
    {"#.........#.........#"},
    {"#.###.#.#.#.#.#.###.#"},
    {"#v###.#.#.#.#.#.###.#"},
};

void print_grid(){
    printf("\033[2J");          // To clear console
    printf("\033[%d;%dH", 0, 0); //reposition the cursor to row 0, column 0
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            if (grid[i][j] == '#'){
                printf("\033[48;2;12;42;212m");
                printf("  ");
                printf("\033[0m");
            } else if (grid[i][j] == '.'){
                printf("\033[48;2;238;162;14m");
                printf("  ");
                printf("\033[0m");
            } else if (grid[i][j] == 'o'){
                printf("\033[48;2;255;235;59m");
                printf("  ");
                printf("\033[0m");
            } else if (grid[i][j] == 'z'){
                printf("\033[48;2;255;0;0m");
                printf("  ");
                printf("\033[0m");
            } else if (grid[i][j] == 'v'){
                printf("\033[48;2;255;235;59m");
                printf("  ");
                printf("\033[0m");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

bool check_location(int x, int y){
    return grid[x][y] == '.';
}

void move_pacman(int r, int c){
    if (grid[r][c] == '.'){
        score += 10;
    } else if (grid[r][c] == 'z') {
        printf("Game Over\n");
        exit(0);
    }
    grid[r][c] = 'v';
    print_grid();
}

void clear_pacman(int r, int c){
    grid[r][c] = '.';
    print_grid();
}

int main() {
    print_grid();

    int c = COL/2;
    int r = ROW-2;

    struct termios orig_attributes, new_attributes;
    tcgetattr(STDIN_FILENO, &orig_attributes);
    new_attributes = orig_attributes;
    new_attributes.c_lflag &= ~(ICANON|ECHO);
    new_attributes.c_cc[VTIME] = 0;
    new_attributes.c_cc[VMIN] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_attributes);

    while (1) {
        usleep(1000);
        bool pacman_moved = false;
        char input_data;
        while (read(STDIN_FILENO, &input_data, 1) == 1){
            if (input_data == 'a') {
                if (check_location(r, c-1)){
                    clear_pacman(r, c);
                    pacman_moved = true;
                    c--;
                }
            }
            else if (input_data == 'd') {
                if (check_location(r, c+1)){
                    clear_pacman(r, c);
                    pacman_moved = true;
                    c++;
                }
            }
            else if (input_data == 'w') {
                if (check_location(r-1, c)){
                    clear_pacman(r, c);
                    pacman_moved = true;
                    r--;
                }
            }
            else if (input_data == 's') {
                if (check_location(r+1, c)){
                    clear_pacman(r, c);
                    pacman_moved = true;
                    r++;
                }
            }
            printf("\033[%d;%dH", r, c*2); //reposition the cursor to Pacman's new location
            printf("\033[38;2;255;235;59m"); // Change color to yellow
            printf("C ");
            printf("\033[0m");
            fflush(stdout);
        }

        if (pacman_moved){
            move_pacman(r, c);
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &orig_attributes);
    return 0;
}