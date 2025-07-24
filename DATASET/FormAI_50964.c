//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: complex
#include <stdio.h>
#include <math.h>

typedef struct Point{
    double x;
    double y;
}point;

double get_distance(point a, point b){
   return sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2));
}

int main(){
    int n;
    printf("Enter number of points: ");
    scanf("%d",&n);

    point points[n];
    double shortest_distance = -1;

    printf("Enter %d points as x y values (ex. 1.0 2.0):\n",n);
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&points[i].x,&points[i].y);
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double distance = get_distance(points[i],points[j]);
            if((shortest_distance == -1) || (distance < shortest_distance)){
                shortest_distance = distance;
            }
        }
    }

    printf("The shortest distance between any two points is: %.2lf\n",shortest_distance);

    return 0;
}