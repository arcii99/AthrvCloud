//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x, y;
} Point;

typedef struct {
    Point p1, p2;
} Line;

int intersect(Line l1, Line l2, Point *p) {
    float d = (l1.p1.x-l1.p2.x)*(l2.p1.y-l2.p2.y) - (l1.p1.y-l1.p2.y)*(l2.p1.x-l2.p2.x);
    if (d == 0) return 0;

    float a = (l1.p1.x-l2.p1.x)*(l2.p1.y-l2.p2.y) - (l1.p1.y-l2.p1.y)*(l2.p1.x-l2.p2.x);
    float b = (l1.p1.x-l1.p2.x)*(l1.p1.y-l2.p1.y) - (l1.p1.x-l2.p1.x)*(l1.p1.y-l1.p2.y);

    p->x = a/d;
    p->y = b/d;

    if (p->x < fmin(l1.p1.x, l1.p2.x) || p->x > fmax(l1.p1.x, l1.p2.x)) return 0;
    if (p->x < fmin(l2.p1.x, l2.p2.x) || p->x > fmax(l2.p1.x, l2.p2.x)) return 0;
    return 1;
}

void test() {
    Line l1 = {{-5,10}, {5,-5}};
    Line l2 = {{-10,0}, {10,0}};

    Point p;
    int intersects = intersect(l1, l2, &p);

    if (intersects)
        printf("Intersection at %.2f,%.2f\n", p.x, p.y);
    else
        printf("No intersection found\n");
}

// async implementation
typedef struct {
    Line l1, l2;
    Point *result;
    int *intersects;
} IntersectTask;

void IntersectTask_run(void *v) {
    IntersectTask *task = (IntersectTask*) v;
    *task->intersects = intersect(task->l1, task->l2, task->result);
}

void intersectAsync(Line l1, Line l2, Point *p, int *intersects) {
    IntersectTask task = {l1, l2, p, intersects};
    // in a real implementation, we would start a new thread or something like that instead of simply
    // running the task immediately like this
    IntersectTask_run(&task);
}

int main() {
    test();

    // async test
    Point p;
    int intersects;
    Line l1 = {{-5,10}, {5,-5}};
    Line l2 = {{-10,0}, {10,0}};
    intersectAsync(l1, l2, &p, &intersects);

    printf("Running async task...\n");
    // wait for async task to finish before printing results
    while (!intersects);

    if (intersects)
        printf("Intersection at %.2f,%.2f\n", p.x, p.y);
    else
        printf("No intersection found\n");

    return 0;
}