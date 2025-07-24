//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: safe
#include<stdio.h>
#include<stdlib.h>

#define ROW 10
#define COL 10

struct cell{
    int row;
    int col;
    int f;
    int h;
    int g;
    struct cell* parent;
};

int is_valid(int row, int col);
int is_destination(int row, int col, struct cell dest);
int heuristic(int row, int col, struct cell dest);
void trace_path(struct cell* current);
void a_star(int grid[][COL],struct cell src, struct cell dest);
void print_grid(int grid[][COL]);

int main(){
    int grid[ROW][COL] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0, 0, 0, 1, 0, 1}
    };
    struct cell source = {1,1,0,0,0,NULL};
    struct cell dest = {ROW-2,COL-2,0,0,0,NULL};
    a_star(grid,source,dest);
    return 0;
}

int is_valid(int row, int col){
    return (row>=0 && row<ROW && col>=0 && col<COL);
}

int is_destination(int row, int col, struct cell dest){
    return (row==dest.row && col==dest.col);
}

int heuristic(int row, int col, struct cell dest){
    return abs(row-dest.row)+abs(col-dest.col);
}

void trace_path(struct cell* current){
    if(current->parent != NULL){
        trace_path(current->parent);
    }
    printf("(%d,%d)\n",current->row,current->col);
}

void a_star(int grid[][COL],struct cell src, struct cell dest){
    if(grid[src.row][src.col]==1 || grid[dest.row][dest.col]==1){
        printf("Source or destination is in a blocked cell!\n");
        return;
    }
    int visited[ROW][COL];
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            visited[i][j] = 0;
        }
    }
    visited[src.row][src.col] = 1;
    struct cell open_set[ROW*COL];
    int open_size = 0;
    open_set[open_size++] = src;
    while(open_size!=0){
        struct cell current = open_set[0];
        int current_index = 0;
        for(int i=1;i<open_size;i++){
            if(open_set[i].f < current.f){
                current = open_set[i];
                current_index = i;
            }
        }
        open_size--;
        open_set[current_index] = open_set[open_size];
        if(is_destination(current.row,current.col,dest)){
            printf("Path found!\n");
            trace_path(&current);
            return;
        }
        struct cell neighbors[8];
        int nb_size = 0;
        int r = current.row;
        int c = current.col;
        int cost = current.g + 1;
        if(is_valid(r-1,c) && grid[r-1][c]==0){
            neighbors[nb_size++] = (struct cell){r-1,c,0,0,0,&current};
        }
        if(is_valid(r+1,c) && grid[r+1][c]==0){
            neighbors[nb_size++] = (struct cell){r+1,c,0,0,0,&current};
        }
        if(is_valid(r,c-1) && grid[r][c-1]==0){
            neighbors[nb_size++] = (struct cell){r,c-1,0,0,0,&current};
        }
        if(is_valid(r,c+1) && grid[r][c+1]==0){
            neighbors[nb_size++] = (struct cell){r,c+1,0,0,0,&current};
        }
        if(is_valid(r-1,c-1) && grid[r-1][c-1]==0){
            neighbors[nb_size++] = (struct cell){r-1,c-1,0,0,0,&current};
        }
        if(is_valid(r+1,c+1) && grid[r+1][c+1]==0){
            neighbors[nb_size++] = (struct cell){r+1,c+1,0,0,0,&current};
        }
        if(is_valid(r-1,c+1) && grid[r-1][c+1]==0){
            neighbors[nb_size++] = (struct cell){r-1,c+1,0,0,0,&current};
        }
        if(is_valid(r+1,c-1) && grid[r+1][c-1]==0){
            neighbors[nb_size++] = (struct cell){r+1,c-1,0,0,0,&current};
        }
        for(int i=0;i<nb_size;i++){
            struct cell* neighbour = &neighbors[i];
            if(!visited[neighbour->row][neighbour->col]){
                visited[neighbour->row][neighbour->col] = 1;
                neighbour->g = cost;
                neighbour->h = heuristic(neighbour->row,neighbour->col,dest);
                neighbour->f = neighbour->g + neighbour->h;
                open_set[open_size++] = *neighbour;
            }
        }
    }
    printf("No path found.\n");
}

void print_grid(int grid[][COL]){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}