//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_POINTS 2000
#define MAX_THREADS 4

struct Point {
    float x;
    float y;
};

typedef struct {
    struct Point points[MAX_POINTS];
    int count;
    float area;
} Shape;

void *compute_area(void *arg) {
    Shape *shape = (Shape *)arg;
    float x1, y1, x2, y2;
    int i;
    float sum = 0;
    for (i = 0; i < shape->count - 1; i++) {
        x1 = shape->points[i].x;
        y1 = shape->points[i].y;
        x2 = shape->points[i+1].x;
        y2 = shape->points[i+1].y;
        sum += (x1 * y2 - x2 * y1);
    }
    shape->area = abs(sum) / 2;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    Shape shapes[MAX_THREADS];
    int num_shapes = 0;
    char c;
    while (1) {
        printf("Enter 's' to add a shape or 'c' to calculate area or 'q' to quit: ");
        scanf(" %c", &c);
        if (c == 's') {
            int i = 0;
            printf("Enter coordinates for shape (end with -1 -1):\n");
            while (1) {
                scanf("%f %f", &shapes[num_shapes].points[i].x, &shapes[num_shapes].points[i].y);
                if (shapes[num_shapes].points[i].x == -1 && shapes[num_shapes].points[i].y == -1)
                    break;
                i++;
            }
            shapes[num_shapes].count = i;
            num_shapes++;
        }
        else if (c == 'c') {
            int i;
            float total_area = 0;
            for (i = 0; i < num_shapes; i++) {
                printf("Calculating area for shape %d...\n", i+1);
                pthread_create(&threads[i], NULL, compute_area, (void *)&shapes[i]);
            }
            for (i = 0; i < num_shapes; i++) {
                pthread_join(threads[i], NULL);
                total_area += shapes[i].area;
            }
            printf("Total area of all shapes: %.2f\n", total_area);
            num_shapes = 0;
        }
        else if (c == 'q') {
            break;
        }
    }
    return 0;
}