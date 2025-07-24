//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: brave
#include<stdio.h>
#include<math.h>

struct Point {
    double x, y;
};

double distance(struct Point a, struct Point b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

double perimeter(struct Point a, struct Point b, struct Point c) {
    return distance(a, b) + distance(b, c) + distance(c, a);
}

double area(struct Point a, struct Point b, struct Point c) {
    double s = perimeter(a, b, c) / 2;
    return sqrt(s * (s - distance(a, b)) * (s - distance(b, c)) * (s - distance(c, a)));
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    struct Point points[n];

    printf("Enter the coordinates of points:\n");

    for(int i=0; i<n; i++) {
        printf("Point %d: ", i+1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    double max_area = 0;
    struct Point max_points[3];

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                double triangle_area = area(points[i], points[j], points[k]);
                if(triangle_area > max_area) {
                    max_area = triangle_area;
                    max_points[0] = points[i];
                    max_points[1] = points[j];
                    max_points[2] = points[k];
                }
            }
        }
    }

    printf("The vertices of the triangle with maximum area are: \n");
    printf("%.2lf, %.2lf\n", max_points[0].x, max_points[0].y);
    printf("%.2lf, %.2lf\n", max_points[1].x, max_points[1].y);
    printf("%.2lf, %.2lf\n", max_points[2].x, max_points[2].y);
    printf("The area of the triangle is: %.2lf", max_area);

    return 0;
}