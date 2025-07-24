//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: calm
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//function to calculate the distance between two points
float distance(float x1, float y1, float x2, float y2){
    float dist = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    return dist;
}

//main function
int main(){

    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    //creating an array to store the coordinates of the points
    float points[n][2];
    for(int i=0; i<n; i++){
        printf("\nEnter the x and y coordinates of point %d: ", i+1);
        scanf("%f %f", &points[i][0], &points[i][1]);
    }

    //finding the convex hull using Graham's Scan algorithm
    int hull[n], top=2;
    hull[0]=0;
    hull[1]=1;
    hull[2]=2;

    for(int i=3; i<n; i++){
        while(top>=0 && (points[hull[top]][0]*(points[hull[top-1]][1]-points[hull[top-2]][1]) + points[hull[top-1]][0]*(points[hull[top-2]][1]-points[hull[top]][1]) + points[hull[top-2]][0]*(points[hull[top]][1]-points[hull[top-1]][1]) <= 0)){
            top--;
        }
        top++;
        hull[top]=i;
    }

    //calculating the perimeter of the convex hull
    float perimeter=0;
    for(int i=0; i<top; i++){
        perimeter+=distance(points[hull[i]][0], points[hull[i]][1], points[hull[i+1]][0], points[hull[i+1]][1]);
    }

    printf("\nThe perimeter of the convex hull is: %f", perimeter);

    return 0;
}