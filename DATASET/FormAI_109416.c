//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 5
#define COL 5

// A structure to store cell coordinates
struct Cell 
{
    int row, col;
};

// A data structure for Stack
struct Stack 
{
    int top;
    unsigned capacity;
    struct Cell* array;
};

// function to create a stack of given capacity
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct Cell*) malloc(stack->capacity * sizeof(struct Cell));
    return stack;
}

// function to check if the stack is full
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

// function to check if the stack is empty
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

// function to add an item to stack
void push(struct Stack* stack, struct Cell item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// function to remove an item from stack
struct Cell pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return (struct Cell) {-1, -1};
    return stack->array[stack->top--];
}

// function to find the shortest path in the maze
void findShortestPath(int maze[][COL], int visited[][COL], int src_row, int src_col, int dest_row, int dest_col)
{
    // checks if source and destination are valid
    if (maze[src_row][src_col] == 1 || maze[dest_row][dest_col] == 1) 
    {
        printf("Invalid input\n");
        return;
    }

    // checks if source and destination are same
    if (src_row == dest_row && src_col == dest_col) 
    {
        printf("Shortest path is 0\n");
        return;
    }

    // declaring and initializing the stack and visited matrix
    struct Stack* stack = createStack(ROW * COL);
    memset(visited, 0, sizeof(visited));

    // adding source cell to stack and marking it as visited
    push(stack, (struct Cell) {src_row, src_col});
    visited[src_row][src_col] = 1;

    // moves to adjacent cells and adds them to stack if they are valid and not visited
    while (!isEmpty(stack)) 
    {
        // pops the top cell from the stack
        struct Cell current_cell = pop(stack);

        // holds the distance value of popped cell
        int dist = visited[current_cell.row][current_cell.col];

        // moves to adjacent cells
        if (current_cell.row > 0 && maze[current_cell.row - 1][current_cell.col] == 0 && !visited[current_cell.row - 1][current_cell.col]) 
        {
            push(stack, (struct Cell) {current_cell.row - 1, current_cell.col}); // north
            visited[current_cell.row - 1][current_cell.col] = dist + 1;
        }

        if (current_cell.col < COL - 1 && maze[current_cell.row][current_cell.col + 1] == 0 && !visited[current_cell.row][current_cell.col + 1]) 
        {
            push(stack, (struct Cell) {current_cell.row, current_cell.col + 1}); // east
            visited[current_cell.row][current_cell.col + 1] = dist + 1;
        }

        if (current_cell.row < ROW - 1 && maze[current_cell.row + 1][current_cell.col] == 0 && !visited[current_cell.row + 1][current_cell.col]) 
        {
            push(stack, (struct Cell) {current_cell.row + 1, current_cell.col}); // south
            visited[current_cell.row + 1][current_cell.col] = dist + 1;
        }

        if (current_cell.col > 0 && maze[current_cell.row][current_cell.col - 1] == 0 && !visited[current_cell.row][current_cell.col - 1]) 
        {
            push(stack, (struct Cell) {current_cell.row, current_cell.col - 1}); // west
            visited[current_cell.row][current_cell.col - 1] = dist + 1;
        }

        // if destination cell is found, the loop is terminated and shortest path is returned
        if (visited[dest_row][dest_col] != 0) 
        {
            printf("Shortest path to destination cell is %d\n", visited[dest_row][dest_col]);
            return;
        }
    }

    // if destination cell is not found
    printf("Destination cell not found!\n");
}

void printMaze(int maze[][COL])
{
    for (int i = 0; i < ROW; i++) 
    {
        for (int j = 0; j < COL; j++) 
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    // example maze
    int maze[ROW][COL] = 
    {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0}
    };

    int visited[ROW][COL];

    // displaying the maze
    printf("Maze:\n");
    printMaze(maze);

    // finding shortest path from (0,0) to (4,4)
    printf("\nFinding shortest path from (0,0) to (4,4):\n");
    findShortestPath(maze, visited, 0, 0, 4, 4);

    return 0;
}