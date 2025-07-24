//FormAI DATASET v1.0 Category: Math exercise ; Style: romantic
#include <stdio.h>
#include <math.h>

int main() {
    float a,b,c,d,x1,x2,real,img;

    printf("My love, please enter the value of a: ");
    scanf("%f", &a);

    printf("My dearest, please enter the value of b: ");
    scanf("%f", &b);

    printf("My sweetie, please enter the value of c: ");
    scanf("%f", &c);

    d = (b*b) - (4*a*c);

    if (d > 0) {
        x1 = (-b+sqrt(d))/(2*a);
        x2 = (-b-sqrt(d))/(2*a);
        printf("My darling, the roots are real and different.\n");
        printf("My love, the first root: %.2f\n",x1);
        printf("My love, the second root: %.2f\n",x2);
    }

    else if (d == 0) {
        printf("My sweetheart, the roots are real and same.\n");
        x1 = (-b)/(2*a);
        printf("My darling, the only root: %.2f\n", x1);
    }

    else if (d < 0) {
        real = (-b)/(2*a);
        img = sqrt(-d)/(2*a);
        printf("My love, the roots are complex and different.\n");
        printf("My love, the first root: %.2f+i%.2f\n",real,img);
        printf("My love, the second root: %.2f-i%.2f\n",real,img);
    }

    printf("My beloved, your calculations are complete!\n");
    return 0;
}