//FormAI DATASET v1.0 Category: Memory Game ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 4
#define COLS 4
#define MAX_SIZE ROWS * COLS / 2

void init_board(char board[ROWS][COLS]){
    char c = 'A';
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            board[i][j] = c;
            if(c == 'Z') c = 'a';
            else c++;
        }
    }
}

void shuffle_board(char board[ROWS][COLS]){
    int size = ROWS * COLS;
    for(int i=size-1;i>0;i--){
        int j = rand() % (i+1);

        int row1 = i / COLS;
        int col1 = i % COLS;
        int row2 = j / COLS;
        int col2 = j % COLS;

        char temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;
    }
}

void print_board(char board[ROWS][COLS], int revealed[ROWS][COLS]){
    printf(" ");

    // Print header
    for(int j=0;j<COLS;j++){
        printf(" %d ", j+1);
    }
    printf("\n");

    for(int i=0;i<ROWS;i++){
        printf("%d", i+1);
        for(int j=0;j<COLS;j++){
            if(revealed[i][j]){
                printf(" %c ", board[i][j]);
            } else {
                printf(" - ");
            }
        }
        printf("\n");
    }
}

void get_input(int *row, int *col){
    printf("Enter row and column: ");
    scanf("%d %d", row, col);
    (*row)--;
    (*col)--;
}

void delay(int ms){
    clock_t start = clock();
    while((clock()-start)*1000/CLOCKS_PER_SEC < ms);
}

void reveal(char board[ROWS][COLS], int revealed[ROWS][COLS], int row, int col){
    revealed[row][col] = 1;
    print_board(board, revealed);
    delay(1000);

    if(row > 0){
        revealed[row-1][col] = 1;
        print_board(board, revealed);
        delay(1000);
    }
    if(col > 0){
        revealed[row][col-1] = 1;
        print_board(board, revealed);
        delay(1000);
    }
    if(row < ROWS-1){
        revealed[row+1][col] = 1;
        print_board(board, revealed);
        delay(1000);
    }
    if(col < COLS-1){
        revealed[row][col+1] = 1;
        print_board(board, revealed);
        delay(1000);
    }
}

int main(){
    srand(time(NULL));

    char board[ROWS][COLS];
    init_board(board);
    shuffle_board(board);

    int revealed[ROWS][COLS] = {0};

    int pairs_found = 0;
    while(pairs_found < MAX_SIZE){
        print_board(board, revealed);

        int row1, col1, row2, col2;
        get_input(&row1, &col1);
        while(revealed[row1][col1]){
            printf("That tile has already been revealed. Please enter another.\n");
            get_input(&row1, &col1);
        }
        reveal(board, revealed, row1, col1);

        get_input(&row2, &col2);
        while(revealed[row2][col2]){
            printf("That tile has already been revealed. Please enter another.\n");
            get_input(&row2, &col2);
        }
        reveal(board, revealed, row2, col2);

        if(board[row1][col1] == board[row2][col2]){
            printf("You found a pair!\n");
            pairs_found++;
        } else {
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
        }
    }

    printf("Congratulations, you found all the pairs!\n");

    return 0;
}