//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

typedef struct 
{
    int row;
    int col;
} Cell;

int maze[ROWS][COLS];
int visited[ROWS][COLS];
Cell stack[ROWS * COLS];
int top = -1;

void push(Cell c)
{
    stack[++top] = c;
}

Cell pop()
{
    return stack[top--];
}

int is_empty()
{
    return top == -1;
}

void generate_maze(int row, int col)
{
    visited[row][col] = 1;
    int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int rand_dir, new_row, new_col;
    Cell current = {row, col};

    while(1)
    {
        int unvisited_neighbors = 0;
        for(int i=0; i<4; i++)
        {
            new_row = current.row + directions[i][0];
            new_col = current.col + directions[i][1];

            if(new_row < 0 || new_row >= ROWS || new_col < 0 || new_col >= COLS)
                continue;
            if(visited[new_row][new_col])
                continue;

            unvisited_neighbors++;
        }

        if(!unvisited_neighbors)
        {
            if(is_empty())
                return;
            current = pop();
            continue;
        }

        rand_dir = rand() % 4;
        new_row = current.row + directions[rand_dir][0];
        new_col = current.col + directions[rand_dir][1];

        if(new_row < 0 || new_row >= ROWS || new_col < 0 || new_col >= COLS)
            continue;
        if(visited[new_row][new_col])
            continue;

        maze[current.row][current.col] |= 1 << rand_dir;
        maze[new_row][new_col] |= 1 << ((rand_dir + 2) % 4);

        push(current);
        current = (Cell){new_row, new_col};

        visited[new_row][new_col] = 1;
    }
}

void print_maze()
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(!visited[i][j])
                printf("# ");
            else
            {
                switch(maze[i][j])
                {
                    case 0: printf("+ "); break;
                    case 1: printf("  "); break;
                    case 2: printf("| "); break;
                    case 3: printf("| "); break;
                    case 4: printf("- "); break;
                    case 5: printf("+ "); break;
                    case 6: printf("| "); break;
                    case 7: printf("| "); break;
                    case 8: printf("- "); break;
                    case 9: printf("+ "); break;
                    case 10: printf("| "); break;
                    case 11: printf("| "); break;
                    case 12: printf("- "); break;
                    case 13: printf("+ "); break;
                    case 14: printf("| "); break;
                    case 15: printf("  "); break;
                }
            }
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));

    for(int i=0; i<ROWS; i++)
        for(int j=0; j<COLS; j++)
            maze[i][j] = 0;

    generate_maze(0, 0);

    printf("Generated Maze:\n\n");
    print_maze();

    return 0;
}