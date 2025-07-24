//FormAI DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

void display(char array[][WIDTH]);
void init(char array[][WIDTH]);
void update(char array[][WIDTH]);

int main(){

    char grid[HEIGHT][WIDTH];
    srand(time(NULL));
    init(grid);
    display(grid);

    for(int i = 0; i < 200; i++) {
        update(grid);
        display(grid);
    }
}

void init(char array[][WIDTH]){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            array[i][j] = rand() % 2;
        }
    }
}

void display(char array[][WIDTH]){
    system("cls");
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(array[i][j] == 1) printf("#");
            else printf(" ");
        }
        printf("\n");
    }
}

void update(char array[][WIDTH]){
    char temp[HEIGHT][WIDTH];
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            int sum=((j==0?0:array[i][j-1]) +
                    (j==(WIDTH-1)?0:array[i][j+1]) +
                    (i==0?0:array[i-1][j]) +
                    (i==(HEIGHT-1)?0:array[i+1][j]) +
                    (i==0||j==0?0:array[i-1][j-1]) +
                    (i==0||j==WIDTH-1?0:array[i-1][j+1]) +
                    (i==HEIGHT-1||j==0?0:array[i+1][j-1]) +
                    (i==HEIGHT-1||j==WIDTH-1?0:array[i+1][j+1]));

            switch(sum){
                case 2:
                    temp[i][j] = array[i][j];
                    break;
                case 3:
                    temp[i][j] = 1;
                    break;
                default:
                    temp[i][j] = 0;
            }
        }
    }

    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            array[i][j]=temp[i][j];
        }
    }
}