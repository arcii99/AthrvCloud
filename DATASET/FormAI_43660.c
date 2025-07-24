//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
    { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
    { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
    { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

struct Node
{
    int x, y;
    struct Node* parent;
    int f, g, h;
};

struct List
{
    struct Node* data;
    struct List* next;
};

void push(struct List** head, struct Node* data)
{
    struct List* newNode = (struct List*)malloc(sizeof(struct List));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct List* current = *head;

    while (current->next)
    {
        current = current->next;
    }

    current->next = newNode;
}

void pop(struct List** head, struct Node* node)
{
    struct List* current = *head;
    struct List* prev = NULL;

    while (current)
    {
        if (current->data->x == node->x && current->data->y == node->y)
        {
            if (prev)
            {
                prev->next = current->next;
            }

            else
            {
                *head = current->next;
            }

            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }
}

int inList(struct List* head, struct Node* node)
{
    struct List* current = head;

    while (current)
    {
        if (current->data->x == node->x && current->data->y == node->y)
        {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

int heuristic(int x, int y, int tx, int ty)
{
    int dx = abs(tx - x);
    int dy = abs(ty - y);
    return dx + dy;
}

void printMaze()
{
    printf(" ");
    for (int i = 0; i < COLS; i++)
    {
        printf("_");
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("|");
        for (int j = 0; j < COLS; j++)
        {
            char c = maze[i][j] ? ' ' : '#';
            printf("%c", c);
        }
        printf("|\n");
    }
    printf(" ");
    for (int i = 0; i < COLS; i++)
    {
        printf("_");
    }
    printf("\n");
}

void printPath(struct Node* node)
{
    while (node)
    {
        maze[node->y][node->x] = 2;
        node = node->parent;
    }
    printMaze();
}

void aStar(int startX, int startY, int targetX, int targetY)
{
    struct List* openList = NULL;
    struct List* closedList = NULL;
    struct Node* startNode = (struct Node*)malloc(sizeof(struct Node));
    startNode->x = startX;
    startNode->y = startY;
    startNode->f = 0;
    startNode->g = 0;
    startNode->h = 0;
    startNode->parent = NULL;
    push(&openList, startNode);

    while (openList != NULL)
    {
        struct List* current = openList;
        struct Node* currentNode = current->data;

        for (struct List* tmp = openList; tmp != NULL; tmp = tmp->next)
        {
            struct Node* tmpNode = tmp->data;

            if (tmpNode->f < currentNode->f)
            {
                current = tmp;
                currentNode = tmpNode;
            }
        }

        pop(&openList, currentNode);
        push(&closedList, currentNode);

        if (currentNode->x == targetX && currentNode->y == targetY)
        {
            printPath(currentNode);
            return;
        }

        for (int y = currentNode->y - 1; y <= currentNode->y + 1; y++)
        {
            for (int x = currentNode->x - 1; x <= currentNode->x + 1; x++)
            {
                if (x >= 0 && x < COLS && y >= 0 && y < ROWS)
                {
                    if (maze[y][x] != 0 && (x != currentNode->x || y != currentNode->y))
                    {
                        struct Node* child = (struct Node*)malloc(sizeof(struct Node));
                        child->x = x;
                        child->y = y;
                        child->parent = currentNode;
                        child->g = currentNode->g + 1;
                        child->h = heuristic(x, y, targetX, targetY);
                        child->f = child->g + child->h;

                        if (inList(closedList, child))
                        {
                            free(child);
                            continue;
                        }

                        if (inList(openList, child))
                        {
                            struct List* current = openList;

                            while (current->data != child)
                            {
                                current = current->next;
                            }

                            struct Node* tmpNode = current->data;

                            if (child->g < tmpNode->g)
                            {
                                tmpNode->parent = child->parent;
                                tmpNode->g = child->g;
                                tmpNode->f = child->f;
                            }

                            free(child);
                            continue;
                        }

                        push(&openList, child);
                    }
                }
            }
        }
    }

    printf("No path found\n");
}

int main()
{
    printMaze();
    aStar(2, 0, 9, 9);
    return 0;
}