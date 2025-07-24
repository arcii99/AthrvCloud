//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: paranoid
#include <stdio.h>

#define ROWS 10
#define COLS 20

char myMaze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ',', ' ', '#', ' ', ' ', '#'},
    {'#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#', '#'},
    {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', '#'}
};

int startRow = 1;
int startCol = 1;
int endRow = 9;
int endCol = 18;

typedef struct Node Node;

struct Node
{
    int row, col;
    Node *parent;
};

Node openList[ROWS*COLS];
int openListSize = 0;

void push(Node n)
{
    openList[openListSize++] = n;
}

Node pop()
{
    Node min = openList[0];
    for (int i = 0; i<openListSize; i++)
    {
        if (openList[i].row == endRow && openList[i].col == endCol)
        {
            return openList[i];
        }
        if ((openList[i].row + openList[i].col) < (min.row + min.col))
        {
            min = openList[i];
        }
    }

    openListSize--;

    for (int i = 0; i<openListSize; i++)
    {
        if (openList[i].row == min.row && openList[i].col == min.col)
        {
            for (int j = i; j<openListSize; j++)
            {
                openList[j] = openList[j+1];
            }
            break;
        }
    }

    return min;
}

int isWithinBounds(int row, int col)
{
    return (row>=0) && (row<ROWS) && (col>=0) && (col<COLS);
}

int isTraversible(int row, int col)
{
    return (myMaze[row][col] != '#');
}

Node createNode(int row, int col, Node *parent)
{
    Node n;
    n.row = row;
    n.col = col;
    n.parent = parent;

    return n;
}

Node* findPath()
{
    push(createNode(startRow, startCol, NULL));
    while (openListSize > 0)
    {
        Node current = pop();

        if (current.row == endRow && current.col == endCol)
        {
            return &current;
        }

        int row = current.row;
        int col = current.col;

        if (isWithinBounds(row-1, col) && isTraversible(row-1, col))
        {
            push(createNode(row-1, col, &current));
        }
        if (isWithinBounds(row+1, col) && isTraversible(row+1, col))
        {
            push(createNode(row+1, col, &current));
        }
        if (isWithinBounds(row, col-1) && isTraversible(row, col-1))
        {
            push(createNode(row, col-1, &current));
        }
        if (isWithinBounds(row, col+1) && isTraversible(row, col+1))
        {
            push(createNode(row, col+1, &current));
        }
    }

    return NULL;
}

void printPath(Node* endNode)
{
    while (endNode != NULL)
    {
        printf("(%d,%d)->", endNode->row+1, endNode->col+1);

        endNode = endNode->parent;
    }
    printf("End\n");
}

int main()
{
    Node *end = findPath();

    if (end != NULL)
    {
        printf("Path found!\n\n");

        printf("Path: ");
        printPath(end);
    }
    else
    {
        printf("Path not found :(\n");
    }

    return 0;
}