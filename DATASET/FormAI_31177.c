//FormAI DATASET v1.0 Category: Computer Biology ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

typedef struct {
    int x;
    int y;
    int result;
} Point;

void *add(void *arg) {
    Point *point = (Point *) arg;
    point->result = point->x + point->y;
    return NULL;
}

void *subtract(void *arg) {
    Point *point = (Point *) arg;
    point->result = point->x - point->y;
    return NULL;
}

int main() {
    Point point_add = {5, 3, 0};
    Point point_subtract = {7, 2, 0};
    pthread_t thread_add, thread_subtract;

    pthread_create(&thread_add, NULL, add, &point_add);
    pthread_create(&thread_subtract, NULL, subtract, &point_subtract);

    pthread_join(thread_add, NULL);
    pthread_join(thread_subtract, NULL);

    printf("Adding %d and %d results in %d\n", point_add.x, point_add.y, point_add.result);
    printf("Subtracting %d from %d results in %d\n", point_subtract.y, point_subtract.x, point_subtract.result);

    return 0;
}