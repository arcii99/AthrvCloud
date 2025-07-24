//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: authentic
#include <stdio.h>
#include <math.h>

typedef struct {
    float x, y;
} Point;

typedef struct {
    Point A, B, C;
} Triangle;

int isInTriangle(Point P, Triangle T) {
    float abcArea, pabArea, pbcArea, pcaArea;
    abcArea = fabs((T.B.x - T.A.x)*(T.C.y - T.A.y) - (T.C.x - T.A.x)*(T.B.y - T.A.y));
    pabArea = fabs((P.x - T.A.x)*(T.B.y - P.y) - (T.B.x - P.x)*(T.A.y - P.y));
    pbcArea = fabs((P.x - T.B.x)*(T.C.y - P.y) - (T.C.x - P.x)*(T.B.y - P.y));
    pcaArea = fabs((P.x - T.C.x)*(T.A.y - P.y) - (T.A.x - P.x)*(T.C.y - P.y));
    float sumAreas = pabArea + pbcArea + pcaArea;
    return (fabs(sumAreas - abcArea) < 0.0001);
}

int main() {
    Point P = {1.0, 1.0};
    Triangle T = {{0.0, 0.0}, {2.0, 0.0}, {0.0, 2.0}};

    if (isInTriangle(P, T)) {
        printf("Point (%g, %g) is inside the triangle.\n", P.x, P.y);
    } else {
        printf("Point (%g, %g) is not inside the triangle.\n", P.x, P.y);
    }
    return 0;
}