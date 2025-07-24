//FormAI DATASET v1.0 Category: Data mining ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {
    int num_of_points;
    Point *points;
    FILE *file_pointer;
    char file_name[100];

    printf("Enter the name of the data file: ");
    scanf("%s", file_name);

    file_pointer = fopen(file_name, "r");
    if (file_pointer == NULL) {
        printf("Failed to open file %s\n", file_name);
        return 1;
    }

    fscanf(file_pointer, "%d", &num_of_points);

    points = (Point *) calloc(num_of_points, sizeof(Point));

    for (int i = 0; i < num_of_points; i++) {
        fscanf(file_pointer, "%d %d", &points[i].x, &points[i].y);
    }

    fclose(file_pointer);

    printf("Data imported successfully.\n");

    // Finding the maximum and minimum X and Y values
    int min_x = points[0].x, max_x = points[0].x, min_y = points[0].y, max_y = points[0].y;

    for (int i = 1; i < num_of_points; i++) { 
        if (points[i].x < min_x)
            min_x = points[i].x;
        else if (points[i].x > max_x)
            max_x = points[i].x;

        if (points[i].y < min_y)
            min_y = points[i].y;
        else if (points[i].y > max_y)
            max_y = points[i].y;
    }

    printf("The minimum X value is %d\n", min_x);
    printf("The maximum X value is %d\n", max_x);
    printf("The minimum Y value is %d\n", min_y);
    printf("The maximum Y value is %d\n", max_y);

    // Calculating the average distance between all points
    float total_distance = 0;
    int num_of_distances = 0;

    for (int i = 0; i < num_of_points - 1; i++) {
        for (int j = i + 1; j < num_of_points; j++) {
            float distance = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
            total_distance += distance;
            num_of_distances++;
        }
    }

    float avg_distance = total_distance / num_of_distances;

    printf("The average distance between all points is %.2f\n", avg_distance);

    free(points);

    return 0;
}