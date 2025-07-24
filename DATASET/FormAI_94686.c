//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Board_size 21 // 21 x 21
#define Wall '#'
#define Pacman 'P'
#define Blinky 'B'
#define Inky 'I'
#define Pinky 'K'
#define Clyde 'C'
#define Dot '.'
#define Fruit 'F'

char board[Board_size][Board_size];
int pacman_x, pacman_y;

int random_direction(){
    //Generate random direction
    srand(time(0));
    return (rand() % 4) + 1;
}

void init_board(){
    //Populate the board with walls and dots
    for(int i=0; i<Board_size; i++){
        for(int j=0; j<Board_size; j++){
            if(i == 0 || i == Board_size-1 || j == 0 || j == Board_size-1)
                board[i][j] = Wall;
            else if(i == Board_size/2 && j == Board_size/2){
                board[i][j] = Pacman;
                pacman_x = i;
                pacman_y = j;
            }
            else if(i==3 && (j==6 || j==14))
                board[i][j] = Fruit;
            else if((i+j) % 2 == 0)
                board[i][j] = Dot;
            else
                board[i][j] = ' ';
        }
    }
}

void print_board(){
    //Print the board
    printf("\n");
    for(int i=0; i<Board_size; i++){
        for(int j=0; j<Board_size; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void move_pacman(int direction){
    //Move Pacman
    board[pacman_x][pacman_y] = ' ';

    switch(direction){
    case 1:
        pacman_x--;
        break;
    case 2:
        pacman_y++;
        break;
    case 3:
        pacman_x++;
        break;
    case 4:
        pacman_y--;
        break;
    }
    board[pacman_x][pacman_y] = Pacman;
}


int main(){
    int direction = 0;

    init_board();
    print_board();

    while(1){
        direction = random_direction();
        move_pacman(direction);
        print_board();
        usleep(200000); //Delay for animation
    }

    return 0;
}