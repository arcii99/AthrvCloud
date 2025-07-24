//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

typedef struct Point{
    float x,y;
} Point;

float distance(Point p1, Point p2){
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

void findIntersection(Point A, Point B, Point C, Point D, Point *p){

    float a1 = B.y - A.y;
    float b1 = A.x - B.x;
    float c1 = a1*A.x + b1*A.y;

    float a2 = D.y - C.y;
    float b2 = C.x - D.x;
    float c2 = a2*C.x + b2*C.y;

    float det = a1*b2 - a2*b1;

    if(det == 0){
        printf("The lines are parallel.\n");
    }
    else{
        p->x = (b2*c1 - b1*c2)/det;
        p->y = (a1*c2 - a2*c1)/det;
        printf("The intersection point is (%.2f, %.2f)\n",p->x,p->y);
    }
}

int main(){

    Point A,B,C,D,P;

    printf("Enter the co-ordinates of Point A: ");
    scanf("%f %f",&A.x,&A.y);

    printf("Enter the co-ordinates of Point B: ");
    scanf("%f %f",&B.x,&B.y);

    printf("Enter the co-ordinates of Point C: ");
    scanf("%f %f",&C.x,&C.y);

    printf("Enter the co-ordinates of Point D: ");
    scanf("%f %f",&D.x,&D.y);

    float AB = distance(A,B);
    float CD = distance(C,D);

    if(AB == 0 || CD == 0){
        printf("Invalid Input: A line cannot have zero length.\n");
        return 0;
    }

    float AC = distance(A,C);
    float AD = distance(A,D);
    float BC = distance(B,C);
    float BD = distance(B,D);

    if(AC == 0 || AD == 0 || BC == 0 || BD == 0){
        printf("The lines intersect at (%.2f, %.2f)\n",A.x,A.y);
        return 0;
    }

    findIntersection(A,B,C,D,&P);

    return 0;
}