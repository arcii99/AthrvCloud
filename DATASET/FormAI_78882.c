//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: automated
#include<stdio.h>
#include<math.h>

#define PI 3.14159

/*Function to calculate area of a rectangle*/
double rectangle_area(double l, double h){
    return l*h;
}

/*Function to calculate area of a circle*/
double circle_area(double r){
    return PI * pow(r,2);
}

/*Function to calculate area of a triangle*/
double triangle_area(double b, double h){
    return 0.5 * b * h;
}

/*Function to calculate area of a regular polygon*/
double polygon_area(double s, int n){
    double half = 0.5 * n * pow(s,2);
    double apothem = s / (2 * tan(PI/n));
    double area = half * apothem;
    return area;
}

int main(){
    int option, n;
    double r, l, b, h, s, area;
    printf("Choose an option:\n");
    printf("1. Rectangle\n");
    printf("2. Circle\n");
    printf("3. Triangle\n");
    printf("4. Polygon\n");
    scanf("%d", &option);
    
    switch(option){
        case 1:
            printf("Enter length and height of the rectangle: ");
            scanf("%lf %lf", &l, &h);
            area = rectangle_area(l,h);
            printf("Area of the rectangle is %.2lf", area);
            break;
            
        case 2:
            printf("Enter the radius of the circle: ");
            scanf("%lf", &r);
            area = circle_area(r);
            printf("Area of the circle is %.2lf", area);
            break;
        
        case 3:
            printf("Enter base and height of the triangle: ");
            scanf("%lf %lf", &b, &h);
            area = triangle_area(b,h);
            printf("Area of the triangle is %.2lf", area);
            break;
        
        case 4:
            printf("Enter the number of sides and length of each side of the polygon: ");
            scanf("%d %lf", &n, &s);
            area = polygon_area(s,n);
            printf("Area of the polygon is %.2lf", area);
            break;
            
        default:
            printf("Invalid option!");
    }
    return 0;
}