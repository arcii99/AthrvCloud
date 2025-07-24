//FormAI DATASET v1.0 Category: Math exercise ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int a,b,c,d;
    float x1,x2;
    printf("Enter the coefficients of quadratic equation in descending order\n");
    scanf("%d%d%d",&a,&b,&c);
    d=(b*b-4*a*c);
    if(d==0){
        printf("The Roots are Real and Equal\n");
        x1 = x2 = (-b)/(2.0*a);
        printf("Root 1 = %f and Root 2 = %f\n",x1,x2);
    }
    else if(d>0){
        printf("The Roots are Real and Distinct\n");
        x1 = (-b+sqrt(d))/(2.0*a);
        x2 = (-b-sqrt(d))/(2.0*a);
        printf("Root 1 = %f and Root 2 = %f\n",x1,x2);
    }
    else{
        printf("The Roots are Imaginary\n");
        x1 = (-b/(2.0*a));
        x2 = (sqrt(-d)/(2.0*a));
        printf("Root 1 = %f + %f i and Root 2 = %f - %f i\n",x1,x2,x1,x2);
    }
    return 0;
}