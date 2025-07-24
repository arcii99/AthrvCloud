//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: active
#include<stdio.h>
#include<math.h>

//Function to find distance between two points
float distance(float x1,float y1,float x2,float y2){
    return sqrt(pow((x2-x1),2) + pow((y2-y1),2));
}

//Function to check whether three points are collinear or not
int collinear(float x1,float y1,float x2,float y2,float x3,float y3){
    float a = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2);
    if(a==0){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to find the area of triangle using the coordinates of the vertices
float area_of_triangle(float x1,float y1,float x2,float y2,float x3,float y3){
    float a = distance(x1,y1,x2,y2);
    float b = distance(x2,y2,x3,y3);
    float c = distance(x3,y3,x1,y1);
    float s = (a + b + c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(){
    float x1,x2,x3,y1,y2,y3;
    printf("Enter the coordinates of the first point: (x,y)\n");
    scanf("%f %f",&x1,&y1);
    printf("Enter the coordinates of the second point: (x,y)\n");
    scanf("%f %f",&x2,&y2);
    printf("Enter the coordinates of the third point: (x,y)\n");
    scanf("%f %f",&x3,&y3);

    if(collinear(x1,y1,x2,y2,x3,y3)==1){
        printf("The given points are collinear.\n");
    }
    else{
        printf("The given points are not collinear.\n");
        printf("The area of the triangle formed by these points is: %f\n", area_of_triangle(x1,y1,x2,y2,x3,y3));
    }
    return 0;
}