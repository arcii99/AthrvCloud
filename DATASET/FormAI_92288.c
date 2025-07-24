//FormAI DATASET v1.0 Category: Memory Game ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GRID_SIZE 4

void display_board(char board[GRID_SIZE][GRID_SIZE], int visible[GRID_SIZE][GRID_SIZE]);
int select_tile();
void update_board(char selection, char board[GRID_SIZE][GRID_SIZE], int visible[GRID_SIZE][GRID_SIZE], int *matched_tiles);
void initialize_board(char board[GRID_SIZE][GRID_SIZE]);
void shuffle_board(char board[GRID_SIZE][GRID_SIZE]);

int main(){
    char board[GRID_SIZE][GRID_SIZE];
    int visible[GRID_SIZE][GRID_SIZE] = {0};
    int matched_tiles = 0;
    int turn = 0;
    int i, j;
    char selection_1, selection_2;
    
    srand(time(NULL));
    initialize_board(board);

    shuffle_board(board);
    
    while(matched_tiles < (GRID_SIZE * GRID_SIZE)/2){
        turn++;
        display_board(board, visible);
        printf("Turn %d, select two tiles to reveal (e.g A1A2): ", turn);
        
        selection_1 = select_tile();
        while(visible[selection_1 / GRID_SIZE][selection_1 % GRID_SIZE] != 0 || selection_1 < 0){
            printf("Invalid Selection, please try again: ");
            selection_1 = select_tile();
        }
        
        selection_2 = select_tile();
        while(visible[selection_2 / GRID_SIZE][selection_2 % GRID_SIZE] != 0 || selection_2 < 0){
            printf("Invalid Selection, please try again: ");
            selection_2 = select_tile();
        }
        
        update_board(selection_1, board, visible, &matched_tiles);
        update_board(selection_2, board, visible, &matched_tiles);
    }
    
    printf("Congratulations, you matched all tiles in %d turns!", turn);
}

//Displays the board
void display_board(char board[GRID_SIZE][GRID_SIZE], int visible[GRID_SIZE][GRID_SIZE]){
    int i,j;

    printf("   ");
    for(i=0;i<GRID_SIZE;i++) printf("%c ", 'A' + i);
    printf("\n");
    
    for(i=0;i<GRID_SIZE;i++){
        printf("%d ", i+1);
        for(j=0;j<GRID_SIZE;j++){
            if(visible[i][j]==1) printf("%c ", board[i][j]);
            else printf("  ");
        }
        printf("\n");
    }
}

//Prompts the user to select a tile and returns the index of the tile
int select_tile(){
    char tile[3];
    int row, col, index;
    scanf("%s", tile);
    row = tile[0] - 'A';
    col = tile[1] - '1';
    index = row * GRID_SIZE + col;
    return index;
}

//Updates the board and visible array based on the selected tile
void update_board(char selection, char board[GRID_SIZE][GRID_SIZE], int visible[GRID_SIZE][GRID_SIZE], int *matched_tiles){
    int row, col;
    row = selection / GRID_SIZE;
    col = selection % GRID_SIZE;
    visible[row][col] = 1;
    if(*matched_tiles == (GRID_SIZE * GRID_SIZE)/2) return; //If all tiles are matched, return
    if(*matched_tiles % 2 == 1){ //If this is the second tile selected for the turn, check for a match
        if(board[selection / GRID_SIZE][selection % GRID_SIZE]
        == board[(*matched_tiles - 1) / GRID_SIZE][(*matched_tiles - 1) % GRID_SIZE]){
            printf("Match Found!\n");
            (*matched_tiles)++;
        }
        else{
            printf("No Match Found.\n");
            visible[selection / GRID_SIZE][selection % GRID_SIZE] = 0;
            visible[(*matched_tiles - 1) / GRID_SIZE][(*matched_tiles - 1) % GRID_SIZE] = 0;
        }
    }
}

//Initializes the board with random letters
void initialize_board(char board[GRID_SIZE][GRID_SIZE]){
    int i,j;
    char letters[(GRID_SIZE * GRID_SIZE)/2] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int letter_index = 0;
    
    for(i=0;i<GRID_SIZE;i++){
        for(j=0;j<GRID_SIZE;j++){
            board[i][j] = letters[letter_index];
            letter_index++;
            if(letter_index >= (GRID_SIZE * GRID_SIZE)/2) letter_index = 0;
        }
    }
}

//Shuffles the board by swapping random tiles
void shuffle_board(char board[GRID_SIZE][GRID_SIZE]){
    int i,j,row1, col1, row2, col2;
    char temp;
    for(i=0;i<GRID_SIZE * GRID_SIZE;i++){
        row1 = rand()%GRID_SIZE;
        col1 = rand()%GRID_SIZE;
        row2 = rand()%GRID_SIZE;
        col2 = rand()%GRID_SIZE;
        temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;
    }
}