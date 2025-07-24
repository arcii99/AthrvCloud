//FormAI DATASET v1.0 Category: Fractal Generation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Function to generate fractals.
void generate_fractal(int x, int y, int w, int h, int iter)
{
    // Base case
    if (iter == 0) return;

    // Draw fractal shape
    // (Here we are just printing '*')
    for (int i = y; i < y + h; i++)
    {
        for (int j = x; j < x + w; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Divide into smaller sub-fractals
    int nw_w = w / 3;
    int nw_h = h / 3;
    generate_fractal(x, y, nw_w, nw_h, iter-1);
    generate_fractal(x+(2*nw_w), y, nw_w, nw_h, iter-1);
    generate_fractal(x, y+(2*nw_h), nw_w, nw_h, iter-1);
    generate_fractal(x+(2*nw_w), y+(2*nw_h), nw_w, nw_h, iter-1);
}

int main()
{
    int width, height, iterations;

    // Get user input for fractal size and depth
    printf("Enter the width of the fractal: ");
    scanf("%d", &width);
    printf("Enter the height of the fractal: ");
    scanf("%d", &height);
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    // Generate and output fractal
    generate_fractal(0, 0, width, height, iterations);

    return 0;
}