//FormAI DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>

int main(){

    int a, b, c;
    float pi = 3.14159265;
    char name[20];

    printf("Welcome to the Arithmetic Program! \n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello %s! Please enter three integers: \n", name);
    scanf("%d %d %d", &a, &b, &c);

    printf("The sum of the three integers is: %d \n", a+b+c);
    printf("The product of the three integers is: %d \n", a*b*c);
    printf("The average of the three integers is: %d \n", (a+b+c)/3);
    printf("The remainder when the first integer is divided by the second is: %d \n", a%b);
    printf("The quotient when the first integer is divided by the second is: %d \n", a/b);

    printf("Now, please enter a radius: \n");
    float radius;
    scanf("%f", &radius);
    printf("The circumference is: %.2f \n", 2*pi*radius);
    printf("The area is: %.2f \n", pi*radius*radius);

    printf("Thank you for using the Arithmetic Program, %s! \n", name);

    return 0;
}