//FormAI DATASET v1.0 Category: Image Editor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

typedef struct {
    Point *vertices;
    int numVertices;
    Color fill;
    int thickness;
} Shape;

typedef enum {
    RECTANGLE,
    CIRCLE,
    TRIANGLE
} ShapeType;

typedef struct {
    ShapeType type;
    Shape *shape;
} Drawable;

int main() {
    char input[100];
    Drawable *canvas[WIDTH][HEIGHT];
    memset(canvas, 0, sizeof(Drawable*) * WIDTH * HEIGHT);
    printf("Welcome to the Shape Shifting Image Editor!\n");
    while (1) {
        printf("> ");
        fgets(input, 100, stdin);
        input[strlen(input)-1] = '\0'; // Remove trailing newline
        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "help") == 0) {
            printf("Commands:\n");
            printf("  draw <shape> <x> <y> [args...]  Draws a shape at the given position\n");
            printf("    Supported shapes: rectangle, circle, triangle\n");
            printf("  move <x1> <y1> <x2> <y2>         Moves a shape from (x1, y1) to (x2, y2)\n");
            printf("  delete <x> <y>                    Deletes the shape at the given position\n");
            printf("  save <filename>                   Saves the current canvas to a file\n");
            printf("  load <filename>                   Loads a canvas from a file\n");
            printf("  help                              Shows this help message\n");
            printf("  exit                              Exits the program\n");
        } else if (strncmp(input, "draw", 4) == 0) {
            // Draw a shape
            char shapeName[20];
            int x, y, args[10];
            int numArgs = 0;
            sscanf(input+4, "%19s %d %d %d %d %d %d %d %d %d %d",
                   shapeName, &x, &y, &args[0], &args[1], &args[2], &args[3],
                   &args[4], &args[5], &args[6], &args[7], &args[8], &args[9]);
            if (strcmp(shapeName, "rectangle") == 0) {
                Shape *rect = malloc(sizeof(Shape));
                rect->numVertices = 4;
                rect->vertices = malloc(sizeof(Point) * 4);
                rect->vertices[0] = (Point){x, y};
                rect->vertices[1] = (Point){x+args[0], y};
                rect->vertices[2] = (Point){x+args[0], y+args[1]};
                rect->vertices[3] = (Point){x, y+args[1]};
                rect->fill = (Color){255, 255, 255};
                rect->thickness = 1;
                canvas[x][y] = malloc(sizeof(Drawable));
                canvas[x][y]->type = RECTANGLE;
                canvas[x][y]->shape = rect;
            } else if (strcmp(shapeName, "circle") == 0) {
                Shape *circle = malloc(sizeof(Shape));
                circle->numVertices = 1;
                circle->vertices = malloc(sizeof(Point));
                circle->vertices[0] = (Point){x, y};
                circle->fill = (Color){255, 255, 255};
                circle->thickness = 1;
                canvas[x][y] = malloc(sizeof(Drawable));
                canvas[x][y]->type = CIRCLE;
                canvas[x][y]->shape = circle;
            } else if (strcmp(shapeName, "triangle") == 0) {
                Shape *tri = malloc(sizeof(Shape));
                tri->numVertices = 3;
                tri->vertices = malloc(sizeof(Point) * 3);
                tri->vertices[0] = (Point){x, y};
                tri->vertices[1] = (Point){x+args[0], y};
                tri->vertices[2] = (Point){x+args[1], y+args[2]};
                tri->fill = (Color){255, 255, 255};
                tri->thickness = 1;
                canvas[x][y] = malloc(sizeof(Drawable));
                canvas[x][y]->type = TRIANGLE;
                canvas[x][y]->shape = tri;
            } else {
                printf("Unknown shape: %s\n", shapeName);
            }
        } else if (strncmp(input, "move", 4) == 0) {
            // Move a shape
            int x1, y1, x2, y2;
            sscanf(input+4, "%d %d %d %d", &x1, &y1, &x2, &y2);
            Drawable *d = canvas[x1][y1];
            canvas[x1][y1] = NULL;
            canvas[x2][y2] = d;
        } else if (strncmp(input, "delete", 6) == 0) {
            // Delete a shape
            int x, y;
            sscanf(input+6, "%d %d", &x, &y);
            free(canvas[x][y]->shape->vertices);
            free(canvas[x][y]->shape);
            free(canvas[x][y]);
            canvas[x][y] = NULL;
        } else if (strncmp(input, "save", 4) == 0) {
            // Save the canvas to a file
            char filename[100];
            sscanf(input+4, "%99s", filename);
            FILE *fp = fopen(filename, "wb");
            fwrite(canvas, sizeof(Drawable*), WIDTH*HEIGHT, fp);
            fclose(fp);
        } else if (strncmp(input, "load", 4) == 0) {
            // Load a canvas from a file
            char filename[100];
            sscanf(input+4, "%99s", filename);
            FILE *fp = fopen(filename, "rb");
            fread(canvas, sizeof(Drawable*), WIDTH*HEIGHT, fp);
            fclose(fp);
        } else {
            printf("Unknown command: %s\n", input);
        }
    }
    // Cleanup
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (canvas[i][j] != NULL) {
                free(canvas[i][j]->shape->vertices);
                free(canvas[i][j]->shape);
                free(canvas[i][j]);
            }
        }
    }
    return 0;
}