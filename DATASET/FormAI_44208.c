//FormAI DATASET v1.0 Category: Memory management ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("Welcome to the Happy Memory Game!\n");
    printf("In this game, you will need to match pairs of happy emojis.\n");
    printf("But be careful! You will need to use your memory to remember where each emoji is located.\n\n");

    int rows, cols, total_pairs;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    total_pairs = (rows * cols) / 2;

    char** board = (char**)malloc(rows * sizeof(char*));
    for(int i=0; i<rows; i++){
        board[i] = (char*)malloc(cols * sizeof(char));
    }

    char emojis[] = {'😄', '😊', '😍', '🤩', '😎', '🥰', '😜', '🤪', '😘', '😉'};
    int matched_pairs = 0;

    srand(time(0));
    for(int i=0; i<total_pairs; i++){
        int r, c;
        do{
            r = rand() % rows;
            c = rand() % cols;
        }while(board[r][c] != '\0');
        board[r][c] = emojis[i];
        do{
            r = rand() % rows;
            c = rand() % cols;
        }while(board[r][c] != '\0');
        board[r][c] = emojis[i];
    }

    int* revealed = (int*)malloc(rows * cols * sizeof(int));
    for(int i=0; i<rows*cols; i++){
        revealed[i] = 0;
    }

    while(matched_pairs < total_pairs){
        printf("------------------------------\n");
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(revealed[i*cols+j]){
                    printf("%c ", board[i][j]);
                }
                else{
                    printf("🙂 ");
                }
            }
            printf("\n");
        }
        printf("------------------------------\n");
        
        printf("Enter the coordinates (row, column) of the emoji you want to reveal: ");
        int row, col;
        scanf("%d %d", &row, &col);

        if(row < 0 || row >= rows || col < 0 || col >= cols){
            printf("Invalid coordinates!\n");
            continue;
        }

        if(revealed[row*cols+col]){
            printf("This emoji is already revealed! Try another one.\n");
            continue;
        }

        revealed[row*cols+col] = 1;
        for(int i=0; i<rows*cols; i++){
            if(revealed[i] && i != row*cols+col){
                if(board[i/cols][i%cols] == board[row][col]){
                    printf("Congratulations! You found a pair of %c\n", board[row][col]);
                    matched_pairs++;
                    break;
                }
                else{
                    printf("Try again! This pair of emojis don't match.\n");
                    revealed[i] = 0;
                    revealed[row*cols+col] = 0;
                    break;
                }
            }
        }
    }

    printf("Congratulations! You completed the Happy Memory Game with %d pairs in %d moves.\n", total_pairs, matched_pairs*2);

    for(int i=0; i<rows; i++){
        free(board[i]);
    }
    free(board);
    free(revealed);

    return 0;
}