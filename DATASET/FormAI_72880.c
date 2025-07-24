//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float getDistance(int x1, int y1, int x2, int y2){
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int main(){
    int vertices;
    printf("Enter the number of vertices in the polygon: ");
    scanf("%d", &vertices);

    int x[vertices], y[vertices];
    for(int i=0; i<vertices; i++){
        printf("Enter the x-coordinate of vertex %d: ", i+1);
        scanf("%d", &x[i]);
        printf("Enter the y-coordinate of vertex %d: ", i+1);
        scanf("%d", &y[i]);
    }

    float perimeter = 0;
    for(int i=0; i<vertices-1; i++){
        perimeter += getDistance(x[i], y[i], x[i+1], y[i+1]);
    }
    perimeter += getDistance(x[vertices-1], y[vertices-1], x[0], y[0]);

    printf("The perimeter of the polygon is: %.2f\n", perimeter);

    return 0;
}