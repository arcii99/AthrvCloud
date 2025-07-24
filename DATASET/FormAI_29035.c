//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

struct Line {
    struct Point p1;
    struct Point p2;
};

int isCollinear(struct Point a, struct Point b, struct Point c) {
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if(area == 0) {
        return 1;
    }
    return 0;
}

int isIntersecting(struct Line l1, struct Line l2) {
    int a1 = l1.p2.y - l1.p1.y;
    int b1 = l1.p1.x - l1.p2.x;
    int c1 = a1 * l1.p1.x + b1 * l1.p1.y;
    int a2 = l2.p2.y - l2.p1.y;
    int b2 = l2.p1.x - l2.p2.x;
    int c2 = a2 * l2.p1.x + b2 * l2.p1.y;
    int determinant = a1 * b2 - a2 * b1;
    if(determinant == 0) {
        return 0;
    }
    else {
        int intersect_x = (b2 * c1 - b1 * c2) / determinant;
        int intersect_y = (a1 * c2 - a2 * c1) / determinant;
        if((intersect_x >= l1.p1.x && intersect_x <= l1.p2.x || intersect_x >= l1.p2.x && intersect_x <= l1.p1.x) && (intersect_y >= l1.p1.y && intersect_y <= l1.p2.y || intersect_y >= l1.p2.y && intersect_y <= l1.p1.y) && (intersect_x >= l2.p1.x && intersect_x <= l2.p2.x || intersect_x >= l2.p2.x && intersect_x <= l2.p1.x) && (intersect_y >= l2.p1.y && intersect_y <= l2.p2.y || intersect_y >= l2.p2.y && intersect_y <= l2.p1.y)) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

void createKochCurve(int n, struct Point p1, struct Point p2) {
    if(n == 0) {
        printf("%d %d %d %d\n", p1.x, p1.y, p2.x, p2.y);
        return;
    }
    else {
        int distance_x = p2.x - p1.x;
        int distance_y = p2.y - p1.y;
        struct Point p3 = {p1.x + distance_x / 3, p1.y + distance_y / 3};
        struct Point p4 = {p3.x + distance_x / 6, p3.y - distance_y / 6};
        struct Point p5 = {p1.x + 2 * distance_x / 3, p1.y + 2 * distance_y / 3};
        createKochCurve(n - 1, p1, p3);
        createKochCurve(n - 1, p3, p4);
        createKochCurve(n - 1, p4, p5);
        createKochCurve(n - 1, p5, p2);
        return;
    }
}

int isInsidePolygon(int n, struct Line polygon[n], struct Point point) {
    int count = 0;
    struct Line line = {point, {10000, point.y}};
    for(int i=0; i<n; i++) {
        if(isCollinear(point, polygon[i].p1, polygon[i].p2)) {
            return 1;
        }
        if(isIntersecting(line, polygon[i])) {
            count++;
        }
    }
    if(count % 2 == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int main() {
    // Koch Cüvesi
    
    struct Point p1 = {300, 200};
    struct Point p2 = {800, 200};
    createKochCurve(4, p1, p2);
    
    struct Point p3 = {800, 200};
    struct Point p4 = {550, 600};
    createKochCurve(4, p3, p4);
    
    struct Point p5 = {550, 600};
    struct Point p6 = {300, 200};
    createKochCurve(4, p5, p6);
    
    
    // Kapalı alan
    
    struct Line polygon[4] = {{{200, 200}, {500, 200}}, {{500, 200}, {500, 500}}, {{500, 500}, {200, 500}}, {{200, 500}, {200, 200}}};
    
    struct Point point1 = {400, 400};
    struct Point point2 = {250, 250};
    
    if(isInsidePolygon(4, polygon, point1)) {
        printf("point1 is inside the polygon\n");
    }
    else {
        printf("point1 is outside the polygon\n");
    }
    
    if(isInsidePolygon(4, polygon, point2)) {
        printf("point2 is inside the polygon\n");
    }
    else {
        printf("point2 is outside the polygon\n");
    }
    
    return 0;
}