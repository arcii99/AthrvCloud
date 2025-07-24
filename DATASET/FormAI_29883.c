//FormAI DATASET v1.0 Category: Fractal Generation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h> 

const int HEIGHT = 60;
const int WIDTH = 120;

void generate_fractal(int x, int y, int iter, char canvas[][WIDTH])
{
    if(iter == 0) 
    {
        canvas[y][x] = '*';
        return;
    }
    
    int new_x = x / 3;
    int new_y = y / 3;
    
    // recursive calls
    generate_fractal(new_x, new_y, iter-1, canvas);
    generate_fractal(new_x, new_y+HEIGHT/3, iter-1, canvas);
    generate_fractal(new_x, new_y+2*HEIGHT/3, iter-1, canvas);
    generate_fractal(new_x+WIDTH/3, new_y, iter-1, canvas);
    generate_fractal(new_x+WIDTH/3, new_y+2*HEIGHT/3, iter-1, canvas);
    generate_fractal(new_x+2*WIDTH/3, new_y, iter-1, canvas);
    generate_fractal(new_x+2*WIDTH/3, new_y+HEIGHT/3, iter-1, canvas);
    generate_fractal(new_x+2*WIDTH/3, new_y+2*HEIGHT/3, iter-1, canvas);
}

int main()
{
    // initialize canvas
    char canvas[HEIGHT][WIDTH];
    for(int i=0; i<HEIGHT; i++) 
    {
        for(int j=0; j<WIDTH; j++) 
        {
            canvas[i][j] = ' ';
        }
    }
    
    // generate fractal with iteration=4
    generate_fractal(WIDTH/2, HEIGHT/2, 4, canvas);

    // print canvas
    for(int i=0; i<HEIGHT; i++) 
    {
        for(int j=0; j<WIDTH; j++) 
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}