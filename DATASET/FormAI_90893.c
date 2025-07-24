//FormAI DATASET v1.0 Category: Fractal Generation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 40
#define MIN_SIZE 3

char canvas[HEIGHT][WIDTH+1];
int idCounter = 0;

typedef struct
{
    int id;
    int x;
    int y;
    int size;
} Shape;

Shape createRandomShape(int x, int y, int size)
{
    Shape shape;
    shape.id = idCounter++;
    shape.x = x;
    shape.y = y;
    shape.size = size;
    return shape;
}

int fractalSize(int size)
{
    if (size <= MIN_SIZE)
    {
        return size;
    }

    int a = rand() % (size / 3);
    int b = rand() % (size / 3);
    return fractalSize(size / 3) + fractalSize(size / 3) + fractalSize(size / 3);
}

void generateFractalShapes(int x, int y, int size, int parentId)
{
    Shape shape = createRandomShape(x, y, size);
    if (parentId != -1)
    {
        printf("Player %d created shape %d with parent %d\n", 0, shape.id, parentId);
    }
    else
    {
        printf("Player %d created shape %d\n", 0, shape.id);
    }

    if (size <= MIN_SIZE)
    {
        return;
    }

    int childSize = fractalSize(size);
    generateFractalShapes(x - (size / 2), y - (size / 2), childSize, shape.id);
    generateFractalShapes(x + (size / 2), y - (size / 2), childSize, shape.id);
    generateFractalShapes(x - (size / 2), y + (size / 2), childSize, shape.id);
    generateFractalShapes(x + (size / 2), y + (size / 2), childSize, shape.id);
}

void initializeCanvas()
{
    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            canvas[i][j] = ' ';
        }
        canvas[i][WIDTH] = '\0';
    }
}

void drawShape(Shape shape)
{
    int i, j;
    int halfSize = shape.size / 2;
    int startX = shape.x - halfSize;
    int startY = shape.y - halfSize;

    for (i = 0; i < shape.size; i++)
    {
        for (j = 0; j < shape.size; j++)
        {
            int x = startX + i;
            int y = startY + j;
            if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
            {
                if (canvas[y][x] == ' ')
                {
                    canvas[y][x] = '+';
                }
                else
                {
                    canvas[y][x] = '*';
                }
            }
        }
    }
}

void drawShapes(Shape *shapes, int numShapes)
{
    int i;
    for (i = 0; i < numShapes; i++)
    {
        drawShape(shapes[i]);
    }
}

void displayCanvas()
{
    int i;
    printf("+");
    for (i = 0; i < WIDTH; i++)
    {
        printf("-");
    }
    printf("+\n");

    for (i = 0; i < HEIGHT; i++)
    {
        printf("|%s|\n", canvas[i]);
    }

    printf("+");
    for (i = 0; i < WIDTH; i++)
    {
        printf("-");
    }
    printf("+\n");
}

int main()
{
    srand(time(NULL));
    initializeCanvas();
    generateFractalShapes(WIDTH / 2, HEIGHT / 2, 27, -1);
    displayCanvas();
    return 0;
}