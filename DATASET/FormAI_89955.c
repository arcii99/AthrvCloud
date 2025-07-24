//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: standalone
#include <stdio.h>

void calculateArea(){
    int base, height;
    printf("\nEnter the Base and Height of Right-Angled Triangle: ");
    scanf("%d%d", &base, &height);
    float area = (base * height) / 2;
    printf("Area of the Right-Angle Triangle is %f square units.", area);
}

void calculatePerimeter(){
    int side1, side2, hypotenuse;
    printf("\nEnter the Three Sides of Right-Angled Triangle: ");
    scanf("%d%d%d", &side1, &side2, &hypotenuse);
    int perimeter = side1 + side2 + hypotenuse;
    printf("Perimeter of the Right-Angle Triangle is %d units.", perimeter);
}

int main(){
    printf("\nMenu\n1.Calculate Area of Right-Angled Triangle\n2.Calculate Perimeter of Right-Angled Triangle\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch(choice){
        case 1:
            calculateArea();
            break;
        case 2:
            calculatePerimeter();
            break;
        default:
            printf("Invalid Choice!");
    }

    return 0;
}