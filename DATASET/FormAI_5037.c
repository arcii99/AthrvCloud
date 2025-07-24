//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

typedef struct{
    int x;
    int y;
}Position;

typedef struct{
    int top;
    Position items[ROWS * COLS];
}Stack;

void push(Stack *s, Position p){
    s->items[++s->top] = p;
}

Position pop(Stack *s){
    return s->items[s->top--];
}

int is_empty(Stack *s){
    return s->top == -1;
}

int is_valid(int row, int col){
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

int dfs(int maze[ROWS][COLS], int visited[ROWS][COLS], Position start, Position end, Stack *solution){
    if(!is_valid(start.x, start.y) || visited[start.x][start.y] || maze[start.x][start.y] == 0){
        return 0;
    }
    visited[start.x][start.y] = 1;
    push(solution, start);
    if(start.x == end.x && start.y == end.y){
        return 1;
    }
    Position north = {start.x - 1, start.y};
    if(dfs(maze, visited, north, end, solution)){
        return 1;
    }
    Position south = {start.x + 1, start.y};
    if(dfs(maze, visited, south, end, solution)){
        return 1;
    }
    Position east = {start.x, start.y + 1};
    if(dfs(maze, visited, east, end, solution)){
        return 1;
    }
    Position west = {start.x, start.y - 1};
    if(dfs(maze, visited, west, end, solution)){
        return 1;
    }
    pop(solution);
    return 0;
}

void print_maze(int maze[ROWS][COLS]){
    printf("MAZE:\n");
    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLS; col++){
            printf("%d ", maze[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_solution(Stack *solution){
    printf("ROUTE:\n");
    while(!is_empty(solution)){
        Position p = pop(solution);
        printf("(%d, %d)\n", p.x, p.y);
    }
    printf("\n");
}

int main(){
    int maze[ROWS][COLS] = 
        {{1,1,1,1,1,1,1,1,1,1},
         {1,0,0,0,1,0,0,1,0,1},
         {1,0,1,0,1,0,0,1,0,1},
         {1,0,1,0,1,1,1,1,1,1},
         {1,0,1,0,0,0,0,0,0,1},
         {1,0,1,1,1,1,1,1,0,1},
         {1,0,1,0,0,0,0,0,0,1},
         {1,0,1,0,1,1,1,1,0,1},
         {1,0,0,0,0,0,0,0,0,1},
         {1,1,1,1,1,1,1,1,1,1}};

    int visited[ROWS][COLS] = {{0}};

    Position start = {1,0};
    Position end = {8,9};

    Stack solution = {-1};

    printf("FINDING THE ROUTE FROM ");
    printf("(%d, %d)", start.x, start.y);
    printf(" TO ");
    printf("(%d, %d)\n\n", end.x, end.y);

    print_maze(maze);

    if(dfs(maze, visited, start, end, &solution)){
        print_solution(&solution);
    }else{
        printf("NO ROUTE EXISTS.\n");
    }

    return 0;
}