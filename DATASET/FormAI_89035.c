//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define POINTS 20
#define CENTERS 3

struct point {
    int x;
    int y;
};

// Initialize an array of random points
void init_points(struct point *array){
    for(int i = 0; i < POINTS; i++){
        array[i].x = rand() % 100;
        array[i].y = rand() % 100;
    }
}

// Initialize an array of random centers
void init_centers(struct point *array){
    for(int i = 0; i < CENTERS; i++){
        array[i].x = rand() % 100;
        array[i].y = rand() % 100;
    }
}

// Return the distance between two points
int distance(struct point p1, struct point p2){
    int x_diff = p1.x - p2.x;
    int y_diff = p1.y - p2.y;

    return x_diff * x_diff + y_diff * y_diff;
}

// Assign each point to the closest center
void assign_points_to_centers(struct point *points, struct point *centers, int *assignments){
    for(int i = 0; i < POINTS; i++){
        int min_distance = 1000000;
        int closest_center = 0;

        for(int j = 0; j < CENTERS; j++){
            int d = distance(points[i], centers[j]);
            if(d < min_distance){
                min_distance = d;
                closest_center = j;
            }
        }

        assignments[i] = closest_center;
    }
}

// Update the centers based on the assigned points
void update_centers(struct point *points, struct point *centers, int *assignments){
    int x_totals[CENTERS] = {0};
    int y_totals[CENTERS] = {0};
    int count[CENTERS] = {0};

    for(int i = 0; i < POINTS; i++){
        int center = assignments[i];
        x_totals[center] += points[i].x;
        y_totals[center] += points[i].y;
        count[center]++;
    }

    for(int i = 0; i < CENTERS; i++){
        if(count[i] != 0){
            centers[i].x = x_totals[i] / count[i];
            centers[i].y = y_totals[i] / count[i];
        }
    }
}

// Print the current state of the program
void print_state(struct point *points, struct point *centers, int *assignments){
    printf("Points:\n");
    for(int i = 0; i < POINTS; i++){
        printf("(%d,%d) ", points[i].x, points[i].y);
    }
    printf("\n\n");

    printf("Centers:\n");
    for(int i = 0; i < CENTERS; i++){
        printf("(%d,%d) ", centers[i].x, centers[i].y);
    }
    printf("\n\n");

    printf("Assignments:\n");
    for(int i = 0; i < POINTS; i++){
        printf("%d ", assignments[i]);
    }
    printf("\n\n");
}

int main(void){
    struct point points[POINTS];
    struct point centers[CENTERS];
    int assignments[POINTS] = {0};

    init_points(points);
    init_centers(centers);
    print_state(points, centers, assignments);

    for(int i = 0; i < 10; i++){
        assign_points_to_centers(points, centers, assignments);
        update_centers(points, centers, assignments);
        print_state(points, centers, assignments);
    }

    return 0;
}