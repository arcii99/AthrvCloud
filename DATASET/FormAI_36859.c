//FormAI DATASET v1.0 Category: Math exercise ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    srand(time(NULL)); // set seed for random number generator
    int x = rand() % 100 + 1; // generate a random integer between 1 and 100
    float y = sqrt(x); // calculate the square root of x
    
    printf("The square root of %d is %f.\n", x, y); // display the result
    
    int a = rand() % 100 + 1; // generate another random integer between 1 and 100
    int b = rand() % 100 + 1; // generate one more random integer between 1 and 100
    int c = a + b; // calculate the sum of a and b
    
    printf("If you add %d and %d together, you get %d.\n", a, b, c); // display the result
    
    float d = rand() % 100 + 1; // generate a random integer between 1 and 100
    float e = rand() % 100 + 1; // generate another random integer between 1 and 100
    float f = d / e; // calculate the result of dividing d by e
    
    printf("The result of dividing %f by %f is %f.\n", d, e, f); // display the result
    
    int g = rand() % 100 + 1; // generate one more random integer between 1 and 100
    int h = rand() % 100 + 1; // generate a final random integer between 1 and 100
    int i = g * h; // calculate the product of g and h
    
    printf("The product of %d and %d is %d.\n", g, h, i); // display the result
    
    return 0;
}