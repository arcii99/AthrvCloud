//FormAI DATASET v1.0 Category: Fractal Generation ; Style: shape shifting
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void sierpinski(int depth, int x1, int y1, int x2, int y2, int x3, int y3) {
    if (depth <= 0) {
        int rand_num = rand() % 6;
        if (rand_num == 0) {
            printf("circle(%d,%d,%d)\n", (x1+x2+x3)/3, (y1+y2+y3)/3, (int)(sqrt(pow((x2-x1),2) + pow((y2-y1),2))/2));
        }
        else if (rand_num == 1) {
            printf("rect(%d,%d,%d,%d)\n", x1, y1, (x2-x1), (y3-y1));
        }
        else if (rand_num == 2) {
            printf("triangle(%d,%d,%d,%d,%d,%d)\n", x1, y1, x2, y2, x3, y3);
        }
        else if (rand_num == 3) {
            printf("line(%d,%d,%d,%d)\n", x1, y1, x2, y2);
        }
        else if (rand_num == 4) {
            printf("point(%d,%d)\n", x1, y1);
        }
        else {
            printf("poly(%d,%d,%d,%d,%d,%d,%d,%d)\n", x1, y1, x2, y2, x2/2 + x3/2, y2/2 + y3/2, x3, y3);
        }
    }
    else {
        int x4 = (x1 + x2)/2;
        int y4 = (y1 + y2)/2;
        int x5 = (x2 + x3)/2;
        int y5 = (y2 + y3)/2;
        int x6 = (x3 + x1)/2;
        int y6 = (y3 + y1)/2;

        sierpinski(depth-1, x1, y1, x4, y4, x6, y6);
        sierpinski(depth-1, x4, y4, x2, y2, x5, y5);
        sierpinski(depth-1, x6, y6, x5, y5, x3, y3);
    }
}

int main() {
    srand(time(0));
    sierpinski(6, 20, 450, 470, 450, 245, 20);
    return 0;
}