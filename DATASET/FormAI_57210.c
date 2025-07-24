//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void drawCircle(int x0, int y0, int radius);

int main(){
    int x, y, radius;
    printf("Welcome to the circle drawing program!\n");
    printf("Please enter the x-coordinate of the center of your circle: ");
    scanf("%d", &x);
    printf("Please enter the y-coordinate of the center of your circle: ");
    scanf("%d", &y);
    printf("Please enter the radius of your circle: ");
    scanf("%d", &radius);
    printf("\n");
    printf("Generating...\n");
    drawCircle(x, y, radius);
    printf("\n");
    printf("Tada!\n");
    return 0;
}

void drawCircle(int x0, int y0, int radius){
    int x, y, i;
    float theta;
    for(i=0;i<=360;i++){
        theta = i*(M_PI/180);
        x = x0 + radius*cos(theta);
        y = y0 + radius*sin(theta);
        printf("(%d, %d)", x, y);
    }
}