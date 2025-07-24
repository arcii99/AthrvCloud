//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
char player = 'X';
char computer = 'O';

void init_board() {
    int i, j;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            board[i][j] = '-';
}

void print_board() {
    int i, j;
    printf("\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++)
            printf("%c\t", board[i][j]);
        printf("\n\n");
    }
}

int check_win() {
    int i, j;
    for(i=0; i<3; i++)
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != '-')
            return 1;
    for(i=0; i<3; i++)
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != '-')
            return 1;
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != '-')
        return 1;
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != '-')
        return 1;
    return 0;
}

int check_tie() {
    int i, j;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            if(board[i][j] == '-')
                return 0;
    return 1;
}

void player_turn() {
    int row, col;
    printf("Enter your move (row and column): ");
    scanf("%d %d", &row, &col);
    if(row<0 || row>2 || col<0 || col>2 || board[row][col]!='-') {
        printf("Invalid move. Try again.\n");
        player_turn();
    }
    else board[row][col] = player;
}

void computer_turn() {
    srand(time(NULL));
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while(board[row][col] != '-');
    board[row][col] = computer;
    printf("Computer's move: row %d, column %d\n", row, col);
}

void play() {
    init_board();
    printf("Tic-Tac-Toe game\n");
    printf("Human player: %c\n", player);
    printf("Computer player: %c\n", computer);
    printf("-------------------------------\n");
    print_board();
    while(!check_win() && !check_tie()) {
        player_turn();
        print_board();
        if(check_win()) {
            printf("You won!\n");
            return;
        }
        if(check_tie()) {
            printf("Tie game.\n");
            return;
        }
        computer_turn();
        print_board();
        if(check_win()) {
            printf("Computer won.\n");
            return;
        }
        if(check_tie()) {
            printf("Tie game.\n");
            return;
        }
    }
}

int main() {
    char choice;
    while(1) {
        play();
        printf("Play again? (y/n): ");
        scanf(" %c", &choice);
        if(choice=='n') break;
    }
    return 0;
}