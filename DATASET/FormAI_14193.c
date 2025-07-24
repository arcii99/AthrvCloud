//FormAI DATASET v1.0 Category: Checkers Game ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

//In this program we are implementing the game of checkers using C programming language.

void initialize(int plate[8][8]); // Function to initialize the board.
void display(int plate[8][8]); //Function to display the board.
void move(int plate[8][8]); // Function to make a move.
int check_win(int plate[8][8]); //Function to check if the game has been won.
int red_win(int plate[8][8]); // Function to check if the red team has won the game.
int white_win(int plate[8][8]); // Function to check if the white team has won the game.

int main(){

    int plate[8][8];
    int winner;

    initialize(plate);
    display(plate);

    while(1){

        move(plate);
        display(plate);
        winner = check_win(plate);

        if(winner != 0){
            break;
        }
    }

    if(winner == 1){
        printf("\n RED WINS !\n\n");
    }
    else if(winner == 2){
        printf("\n WHITE WINS !\n\n");
    }

    return 0;
}

void initialize(int plate[8][8]){
    int i, j;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(i < 3 && ((i+j)%2 == 0)){
                plate[i][j] = 1;
            }
            else if(i > 4 && ((i+j)%2 == 0)){
                plate[i][j] = 2;
            }
            else{
                plate[i][j] = 0;
            }
        }
    }
}

void display(int plate[8][8]){
    int i, j;

    printf("\n\n");
    printf("    0   1   2   3   4   5   6   7\n");
    printf("  +---+---+---+---+---+---+---+---+\n");

    for(i = 0; i < 8; i++){

        printf("%d |", i);
        for(j = 0; j < 8; j++){
            if(plate[i][j] == 0){
                printf("   |");
            }
            else if(plate[i][j] == 1){
                printf(" R |");
            }
            else if(plate[i][j] == 2){
                printf(" W |");
            }
        }

        printf("\n");
        printf("  +---+---+---+---+---+---+---+---+\n");

    }
}

void move(int plate[8][8]){
    int sx, sy;
    int dx, dy;
    int i;

    printf("\nEnter the position of the piece you want to move (row column): ");
    scanf("%d %d", &sx, &sy);

    printf("Enter the position of the destination (row column): ");
    scanf("%d %d", &dx, &dy);

    if(plate[sx][sy] == 0){
        printf("\n There is no piece there ! \n");
        move(plate);
        return;
    }

    if(plate[dx][dy] != 0){
        printf("\n There is already a piece at that location ! \n");
        move(plate);
        return;
    }

    if(((sx+sy)%2 == 0) && ((dx+dy)%2 == 0)){

        if(plate[sx][sy] == 1){

            if((dx == sx-1) && ((dy == sy-1) || (dy == sy+1)) && (plate[dx][dy] == 0)){
                plate[dx][dy] = 1;
                plate[sx][sy] = 0;
            }
            else if((dx == sx-2) && ((dy == sy-2) || (dy == sy+2)) && (plate[dx][dy] == 0) && (plate[sx-1][sy-1] == 2 || plate[sx-1][sy+1] == 2)){
                plate[dx][dy] = 1;
                plate[sx][sy] = 0;
                plate[sx-1][sy-1] = 0;
                plate[sx-1][sy+1] = 0;
            }
            else{
                printf("\n Invalid move ! \n");
                move(plate);
                return;
            }
        }

        else if(plate[sx][sy] == 2){

            if((dx == sx+1) && ((dy == sy-1) || (dy == sy+1)) && (plate[dx][dy] == 0)){
                plate[dx][dy] = 2;
                plate[sx][sy] = 0;
            }
            else if((dx == sx+2) && ((dy == sy-2) || (dy == sy+2)) && (plate[dx][dy] == 0) && (plate[sx+1][sy-1] == 1 || plate[sx+1][sy+1] == 1)){
                plate[dx][dy] = 2;
                plate[sx][sy] = 0;
                plate[sx+1][sy-1] = 0;
                plate[sx+1][sy+1] = 0;
            }
            else{
                printf("\n Invalid move ! \n");
                move(plate);
                return;
            }

        }
        else{
            printf("\n Invalid piece selected ! \n");
            move(plate);
            return;
        }

    }
    else{
        printf("\n You cannot move into that position ! \n");
        move(plate);
        return;
    }
}

int check_win(int plate[8][8]){
    if(red_win(plate)){
        return 1;
    }
    else if(white_win(plate)){
        return 2;
    }
    else{
        return 0;
    }
}

int red_win(int plate[8][8]){
    int i, j;

    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(plate[i][j] == 2){
                return 0;
            }
        }
    }

    return 1;
}

int white_win(int plate[8][8]){
    int i, j;

    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(plate[i][j] == 1){
                return 0;
            }
        }
    }

    return 1;
}