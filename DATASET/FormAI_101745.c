//FormAI DATASET v1.0 Category: Arithmetic ; Style: expert-level
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

//function to calculate the factorial of a number
int factorial(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

//function to calculate the value of sin(x)
double sin_x(double x){
    double sum = 0;
    int sign = 1;
    int i,j;
    for(i=1,j=0;i<=10;i+=2,j++){
        double term = pow(x,i)/factorial(i);
        sum += sign*term;
        sign = sign*(-1);
    }
    return sum;
}

//function to calculate the value of cos(x)
double cos_x(double x){
    double sum = 0;
    int sign = 1;
    int i,j;
    for(i=0,j=0;i<=10;i+=2,j++){
        double term = pow(x,i)/factorial(i);
        sum += sign*term;
        sign = sign*(-1);
    }
    return sum;
}

int main(){
    double x;

    printf("Enter the value of x in radians: ");
    scanf("%lf", &x);

    if(x >= -1.57 && x <= 1.57){
        printf("The value of sin(%lf) = %lf\n", x, sin_x(x));
    }
    else if(x > 1.57 && x <= 3.14){
        x = 3.14 - x;
        printf("The value of sin(%lf) = %lf\n", x, sin_x(x));
    }
    else if(x >= -3.14 && x < -1.57){
        x = -1*x;
        printf("The value of sin(%lf) = %lf\n", x, -1*sin_x(x));
    }
    else if(x < -3.14 || x > 3.14){
        x = fmod(x, 3.14);
        x = fabs(x);
        if(x >= -1.57 && x <= 1.57){
            printf("The value of sin(%lf) = %lf\n", x, sin_x(x));
        }
        else if(x > 1.57 && x <= 3.14){
            x = 3.14 - x;
            printf("The value of sin(%lf) = %lf\n", x, sin_x(x));
        }
        else if(x >= -3.14 && x < -1.57){
            x = -1*x;
            printf("The value of sin(%lf) = %lf\n", x, -1*sin_x(x));
        }
    }

    if(x >= 0 && x <= 3.14/2){
        printf("The value of cos(%lf) = %lf", x, cos_x(x));
    }
    else if(x > 3.14/2 && x <= 3.14){
        x = 3.14 - x;
        printf("The value of cos(%lf) = %lf", x, -1*cos_x(x));
    }
    else if(x >= -3.14 && x < 0){
        x = -1*x;
        printf("The value of cos(%lf) = %lf", x, cos_x(x));
    }
    else if(x < -3.14 || x > 3.14){
        x = fmod(x, 3.14);
        x = fabs(x);
        if(x >= 0 && x <= 3.14/2){
            printf("The value of cos(%lf) = %lf", x, cos_x(x));
        }
        else if(x > 3.14/2 && x <= 3.14){
            x = 3.14 - x;
            printf("The value of cos(%lf) = %lf", x, -1*cos_x(x));
        }
        else if(x >= -3.14 && x < 0){
            x = -1*x;
            printf("The value of cos(%lf) = %lf", x, cos_x(x));
        }
    }

    return 0;
}