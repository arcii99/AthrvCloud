//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point{
    float x, y;
};

struct shape{
    int type;
    struct point *vertices;
};

float distance(struct point p1, struct point p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

float triangle_perimeter(struct point *vertices){
    float perimeter = 0;
    for(int i=0; i<3; i++){
        perimeter += distance(vertices[i], vertices[(i+1)%3]);
    }
    return perimeter;
}

void square_generator(struct point *vertices, float side){
    vertices[0] = (struct point){0, 0};
    vertices[1] = (struct point){side, 0};
    vertices[2] = (struct point){side, side};
    vertices[3] = (struct point){0, side};
}

void rectangle_generator(struct point *vertices, float length, float breadth){
    vertices[0] = (struct point){0, 0};
    vertices[1] = (struct point){length, 0};
    vertices[2] = (struct point){length, breadth};
    vertices[3] = (struct point){0, breadth};
}

int main(){

    struct shape shapes[3];
    shapes[0].type = 0;
    shapes[1].type = 1;
    shapes[2].type = 2;

    shapes[0].vertices = (struct point*)malloc(3*sizeof(struct point));
    shapes[1].vertices = (struct point*)malloc(4*sizeof(struct point));
    shapes[2].vertices = (struct point*)malloc(4*sizeof(struct point));

    square_generator(shapes[0].vertices, 5);
    rectangle_generator(shapes[1].vertices, 10, 5);
    rectangle_generator(shapes[2].vertices, 6, 8);

    float perimeters[3];

    #pragma omp parallel for
    for(int i=0; i<3; i++){
        if(shapes[i].type == 0) perimeters[i] = triangle_perimeter(shapes[i].vertices);
        else perimeters[i] = 2*(distance(shapes[i].vertices[0], shapes[i].vertices[1]) + distance(shapes[i].vertices[1], shapes[i].vertices[2]));
    }

    printf("Perimeters of Shapes:\n");
    for(int i=0; i<3; i++){
        printf("%d: %f\n", i+1, perimeters[i]);
        free(shapes[i].vertices);
    }

    return 0;
}