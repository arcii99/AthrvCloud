//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: post-apocalyptic
// Post-Apocalyptic Geometric Algorithms Example Program
// Code written by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

// Struct to hold x,y coordinates of a point
typedef struct {
    int x;
    int y;
} Point;

// Struct to hold information about a line segment
typedef struct {
    Point p1;
    Point p2;
    float slope;
    float y_intercept;
} Line;

// Global array to hold all the points
Point points[MAX_POINTS];
int num_points = 0;

// Function to calculate the distance between two points
float distance(Point p1, Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate the slope and y-intercept of a line segment
void calculate_slope_and_intercept(Line* line) {
    float dx = line->p1.x - line->p2.x;
    float dy = line->p1.y - line->p2.y;
    if (dx != 0) {
        line->slope = dy/dx;
    } else {
        line->slope = INFINITY; // Vertical line
    }
    line->y_intercept = line->p1.y - line->slope*line->p1.x;
}

// Function to find the intersection point of two lines
Point find_intersection(Line line1, Line line2) {
    Point intersection;
    if (line1.slope != line2.slope) {
        if (line1.slope == INFINITY) {
            // Line 1 is vertical
            intersection.x = line1.p1.x;
            intersection.y = line2.slope*intersection.x + line2.y_intercept;
        } else if (line2.slope == INFINITY) {
            // Line 2 is vertical
            intersection.x = line2.p1.x;
            intersection.y = line1.slope*intersection.x + line1.y_intercept;
        } else {
            // Neither line is vertical
            intersection.x = (line2.y_intercept - line1.y_intercept)/(line1.slope - line2.slope);
            intersection.y = line1.slope*intersection.x + line1.y_intercept;
        }
    } else {
        // Lines are parallel
        intersection.x = -1;
        intersection.y = -1;
    }
    return intersection;
}

int main() {
    // Generate random points and populate the points array
    for (int i = 0; i < MAX_POINTS; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
        num_points++;
    }

    // Find the shortest distance between any two points
    float min_distance = INFINITY;
    Point closest_point1;
    Point closest_point2;
    for (int i = 0; i < num_points - 1; i++) {
        for (int j = i + 1; j < num_points; j++) {
            float d = distance(points[i], points[j]);
            if (d < min_distance) {
                min_distance = d;
                closest_point1 = points[i];
                closest_point2 = points[j];
            }
        }
    }
    printf("The closest two points are (%d,%d) and (%d,%d) with distance %f\n", closest_point1.x, closest_point1.y, closest_point2.x, closest_point2.y, min_distance);

    // Find the two points that are farthest apart
    float max_distance = 0;
    Point farthest_point1;
    Point farthest_point2;
    for (int i = 0; i < num_points - 1; i++) {
        for (int j = i + 1; j < num_points; j++) {
            float d = distance(points[i], points[j]);
            if (d > max_distance) {
                max_distance = d;
                farthest_point1 = points[i];
                farthest_point2 = points[j];
            }
        }
    }
    printf("The farthest two points are (%d,%d) and (%d,%d) with distance %f\n", farthest_point1.x, farthest_point1.y, farthest_point2.x, farthest_point2.y, max_distance);

    // Find all the line segments that are parallel to the x-axis
    Line horizontal_lines[num_points];
    int num_horizontal_lines = 0;
    for (int i = 0; i < num_points - 1; i++) {
        for (int j = i + 1; j < num_points; j++) {
            float d = distance(points[i], points[j]);
            if (d < min_distance) {
                Line line;
                line.p1 = points[i];
                line.p2 = points[j];
                calculate_slope_and_intercept(&line);
                if (line.slope == 0) {
                    horizontal_lines[num_horizontal_lines] = line;
                    num_horizontal_lines++;
                }
            }
        }
    }
    printf("There are %d line segments parallel to the x-axis\n", num_horizontal_lines);

    // Find all the intersection points of the horizontal lines
    Point intersections[num_points];
    int num_intersections = 0;
    for (int i = 0; i < num_horizontal_lines - 1; i++) {
        for (int j = i + 1; j < num_horizontal_lines; j++) {
            Point intersection = find_intersection(horizontal_lines[i], horizontal_lines[j]);
            if (intersection.x != -1) {
                intersections[num_intersections] = intersection;
                num_intersections++;
            }
        }
    }
    printf("There are %d intersection points of the horizontal lines\n", num_intersections);

    return 0;
}