//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Romeo and Juliet
/* Romeo and Juliet Geometric Algorithms */

#include <stdio.h>

/* Define Points Struct */
typedef struct {
    int x;
    int y;
} point;

/* Define Distance Function */
double distance(point p1, point p2) {
    int x_diff = p1.x - p2.x;
    int y_diff = p1.y - p2.y;
    return sqrt(x_diff*x_diff + y_diff*y_diff);
}

int main() {
    /* Declarations */
    point romeo = {2, 5};
    point juliet = {8, 3};
    double dist;

    /* Romeo and Juliet meet and fall in love */
    printf("Romeo and Juliet met and fell in love!\n\n");

    /* Romeo wants to impress Juliet with his knowledge of geometry */
    printf("Romeo: My love, did you know the distance between us is %f units?\n", distance(romeo, juliet));

    /* Juliet is impressed */
    printf("Juliet: Wow, Romeo! How did you calculate that?\n");

    /* Romeo explains his algorithm */
    printf("Romeo: I used the distance formula, which is: sqrt((x1-x2)^2 + (y1-y2)^2).\n");

    /* Juliet is even more impressed */
    printf("Juliet: You are so smart, Romeo!\n");

    /* Romeo and Juliet live happily ever after */
    printf("Romeo and Juliet lived happily ever after. The end.\n");

    return 0;
}