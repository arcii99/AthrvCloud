//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int maze[WIDTH][HEIGHT] = {0};

void generate_maze(int x, int y)
{
    maze[x][y] = 1;
    
    // Create a random order of directions to move in
    int dirs[4] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++)
    {
        int temp = dirs[i];
        int r = rand() % 4;
        dirs[i] = dirs[r];
        dirs[r] = temp;
    }
    
    // Move in each direction
    for (int i = 0; i < 4; i++)
    {
        int dir = dirs[i];
        switch (dir)
        {
            case 0: // North
                if (y > 0 && maze[x][y-1] == 0)
                {
                    maze[x][y-1] = 1;
                    maze[x][y] |= 1<<0; // Set the north wall of current cell to be open
                    generate_maze(x, y-1);
                }
                break;
            case 1: // East
                if (x < WIDTH-1 && maze[x+1][y] == 0)
                {
                    maze[x+1][y] = 1;
                    maze[x][y] |= 1<<1; // Set the east wall of current cell to be open
                    generate_maze(x+1, y);
                }
                break;
            case 2: // South
                if (y < HEIGHT-1 && maze[x][y+1] == 0)
                {
                    maze[x][y+1] = 1;
                    maze[x][y] |= 1<<2; // Set the south wall of current cell to be open
                    generate_maze(x, y+1);
                }
                break;
            case 3: // West
                if (x > 0 && maze[x-1][y] == 0)
                {
                    maze[x-1][y] = 1;
                    maze[x][y] |= 1<<3; // Set the west wall of current cell to be open
                    generate_maze(x-1, y);
                }
                break;
        }
    }
}

void print_maze()
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%s", maze[x][y]&1 ? " " : "_"); // Print north wall
            printf("%s", maze[x][y]&2 ? " " : "|"); // Print east wall
            printf("%s", maze[x][y]&4 ? " " : "_"); // Print south wall
            printf("%s", maze[x][y]&8 ? " " : "|"); // Print west wall
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    generate_maze(0, 0);
    print_maze();
    return 0;
}