//FormAI DATASET v1.0 Category: Fractal Generation ; Style: enthusiastic
// Welcome to the world of Fractals
// This program generates a Sierpinski Triangle

#include <stdio.h>

void generate_fractal(int depth)
{
    int i, j;
    for(i=0; i<depth; i++)
    {
        for(j=0; j<(depth-i); j++)
        {
            printf(" ");
        }
        for(j=0; j<=i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

int main()
{
    int depth;
    printf("Hey there! Let's generate a Sierpinski Triangle.\n");
    printf("Please enter the depth of the triangle: ");
    scanf("%d", &depth);
    if(depth > 0)
    {
        printf("Generating Sierpinski Triangle for depth %d...\n", depth);
        generate_fractal(depth);
    }
    else
    {
        printf("Invalid input.\n");
    }
    printf("Hope you enjoyed generating a Sierpinski Triangle!\n");
    return 0;
}