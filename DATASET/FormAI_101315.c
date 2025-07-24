//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fractal(int x, int y, int size, int level);

int main()
{
    int size, level, x, y;
    
    printf("Enter the size of the fractal: ");
    scanf("%d", &size);
    
    printf("Enter the level of the fractal: ");
    scanf("%d", &level);
    
    printf("Enter the starting position of the fractal (x, y): ");
    scanf("%d %d", &x, &y);
    
    fractal(x, y, size, level);
    
    return 0;
}

void fractal(int x, int y, int size, int level)
{
    int i, j;
    
    if (size == 1)
    {
        printf("1");
        return;
    }
    
    for (i = -size/2; i <= size/2; i++)
    {
        for (j = -size/2; j <= size/2; j++)
        {
            if (abs(i) == size/2 || abs(j) == size/2 || (rand() % 3 == 0))
            {
                int new_x = x + i * pow(3, level - 1);
                int new_y = y + j * pow(3, level - 1);
                
                printf("(%d,%d) ", new_x, new_y);
                
                if (level > 1)
                {
                    fractal(new_x, new_y, size/3, level - 1);
                }
            }
        }
        
        printf("\n");
    }
}