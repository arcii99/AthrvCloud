//FormAI DATASET v1.0 Category: QR code generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SHAPE 5
#define MAX_SIZE 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point points[MAX_SIZE];
    int size;
} Shape;

void generateQRCode(Shape* shapes, int numShapes);

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    int numShapes = rand() % MAX_SHAPE + 1;
    Shape shapes[numShapes];

    generateQRCode(shapes, numShapes);

    for (int i = 0; i < numShapes; i++) {
        printf("Shape #%d:\n", i + 1);
        for (int j = 0; j < shapes[i].size; j++) {
            printf("(%d, %d) ", shapes[i].points[j].x, shapes[i].points[j].y);
        }
        printf("\n");
    }

    return 0;
}

void generateQRCode(Shape* shapes, int numShapes) {
    int currX = 0, currY = 0;
    for (int i = 0; i < numShapes; i++) {
        shapes[i].size = rand() % MAX_SIZE + 1;

        for (int j = 0; j < shapes[i].size; j++) {
            Point p;
            p.x = currX + rand() % 3 - 1;
            p.y = currY + rand() % 3 - 1;

            shapes[i].points[j] = p;

            currX = p.x;
            currY = p.y;
        }
    }
}