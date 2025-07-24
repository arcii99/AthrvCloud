//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 20
#define COLUMNS 40

char grid[ROWS][COLUMNS];

//function to initialize the grid
void initialize_grid() {

    int i,j;

    for(i=0;i<ROWS;i++) {

        for(j=0;j<COLUMNS;j++) {

            grid[i][j]=' ';
        }
    }
}

//function to display the grid
void display_grid() {

    int i,j;

    for(i=0;i<ROWS;i++) {

        for(j=0;j<COLUMNS;j++) {

            printf("%c",grid[i][j]);
        }

        printf("\n");
    }
}

//function to generate the ball coordinates
void generate_ball(int *row,int *column) {

    srand(time(0));

    *row=rand()%ROWS;
    *column=rand()%COLUMNS;

    grid[*row][*column]='o';
}

//function to move the ball
void move_ball(int *row,int *column,int *x,int *y) {

    srand(time(0));

    *row+=*x;
    *column+=*y;

    if(*row==ROWS-1) {

        *x=-1;
    } else if(*row==0) {

        *x=1;
    }

    if(*column==COLUMNS-1) {

        *y=-1;
    } else if(*column==0) {

        *y=1;
    }

    grid[*row][*column]='o';
}

int main() {

    int row,column,x=1,y=1,score=0;

    initialize_grid();

    generate_ball(&row,&column);

    while(score<=50) {

        system("clear");

        move_ball(&row,&column,&x,&y);

        display_grid();

        if(grid[ROWS-1][COLUMNS/2]=='o') {

            printf("\a");

            score++;
        }

        sleep(1);
    }

    printf("\n\nGame Over! Score: %d\n\n",score);

    return 0;
}