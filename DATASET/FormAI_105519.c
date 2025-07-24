//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: sophisticated
#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    
    double x[n], y[n], d, max_d = 0.0;
    int p1 = -1, p2 = -1;
    
    printf("Enter the coordinates of the points: \n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            d = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
            if (d > max_d) {
                max_d = d;
                p1 = i;
                p2 = j;
            }
        }
    }
    
    printf("The farthest points are (%.2lf, %.2lf) and (%.2lf, %.2lf)\n", x[p1], y[p1], x[p2], y[p2]);
    printf("The distance between them is %.2lf\n", max_d);
    
    return 0;
}