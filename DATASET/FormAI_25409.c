//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: invasive
#include<stdio.h>
#include<math.h>

//Function to calculate area of triangle
float area_of_triangle(float x1, float y1, float x2, float y2, float x3, float y3){
    float area;
    area = fabs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2);
    return area;
}

//Function to find the intersection point of two lines
void intersection_point(float a1, float b1, float c1, float a2, float b2, float c2){
    float d = a1*b2 - a2*b1;
    if(d == 0) printf("Lines are parallel");
    else{
        float x = (b2*c1 - b1*c2)/d;
        float y = (a1*c2 - a2*c1)/d;
        printf("The intersection point is (%.2f, %.2f)", x, y);
    }
}

//Function to calculate distance between two points
float distance(float x1, float y1, float x2, float y2){
    float dist;
    dist = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    return dist;
}

int main(){
    int choice;
    float x1,y1,x2,y2,x3,y3,a1,b1,c1,a2,b2,c2,len1,len2,len3;

    printf("\nGeometry Calculations\n");
    printf("1. Find the area of triangle\n");
    printf("2. Find the intersection point of two lines\n");
    printf("3. Find the distance between two points\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("\nEnter the coordinates of the three vertices of triangle to calculate area : ");
            scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);
            float area = area_of_triangle(x1,y1,x2,y2,x3,y3);
            printf("\nThe area of triangle is %.2f\n", area);      
            break;

        case 2:
            printf("\nEnter the equation of two lines in the form of ax + by + c = 0 to find the intersection point : ");
            scanf("%f%f%f%f%f%f",&a1,&b1,&c1,&a2,&b2,&c2);
            intersection_point(a1,b1,c1,a2,b2,c2);
            break;

        case 3:
            printf("\nEnter the coordinates of two points to calculate distance : ");
            scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
            float dist = distance(x1,y1,x2,y2);
            printf("\nThe distance between two points is %.2f\n", dist);
            break;

        default:
            printf("\nInvalid choice !\n");
    }

    return 0;
}