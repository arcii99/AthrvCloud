//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#define MAX_POINTS 100

struct Point {
    int x;
    int y;
};

struct Polygon {
    struct Point points[MAX_POINTS];
    int numPoints;
};

int areaOfTriangle(struct Point a, struct Point b, struct Point c) {
    return abs((a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y))/2);
}

int isInsideTriangle(struct Point p, struct Point a, struct Point b, struct Point c) {
    int area = areaOfTriangle(a, b, c);
    int area1 = areaOfTriangle(p, b, c);
    int area2 = areaOfTriangle(p, a, c);
    int area3 = areaOfTriangle(p, a, b);
    if(area == area1 + area2 + area3)
        return 1;
    else
        return 0;
}

int isInsidePolygon(struct Point p, struct Polygon poly) {
    int i, j, c = 0, n = poly.numPoints;
    struct Point outside = {99999, 99999};
    for(i = 0, j = n-1; i < n; j = i++) {
        if(isInsideTriangle(p, poly.points[i], poly.points[j], outside)) {
            c = !c;
        }
    }
    return c;
}

void printPoints(struct Point arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("(%d, %d) ", arr[i].x, arr[i].y);
    }
    printf("\n");
}

void printPolygon(struct Polygon poly) {
    printf("Points in polygon: ");
    printPoints(poly.points, poly.numPoints);
}

void drawLine(int x1, int y1, int x2, int y2) {
    printf("Drawing line from (%d, %d) to (%d, %d)\n", x1, y1, x2, y2);
}

void drawPolygonAux(struct Point arr[], int n) {
    if(n == 1) {
        printf("Nothing to draw. Need atleast 2 points.\n");
        return;
    }
    else if(n == 2) {
        drawLine(arr[0].x, arr[0].y, arr[1].x, arr[1].y);
        return;
    }
    else if(n == 3) {
        drawLine(arr[0].x, arr[0].y, arr[1].x, arr[1].y);
        drawLine(arr[1].x, arr[1].y, arr[2].x, arr[2].y);
        drawLine(arr[2].x, arr[2].y, arr[0].x, arr[0].y);
        return;
    }
    int i, maxy, maxi, startindex = 0;
    maxy = arr[0].y;
    maxi = 0;
    for(i = 1; i < n; i++) {
        if(arr[i].y > maxy) {
            maxy = arr[i].y;
            maxi = i;
        }
    }
    struct Point tmp = arr[0];
    arr[0] = arr[maxi];
    arr[maxi] = tmp;

    struct Point pivot = arr[startindex];
    int j;
    for(i = 1, j = n-1; i <= j;) {
        if(isInsideTriangle(arr[i], pivot, arr[(i+1)%n], arr[j])) {
            i++;
        }
        else if(isInsideTriangle(arr[j], pivot, arr[(i+1)%n], arr[j-1])) {
            j--;
        }
        else {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    struct Polygon poly1, poly2;
    poly1.numPoints = i;
    poly2.numPoints = n-i;
    for(int k = 0; k < i; k++) {
        poly1.points[k] = arr[k];
    }
    for(int k = i; k < n; k++) {
        poly2.points[k-i] = arr[k];
    }
    printPolygon(poly1);
    printPolygon(poly2);
    drawPolygonAux(poly1.points, poly1.numPoints);
    drawPolygonAux(poly2.points, poly2.numPoints);   
}

void drawPolygon(struct Polygon poly) {
    printf("Drawing polygon:\n");
    drawPolygonAux(poly.points, poly.numPoints);
}

int main() {
    struct Point a = {0, 0};
    struct Point b = {5, 0};
    struct Point c = {0, 5};
    struct Point d = {-3, 3};
    struct Point e = {-2, 1};
    struct Point f = {-2, 5};

    struct Polygon poly;
    poly.numPoints = 6;
    poly.points[0] = a;
    poly.points[1] = b;
    poly.points[2] = c;
    poly.points[3] = d;
    poly.points[4] = e;
    poly.points[5] = f;

    printPolygon(poly);
    drawPolygon(poly);

    return 0;
}