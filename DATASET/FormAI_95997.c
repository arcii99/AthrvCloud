//FormAI DATASET v1.0 Category: Syntax parsing ; Style: medieval
#include <stdio.h>

// Medieval style C syntax parsing program to calculate the area of a rectangle

int main(void) {

    int length, width, area;
    
    printf ("Hark! What be the length of thine rectangle?\n");
    scanf("%d", &length);

    printf("And what be the width thereof?\n");
    scanf("%d",&width);

    area = length * width;

    printf("Verily! The area of the rectangle is %d square units", area);

    return 0;
}