//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: statistical
/* This program calculates the intersection point of two lines in a 2D plane using C Geometric algorithms.
   It takes four inputs, each representing the x and y coordinates of the two points that form each line*/

#include<stdio.h>

typedef struct{ double x,y; } point;

double cross_product(point a, point b){
    return a.x*b.y - b.x*a.y;
}

int main(){

    point line1_p1,line1_p2,line2_p1,line2_p2;
    double det,det_x,det_y;
    
    printf("Enter the x and y coordinates of the first point for line 1: ");
    scanf("%lf%lf",&line1_p1.x,&line1_p1.y);
    printf("Enter the x and y coordinates of the second point for line 1: ");
    scanf("%lf%lf",&line1_p2.x,&line1_p2.y);
    printf("Enter the x and y coordinates of the first point for line 2: ");
    scanf("%lf%lf",&line2_p1.x,&line2_p1.y);
    printf("Enter the x and y coordinates of the second point for line 2: ");
    scanf("%lf%lf",&line2_p2.x,&line2_p2.y);

    det = cross_product((point){line1_p1.x-line1_p2.x, line1_p1.y-line1_p2.y},(point){line2_p1.x-line2_p2.x, line2_p1.y-line2_p2.y});
    det_x = cross_product((point){line1_p1.x,line1_p1.y-line1_p2.y},(point){line2_p1.x, line2_p1.y-line2_p2.y}) - cross_product((point){line1_p1.x-line1_p2.x, line1_p1.y},(point){line2_p1.x-line2_p2.x, line2_p1.y});
    det_y = cross_product((point){line1_p1.x-line1_p2.x, line1_p1.y},(point){line2_p1.x-line2_p2.x, line2_p1.y}) - cross_product((point){line1_p1.x, line1_p1.y-line1_p2.y},(point){line2_p1.x, line2_p1.y-line2_p2.y});

    if(det==0){
        if(det_x==0 && det_x==0){
            printf("Both the lines are overlapping.\n");
        }
    }
    else{
        printf("The intersection point of the two lines is: (%.2lf,%.2lf)\n",det_x/det,det_y/det);
    }
   
    return 0;
}