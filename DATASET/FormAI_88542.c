//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point start;
    Point end;
} Line;

void drawLine(Line l) {
    int xDir = (l.start.x < l.end.x) ? 1 : -1;
    int yDir = (l.start.y < l.end.y) ? 1 : -1;
    int xDiff = abs(l.end.x - l.start.x);
    int yDiff = abs(l.end.y - l.start.y);
    int error = 0;
    int x = l.start.x;
    int y = l.start.y;
    int i;

    if (xDiff > yDiff) {
        for (i = 0; i <= xDiff; i++) {
            printf("(%d, %d)\n", x, y);
            if (error >= xDiff) {
                error -= xDiff;
                y += yDir;
            }
            error += yDiff;
            x += xDir;
        }
    } else {
        for (i = 0; i <= yDiff; i++) {
            printf("(%d, %d)\n", x, y);
            if (error >= yDiff) {
                error -= yDiff;
                x += xDir;
            }
            error += xDiff;
            y += yDir;
        }
    }
}

int main() {
    Line l1 = {{0, 0}, {10, 5}};
    Line l2 = {{5, 10}, {15, 15}};

    drawLine(l1);
    printf("------\n");
    drawLine(l2);

    return 0;
}