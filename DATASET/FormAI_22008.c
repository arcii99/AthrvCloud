//FormAI DATASET v1.0 Category: Robot movement control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#define CLEAR_SCREEN "\e[1;1H\e[2J"

#define LEFT 'a'
#define RIGHT 'd'
#define UP 'w'
#define DOWN 's'

#define MAX_X 20
#define MAX_Y 20

#define ROBOT_CHAR 'R'

int get_key() {
    struct termios oldattr, newattr;
    int ch;

    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

void clear_screen(){
    printf("%s", CLEAR_SCREEN);
}

void print_board(char board[MAX_X][MAX_Y]){
    clear_screen();
    for(int y = 0; y < MAX_Y; y++){
        for(int x = 0; x < MAX_X; x++){
            printf("%c", board[x][y]);
        }
        printf("\n");
    }
}

int main()
{
    char board[MAX_X][MAX_Y];
    board[MAX_X / 2][MAX_Y / 2] = ROBOT_CHAR;
    
    int robot_x = MAX_X / 2;
    int robot_y = MAX_Y / 2;
    
    for(int x = 0; x < MAX_X; x++){
        for(int y = 0; y < MAX_Y; y++){
            if(board[x][y] != ROBOT_CHAR){
                board[x][y] = '#';
            }
        }
    }
    
    print_board(board);
    
    while(1){
        int ch = get_key();
        
        switch(ch){
            case LEFT:
                if(robot_x > 0){
                    board[robot_x][robot_y] = '#';
                    robot_x--;
                    board[robot_x][robot_y] = ROBOT_CHAR;
                }
                break;
            case RIGHT:
                if(robot_x < MAX_X - 1){
                    board[robot_x][robot_y] = '#';
                    robot_x++;
                    board[robot_x][robot_y] = ROBOT_CHAR;
                }
                break;
            case UP:
                if(robot_y > 0){
                    board[robot_x][robot_y] = '#';
                    robot_y--;
                    board[robot_x][robot_y] = ROBOT_CHAR;
                }
                break;
            case DOWN:
                if(robot_y < MAX_Y - 1){
                    board[robot_x][robot_y] = '#';
                    robot_y++;
                    board[robot_x][robot_y] = ROBOT_CHAR;
                }
                break;
        }
        
        print_board(board);
    }
    
    return 0;
}