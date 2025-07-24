//FormAI DATASET v1.0 Category: Arithmetic ; Style: Sherlock Holmes
#include<stdio.h>
#include<math.h>

int main() {
    int a=10, b=15, c=20, d = -5;
    double root1, root2, discriminant;
    char statement[100];

    printf("Sherlock Holmes is one of the greatest detectives of all time.\nLet's try to solve an arithmetic mystery with him!\n");

    // Mysterious equation
    int mystery = ((a+b)*(c+d))/2;
    sprintf(statement, "The mysterious equation is: ((%d+%d)*( %d%d))/2 = %d\n", a, b, c, d, mystery);
    printf("%s", statement);

    // Solving for roots using quadratic formula
    discriminant = pow(b,2) - 4*a*c;
    root1 = (-b + sqrt(discriminant)) / (2*a);
    root2 = (-b - sqrt(discriminant)) / (2*a);

    // Deductions from roots
    if(isnan(root1) || isnan(root2)) {
        sprintf(statement, "The identity of the roots is unknown. Continuing with the search...\n");
    } else if(root1 == root2) {
        sprintf(statement, "The equation seems to be related to a square. The root value is %0.2f.\n", root1);
    } else if(root1 > 0 && root2 < 0) {
        sprintf(statement, "One of the roots is negative and the other is positive. The equation appears to be related to a parabola.\n");
    } else if(root1 < 0 && root2 > 0) {
        sprintf(statement, "One of the roots is negative and the other is positive. The equation appears to be related to a parabola.\n");
    } else {
        sprintf(statement, "Analysis of the equation is inconclusive at this time...\n");
    }

    printf("%s", statement);

    return 0;
}