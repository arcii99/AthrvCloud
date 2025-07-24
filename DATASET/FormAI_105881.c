//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

typedef struct node
{
    int row;
    int col;
    struct node* next;
} Node;

Node* createNode(int row, int col) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;

    return newNode;
}

void push(Node** head_ref, int row, int col)
{
    Node* newNode = createNode(row, col);

    newNode->next = *head_ref;
    *head_ref = newNode;
}

void pop(Node** head_ref)
{
    if (*head_ref == NULL)
        return;

    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

bool isQueueEmpty(Node** head_ref) {
    return (*head_ref == NULL);
}

bool isValid(int maze[ROW][COL], int row, int col)
{
    if (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col])
        return true;
    else
        return false;
}

void markVisited(int visited[ROW][COL], int row, int col)
{
    visited[row][col] = 1;
}

bool isVisited(int visited[ROW][COL], int row, int col)
{
    if (visited[row][col] == 1)
        return true;
    else
        return false;
}

void printPath(Node** path_head_ref)
{
    Node* temp = *path_head_ref;
    printf("\nThe route to the destination (starting from origin): \n");
    while (temp != NULL)
    {
        printf("(%d,%d) -> ", temp->row, temp->col);
        temp = temp->next;
    }
    printf("Destination!");
}

void findPath(int maze[ROW][COL], int visited[ROW][COL], int start_row, int start_col, int end_row, int end_col)
{
    Node* queue_head = NULL;
    Node* path_head = NULL;

    push(&queue_head, start_row, start_col);
    markVisited(visited, start_row, start_col);

    bool found = false;

    while (!isQueueEmpty(&queue_head))
    {
        int row = queue_head->row;
        int col = queue_head->col;
        pop(&queue_head);

        if (row == end_row && col == end_col)
        {
            found = true;
            push(&path_head, row, col);

            printPath(&path_head);
            break;
        }

        if (isValid(maze, row-1, col) && !isVisited(visited, row-1, col)) // Up
        {
            push(&queue_head, row-1, col);
            push(&path_head, row, col);
            markVisited(visited, row-1, col);
        }
        if (isValid(maze, row, col+1) && !isVisited(visited, row, col+1)) // Right
        {
            push(&queue_head, row, col+1);
            push(&path_head, row, col);
            markVisited(visited, row, col+1);
        }
        if (isValid(maze, row+1, col) && !isVisited(visited, row+1, col)) // Down
        {
            push(&queue_head, row+1, col);
            push(&path_head, row, col);
            markVisited(visited, row+1, col);
        }
        if (isValid(maze, row, col-1) && !isVisited(visited, row, col-1)) // Left
        {
            push(&queue_head, row, col-1);
            push(&path_head, row, col);
            markVisited(visited, row, col-1);
        }
    }

    if (!found)
        printf("\nSorry, there is no route to the destination.");
}

int main()
{
    int maze[ROW][COL] = { {1, 0, 0, 1, 1, 1, 1, 0, 0, 1},
                           {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
                           {0, 1, 0, 0, 1, 1, 1, 0, 0, 1},
                           {1, 1, 0, 1, 0, 1, 1, 1, 1, 1},
                           {1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
                           {1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
                           {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
                           {0, 0, 1, 1, 1, 0, 1, 1, 1, 1},
                           {0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
                           {1, 1, 0, 1, 1, 1, 1, 1, 1, 1} };

    int visited[ROW][COL] = { 0 };

    int start_row = 0;
    int start_col = 0;
    int end_row = 9;
    int end_col = 9;

    printf(" ----------------------------------------------------\n");
    printf("|                                                    |\n");
    printf("|                WELCOME TO MAZE RUNNER!              |\n");
    printf("|                                                    |\n");
    printf(" ----------------------------------------------------\n\n");

    printf("You are a cyberpunk trying to escape a facility. Your goal is to reach the exit located at (9,9).\n\n");
    printf("Here is the maze : \n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (maze[i][j] == 1)
            {
                printf("|%c", ' ');
            }
            else
            {
                printf("|%c", 'W');
            }
        }
        printf("|\n");
    }

    findPath(maze, visited, start_row, start_col, end_row, end_col);

    return 0;
}