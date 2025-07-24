//FormAI DATASET v1.0 Category: Data mining ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 50
#define MAX_DATA_POINTS 10

struct data_point {
    int x;
    float y;
};

void print_data_point(struct data_point ptr) {
    printf("(%d, %f)\n", ptr.x, ptr.y);
}

void print_data_points(struct data_point* ptr, int size) {
    for (int i = 0; i < size; i++) {
        print_data_point(ptr[i]);
    }
}

void populate_data_points(struct data_point* ptr) {
    for (int i = 0; i < MAX_DATA_POINTS; i++) {
        ptr[i].x = i;
        ptr[i].y = (float)i * 0.5;
    }
}

int main() {
    struct data_point data_points[MAX_DATA_POINTS];
    populate_data_points(data_points);
    print_data_points(data_points, MAX_DATA_POINTS);
    return 0;
}