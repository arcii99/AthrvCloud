//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: calm
#include<stdio.h>
#include<math.h>

//A function to find the distance between two points in 3D space
float distance(float x1, float y1, float z1, float x2, float y2, float z2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2));
}

/*A function to find the area of a triangle using Heron's Formula
  Given the length of three sides*/
float triangle_area_heron(float a, float b, float c){
    float s = (a+b+c)/2; //Semi-perimeter
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

/*A function to find the area of a triangle using two sides and the angle between them
  Using the formula 1/2 absinC*/
float triangle_area_sas(float a, float b, float C){
    return 0.5*a*b*sin(C);
}

/*A function to find the volume of a sphere given its radius*/
float sphere_volume(float r){
    return (4.0/3.0)*3.14159*pow(r,3);
}

/*A function to find the surface area of a sphere given its radius*/
float sphere_surface_area(float r){
    return 4.0*3.14159*pow(r,2);
}

/*A function to find the volume of a cylinder given its radius and height*/
float cylinder_volume(float r, float h){
    return 3.14159*pow(r,2)*h;
}

/*A function to find the surface area of a cylinder given its radius and height*/
float cylinder_surface_area(float r, float h){
    return 2*3.14159*r*h+2*3.14159*pow(r,2);
}

int main(){
    float x1, y1, z1, x2, y2, z2, a, b, c, C, r, h;
    printf("Enter the coordinates of the first point (x1 y1 z1): ");
    scanf("%f %f %f",&x1,&y1,&z1);
    printf("Enter the coordinates of the second point (x2 y2 z2): ");
    scanf("%f %f %f",&x2,&y2,&z2);
    printf("The distance between the two points is %.2f\n",distance(x1, y1, z1, x2, y2, z2));
    printf("Enter the length of the three sides of the triangle: ");
    scanf("%f %f %f",&a,&b,&c);
    printf("The area of the triangle is %.2f\n",triangle_area_heron(a,b,c));
    printf("Enter the length of two sides of the triangle and the angle between them in degrees: ");
    scanf("%f %f %f",&a,&b,&C);
    printf("The area of the triangle is %.2f\n",triangle_area_sas(a,b,C*3.14159/180));
    printf("Enter the radius of the sphere: ");
    scanf("%f",&r);
    printf("The volume of the sphere is %.2f\n",sphere_volume(r));
    printf("The surface area of the sphere is %.2f\n",sphere_surface_area(r));
    printf("Enter the radius and height of the cylinder: ");
    scanf("%f %f",&r,&h);
    printf("The volume of the cylinder is %.2f\n",cylinder_volume(r,h));
    printf("The surface area of the cylinder is %.2f\n",cylinder_surface_area(r,h));
    return 0;
}