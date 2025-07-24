//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 5

int map[WIDTH][HEIGHT] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

struct node
{
    int x, y;
    int g, f;
};

int heuristic(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    return dx + dy;
}

int is_valid(int x, int y)
{
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && !map[x][y];
}

int is_goal(int x, int y, int goal_x, int goal_y)
{
    return x == goal_x && y == goal_y;
}

void print_path(struct node *path, int goal_x, int goal_y)
{
    printf("Path: (");
    struct node current = path[0];
    for (int i = 1; !is_goal(current.x, current.y, goal_x, goal_y); i++)
    {
        current = path[i];
        printf("(%d, %d), ", current.x, current.y);
    }
    printf("(%d, %d))\n", goal_x, goal_y);
}

int main(int argc, char *argv[])
{
    int start_x = 2, start_y = 0;
    int goal_x = 3, goal_y = 4;

    struct node current = {start_x, start_y, 0, heuristic(start_x, start_y, goal_x, goal_y)};
    struct node open_list[WIDTH * HEIGHT];
    struct node closed_list[WIDTH * HEIGHT];
    int open_count = 0, closed_count = 0;

    open_list[open_count++] = current;

    while (open_count > 0)
    {
        current = open_list[0];
        int current_index = 0;
        for (int i = 1; i < open_count; i++)
        {
            if (open_list[i].f < current.f)
            {
                current = open_list[i];
                current_index = i;
            }
        }

        if (is_goal(current.x, current.y, goal_x, goal_y))
        {
            struct node path[WIDTH * HEIGHT];
            path[0] = current;
            print_path(path, goal_x, goal_y);
            return 0;
        }

        open_count--;
        closed_list[closed_count++] = current;

        int neighbors[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for (int i = 0; i < 8; i++)
        {
            int neighbor_x = current.x + neighbors[i][0];
            int neighbor_y = current.y + neighbors[i][1];

            if (!is_valid(neighbor_x, neighbor_y))
            {
                continue;
            }

            int g = current.g + 1;
            int f = g + heuristic(neighbor_x, neighbor_y, goal_x, goal_y);

            int in_open = 0;
            int in_closed = 0;
            for (int j = 0; j < open_count; j++)
            {
                if (open_list[j].x == neighbor_x && open_list[j].y == neighbor_y)
                {
                    in_open = 1;
                    if (g < open_list[j].g)
                    {
                        open_list[j].g = g;
                        open_list[j].f = f;
                        open_list[j].x = neighbor_x;
                        open_list[j].y = neighbor_y;
                    }
                    break;
                }
            }
            for (int j = 0; j < closed_count; j++)
            {
                if (closed_list[j].x == neighbor_x && closed_list[j].y == neighbor_y)
                {
                    in_closed = 1;
                    break;
                }
            }
            if (!in_open && !in_closed)
            {
                struct node neighbor = {neighbor_x, neighbor_y, g, f};
                open_list[open_count++] = neighbor;
            }
        }

        for (int i = current_index; i < open_count - 1; i++)
        {
            open_list[i] = open_list[i + 1];
        }
    }

    printf("No path found.\n");
    return 0;
}