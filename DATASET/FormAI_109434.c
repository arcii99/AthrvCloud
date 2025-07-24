//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h> 

int main() { 
    int x[] = {2, 5, 3, 9, 4, 7};
    int y[] = {3, 6, 1, 8, 2, 5};
    int n = 6;
    
    int i, j, max_dist = 0;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            int dist = dx * dx + dy * dy;
            if (dist > max_dist) {
                max_dist = dist;
            }
        }
    }

    printf("The maximum distance between two points in the set is %d\n", max_dist);

    return 0; 
}