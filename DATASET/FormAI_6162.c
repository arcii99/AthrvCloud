//FormAI DATASET v1.0 Category: Error handling ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

    int a, b, c, x, y, z;
    float alpha, beta, gamma;
    printf("Enter the value of a: ");
    if(scanf("%d", &a) != 1){
        printf("Error: Invalid input for a!");
        exit(1);
    }
    printf("Enter the value of b: ");
    if(scanf("%d", &b) != 1){
        printf("Error: Invalid input for b!");
        exit(1);
    }
    printf("Enter the value of c: ");
    if(scanf("%d", &c) != 1){
        printf("Error: Invalid input for c!");
        exit(1);
    }

    if(a<=0 || b<=0 || c<=0){
        printf("Error: Sides of a triangle cannot be non-positive!");
        exit(1);
    }

    x = abs(b-c);
    y = abs(a-c);
    z = abs(a-b);

    if(x >= a || y >= b || z>= c){
        printf("Error: The given sides do not form a valid triangle!");
        exit(1);
    }

    alpha = acos((b*b + c*c - a*a)/(2*b*c));
    beta = acos((c*c + a*a - b*b)/(2*c*a));
    gamma = acos((a*a + b*b - c*c)/(2*a*b));

    printf("The angles of the given triangle are: %f, %f, %f", alpha, beta, gamma);

    return 0;
}