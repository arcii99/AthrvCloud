//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: imaginative
#include<stdio.h>
#include<math.h>

int main(){

    // Let's create a star polygon
    int num_points = 7; // the number of points on the star
    int radius = 100; // the radius of the circle

    // To find the coordinates of each point on the star, we need to find the angle of each point 
    // The angle between each point on the star will be 2 * PI / num_points
    double angle_per_point = 2 * M_PI / num_points;
    double current_angle = 0;

    // Let's store the coordinates of each point
    int x_coordinates[num_points];
    int y_coordinates[num_points];

    // Calculate the x and y coordinates of each point on the star using trigonometry
    for (int i = 0; i < num_points; i++){
        int x = radius * cos(current_angle);
        int y = radius * sin(current_angle);
        x_coordinates[i] = x;
        y_coordinates[i] = y;
        current_angle += angle_per_point;
    }

    // Now let's print the coordinates of each point
    for (int i = 0; i < num_points; i++){
        printf("Point %d: (%d, %d)\n", i, x_coordinates[i], y_coordinates[i]);
    }
   
    // Finally, let's connect each point on the star to create the polygon
    printf("Polygon: ");
    for (int i = 0; i < num_points; i++){
        printf("(%d, %d) ", x_coordinates[i], y_coordinates[i]);
    }
    printf("(%d, %d)\n", x_coordinates[0], y_coordinates[0]);

    return 0;
}