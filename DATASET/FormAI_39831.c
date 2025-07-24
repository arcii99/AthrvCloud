//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int x,y;
char board[20][20];
int score = 0;
int lives = 3;

void print_board(){
    int i,j;
    printf("Score: %d\nLives: %d\n\n",score,lives);
    for(i = 0;i < 20;i++){
        for(j = 0;j < 20;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

void init_board(){
    int i,j;
    for(i = 0;i < 20;i++){
        for(j = 0;j < 20;j++){
            if(i == 0 || i == 19 || j == 0 || j == 19){
                board[i][j] = '#';
            }else{
                board[i][j] = ' ';
            }
        }
    }
    x = 10;
    y = 10;
    board[x][y] = 'C';
}

void move_left(){
    if(board[x][y-1] != '#'){
        board[x][y] = ' ';
        y--;
        board[x][y] = 'C';
    }
}

void move_right(){
    if(board[x][y+1] != '#'){
        board[x][y] = ' ';
        y++;
        board[x][y] = 'C';
    }
}

void move_up(){
    if(board[x-1][y] != '#'){
        board[x][y] = ' ';
        x--;
        board[x][y] = 'C';
    }
}

void move_down(){
    if(board[x+1][y] != '#'){
        board[x][y] = ' ';
        x++;
        board[x][y] = 'C';
    }
}

void random_fruit(){
    int random_x,random_y;
    do{
        random_x = rand()%18+1;
        random_y = rand()%18+1;
    }while(board[random_x][random_y] != ' ');
    board[random_x][random_y] = 'F';
}

void check_hit(){
    if(board[x][y] == 'F'){
        score++;
        board[x][y] = 'C';
        random_fruit();
    }else if(board[x][y] == '#'){
        lives--;
        board[x][y] = 'C';
        x = 10;
        y = 10;
        board[x][y] = 'C';
    }else{
        board[x][y] = 'C';
    }
}

int main(){
    srand(time(NULL));
    init_board();
    random_fruit();

    while(lives > 0){
        system("clear");
        print_board();
        char input = getchar();
        getchar();
        if(input == 'a'){
            move_left();
        }else if(input == 'd'){
            move_right();
        }else if(input == 'w'){
            move_up();
        }else if(input == 's'){
            move_down();
        }else{
            continue;
        }
        check_hit();
    }

    printf("\n\nGAME OVER\nYour score: %d\n",score);
    return 0;
}