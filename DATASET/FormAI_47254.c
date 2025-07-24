//FormAI DATASET v1.0 Category: Memory Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void display(char array[][COLS], int rows){
    int i, j;
    for(i = 0; i < rows; i++){
        for(j = 0; j < COLS; j++){
            printf("%c\t", array[i][j]);
        }
        printf("\n\n");
    }
}

void initialise(char array[][COLS], int rows){
    int i, j, count = 1;
    srand(time(NULL));
    for(i = 0; i < rows; i++){
        for(j = 0; j < COLS; j++){
            if(count == 8){
                array[i][j] = ' ';
                break;
            }
            array[i][j] = count + 48;
            count++;
        }
    }
    shuffle(array, rows);
}

void shuffle(char array[][COLS], int rows){
    int i, j, random_row, random_col;
    char temp;
    for(i = 0; i < rows; i++){
        for(j = 0; j < COLS; j++){
            random_row = rand() % 4;
            random_col = rand() % 4;
            temp = array[i][j];
            array[i][j] = array[random_row][random_col];
            array[random_row][random_col] = temp;
        }
    }
}

void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int find_blank(char array[][COLS]){
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            if(array[i][j] == ' '){
                return i*4 + j;
            }
        }
    }
    return -1;
}

int check_win(char array[][COLS], int rows){
    int i, j, count = 1;
    for(i = 0; i < rows; i++){
        for(j = 0; j < COLS; j++){
            if(count == 16){
                break;
            }
            if(array[i][j] != count + 48){
                return 0;
            }
            count++;
        }
    }
    return 1;
}

void game_menu(){
        printf("\n\n\t\t\t\t\tMemory Game\n");
        printf("***********************************************************************************\n\n");
        printf("\t\t\t\tEnter 0 to Exit\n");
        printf("\t\t\t\tEnter 1 to Play\n\n");
}

int main(){
    char game[ROWS][COLS];
    char input;
    int blank_index;
    initialise(game, ROWS);
    while(1){
        game_menu();
        display(game, ROWS);
        scanf("%c", &input);
        if(input == '0') break;
        blank_index = find_blank(game);
        switch(input){
            case '1':
                if(blank_index >= 4){
                    swap(&game[blank_index/4 - 1][blank_index % 4], &game[blank_index/4][blank_index % 4]);
                    blank_index = blank_index - 4;
                }
                break;
            case '2':
                if(blank_index <= 11){
                    swap(&game[blank_index/4 + 1][blank_index % 4], &game[blank_index/4][blank_index % 4]);
                    blank_index = blank_index + 4;
                }
                break;
            case '3':
                if(blank_index % 4 != 0){
                    swap(&game[blank_index/4][blank_index % 4 - 1], &game[blank_index/4][blank_index % 4]);
                    blank_index = blank_index - 1;
                }
                break;
            case '4':
                if(blank_index % 4 != 3){
                    swap(&game[blank_index/4][blank_index % 4 + 1], &game[blank_index/4][blank_index % 4]);
                    blank_index = blank_index + 1;
                }
                break;
            default:
                printf("\nInvalid Input!");
                break;
        }
        if(check_win(game, ROWS)){
            display(game, ROWS);
            printf("\n\nYou Won!!!\n\n");
            break;
        }
        getchar(); //to get rid of extra character input by user
        system("cls"); //for windows, use "clear" for linux and mac
    }
    return 0;
}