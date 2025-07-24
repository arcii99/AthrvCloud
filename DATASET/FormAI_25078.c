//FormAI DATASET v1.0 Category: Math exercise ; Style: multivariable
#include<stdio.h>
#include<math.h>

double findDistance(double x1, double y1, double x2, double y2){
    double distance = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    return distance;
}

int main(){
    double x1, y1, x2, y2, x3, y3, a, b, c, s, area;
    
    printf("Enter x-coordinate and y-coordinate for point A: ");
    scanf("%lf %lf", &x1, &y1);
    
    printf("Enter x-coordinate and y-coordinate for point B: ");
    scanf("%lf %lf", &x2, &y2);
    
    printf("Enter x-coordinate and y-coordinate for point C: ");
    scanf("%lf %lf", &x3, &y3);
    
    a = findDistance(x1, y1, x2, y2);
    b = findDistance(x2, y2, x3, y3);
    c = findDistance(x3, y3, x1, y1);
    
    if(a+b>c && b+c>a && c+a>b){
        s = (a+b+c)/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        printf("\nThe area of the triangle ABC is: %lf\n", area);
    }
    else{
        printf("\nThe given points do not form a valid triangle.\n");
    }
    
    return 0;
}