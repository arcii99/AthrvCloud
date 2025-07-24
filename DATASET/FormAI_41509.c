//FormAI DATASET v1.0 Category: Scientific ; Style: minimalist
#include <stdio.h>

int main() {
    int num;
    double square, cube;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    square = num * num;
    cube = num * num * num;
    
    printf("Square of %d is %.2lf\n", num, square);
    printf("Cube of %d is %.2lf\n", num, cube);
    
    return 0;
}