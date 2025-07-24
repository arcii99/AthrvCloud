//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265358979323846264338327

struct Point{
    double x;
    double y;
};

struct Circle{
    struct Point center;
    double radius;
};

//returns the area of the polygon formed by the given array of vertices
double computePolygonArea(struct Point* vertices, int numVertices ){
    double area = 0.0;
    for(int i=0;i<numVertices;i++){
        int j = (i+1)%numVertices;
        area += vertices[i].x*vertices[j].y - vertices[j].x*vertices[i].y;
    }
    return area/2;
}

//returns the circle passing through the given three non-collinear points
struct Circle computeCircle(struct Point a, struct Point b, struct Point c){
    struct Circle circle;
    double x1 = a.x; double y1 = a.y;
    double x2 = b.x; double y2 = b.y;
    double x3 = c.x; double y3 = c.y;
    double yDelta_a = y2 - y1;
    double xDelta_a = x2 - x1;
    double yDelta_b = y3 - y2;
    double xDelta_b = x3 - x2;
    double slope_a = yDelta_a / xDelta_a;
    double slope_b = yDelta_b / xDelta_b;
    double centerX = (slope_a*slope_b*(y1 - y3) + slope_b*(x1 + x2) - slope_a*(x2 + x3) ) / (2* (slope_b - slope_a) );
    double centerY = (-1/slope_a)*(centerX - (x1+x2)/2) + (y1+y2)/2;
    double radius = sqrt( pow(centerX-x1,2) + pow(centerY-y1,2) );
    circle.center.x = centerX;
    circle.center.y = centerY;
    circle.radius = radius;
    return circle;
}

//returns the centroid of the given array of vertices
struct Point computeCentroid(struct Point* vertices, int numVertices){
    struct Point centroid;
    double xsum = 0.0;
    double ysum = 0.0;
    double area = computePolygonArea(vertices,numVertices);
    for(int i=0;i<numVertices;i++){
        int j = (i+1)%numVertices;
        xsum += (vertices[i].x + vertices[j].x) * (vertices[i].x*vertices[j].y - vertices[j].x*vertices[i].y);
        ysum += (vertices[i].y + vertices[j].y) * (vertices[i].x*vertices[j].y - vertices[j].x*vertices[i].y);
    }
    centroid.x = xsum/(6*area);
    centroid.y = ysum/(6*area);
    return centroid;
}


int main(){
    struct Point vertices[] = {{0,0},{4,0},{4,4},{2,6},{0,4}};
    int numVertices = 5;
    printf("Area of the polygon = %lf\n",computePolygonArea(vertices,numVertices));

    struct Circle circle = computeCircle(vertices[0],vertices[1],vertices[3]);
    printf("Circle Center = (%lf,%lf) and Radius = %lf\n",circle.center.x,circle.center.y,circle.radius);

    printf("Centroid of the polygon = (%lf,%lf)\n",computeCentroid(vertices,numVertices).x,computeCentroid(vertices,numVertices).y);

    return 0;
}