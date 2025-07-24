//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: shape shifting
#include<stdio.h>

int main(){
    int shape;
    float length, breadth, radius, side;
    printf("Enter the initial shape (1: Square, 2: Rectangle, 3: Circle): ");
    scanf("%d",&shape);
    switch(shape){
        case 1:
            printf("Enter the side length of the square: ");
            scanf("%f",&side);
            printf("The square with side length %.2f has perimeter %.2f and area %.2f\n",side,(4*side),(side*side));
            printf("Enter the radius of the circle: ");
            scanf("%f",&radius);
            printf("The circle with radius %.2f has circumference %.2f and area %.2f\n",radius,(2*3.1416*radius),(3.1416*radius*radius));
            printf("Enter the length and breadth of the rectangle: ");
            scanf("%f%f",&length,&breadth);
            printf("The rectangle with length %.2f and breadth %.2f has perimeter %.2f and area %.2f\n",length,breadth,(2*(length+breadth)),(length*breadth));
            break;
        case 2:
            printf("Enter the length and breadth of the rectangle: ");
            scanf("%f%f",&length,&breadth);
            printf("The rectangle with length %.2f and breadth %.2f has perimeter %.2f and area %.2f\n",length,breadth,(2*(length+breadth)),(length*breadth));
            printf("Enter the side length of the square: ");
            scanf("%f",&side);
            printf("The square with side length %.2f has perimeter %.2f and area %.2f\n",side,(4*side),(side*side));
            printf("Enter the radius of the circle: ");
            scanf("%f",&radius);
            printf("The circle with radius %.2f has circumference %.2f and area %.2f\n",radius,(2*3.1416*radius),(3.1416*radius*radius));
            break;
        case 3:
            printf("Enter the radius of the circle: ");
            scanf("%f",&radius);
            printf("The circle with radius %.2f has circumference %.2f and area %.2f\n",radius,(2*3.1416*radius),(3.1416*radius*radius));
            printf("Enter the length and breadth of the rectangle: ");
            scanf("%f%f",&length,&breadth);
            printf("The rectangle with length %.2f and breadth %.2f has perimeter %.2f and area %.2f\n",length,breadth,(2*(length+breadth)),(length*breadth));
            printf("Enter the side length of the square: ");
            scanf("%f",&side);
            printf("The square with side length %.2f has perimeter %.2f and area %.2f\n",side,(4*side),(side*side));
            break;
        default:
            printf("Invalid choice, please enter valid input!\n");
            break;
    }
    return 0;
}