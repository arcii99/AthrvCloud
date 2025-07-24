//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAP_SIZE 10
#define WALL_COST 1000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    int g;
    int f;
} Node;

typedef struct {
    int map[MAP_SIZE][MAP_SIZE];
    Node came_from[MAP_SIZE][MAP_SIZE];
    bool closed_list[MAP_SIZE][MAP_SIZE];
} Map;

int heuristic_distance(Point current, Point target)
{
    return abs(current.x - target.x) + abs(current.y - target.y);
}

int movement_cost(Point start, Point end)
{
    if (start.x == end.x && start.y == end.y) {
        return 0;
    }
    if (start.x == end.x || start.y == end.y) {
        return 1;
    }
    return 2;
}

Node pop_cheapest_node(Node *open_list, int length)
{
    int cheapest_index = 0;
    for (int i = 1; i < length; i++) {
        if (open_list[i].f < open_list[cheapest_index].f) {
            cheapest_index = i;
        }
    }
    Node cheapest_node = open_list[cheapest_index];
    for (int i = cheapest_index; i < length - 1; i++) {
        open_list[i] = open_list[i + 1];
    }
    return cheapest_node;
}

bool is_in_open_list(Node *open_list, int open_list_length, Point position)
{
    for (int i = 0; i < open_list_length; i++) {
        if (open_list[i].position.x == position.x && open_list[i].position.y == position.y) {
            return true;
        }
    }
    return false;
}

bool is_wall(Map map, Point position)
{
    return map.map[position.y][position.x] == WALL_COST;
}

void reconstruct_path(Map map, Point end_point)
{
    Point current_point = end_point;
    while (true) {
        printf("(%d,%d) ", current_point.x, current_point.y);
        if (current_point.x == map.came_from[current_point.y][current_point.x].position.x
            && current_point.y == map.came_from[current_point.y][current_point.x].position.y) {
            break;
        }
        current_point = map.came_from[current_point.y][current_point.x].position;
    }
}

void search(Map map, Point start_point, Point end_point)
{
    Node open_list[MAP_SIZE * MAP_SIZE];
    int open_list_length = 0;
    Node start_node = { start_point, 0, heuristic_distance(start_point, end_point) };
    open_list[0] = start_node;
    open_list_length++;

    while (open_list_length > 0) {
        Node current_node = pop_cheapest_node(open_list, open_list_length);
        open_list_length--;

        if (current_node.position.x == end_point.x && current_node.position.y == end_point.y) {
            printf("Path: ");
            reconstruct_path(map, end_point);
            return;
        }

        map.closed_list[current_node.position.y][current_node.position.x] = true;

        for (int y = current_node.position.y - 1; y <= current_node.position.y + 1; y++) {
            for (int x = current_node.position.x - 1; x <= current_node.position.x + 1; x++) {
                Point neighbour = { x, y };
                if (neighbour.x < 0 || neighbour.y < 0 || neighbour.x >= MAP_SIZE || neighbour.y >= MAP_SIZE) {
                    continue;
                }
                if ((neighbour.x == current_node.position.x && neighbour.y == current_node.position.y)
                    || is_wall(map, neighbour) || map.closed_list[neighbour.y][neighbour.x]) {
                    continue;
                }
                int tentative_g_score = current_node.g + movement_cost(current_node.position, neighbour);
                Node neighbour_node = {};
                neighbour_node.position = neighbour;

                if (is_in_open_list(open_list, open_list_length, neighbour)) {
                    if (tentative_g_score < open_list[open_list_length].g) {
                        neighbour_node.g = tentative_g_score;
                        neighbour_node.f = neighbour_node.g + heuristic_distance(neighbour_node.position, end_point);
                        open_list[open_list_length] = neighbour_node;
                        map.came_from[neighbour.y][neighbour.x] = current_node;
                    }
                } else {
                    neighbour_node.g = tentative_g_score;
                    neighbour_node.f = neighbour_node.g + heuristic_distance(neighbour_node.position, end_point);
                    open_list[open_list_length] = neighbour_node;
                    open_list_length++;
                    map.came_from[neighbour.y][neighbour.x] = current_node;
                }
            }
        }
    }

    printf("No path found\n");
}

int main()
{
    Map map = { {  // has to be rectangular
            { 0, 0, 0, 0, WALL_COST, WALL_COST, WALL_COST, 0, WALL_COST, 0 },
            { 0, WALL_COST, 0, 0, 0, WALL_COST, 0, 0, 0, WALL_COST },
            { WALL_COST, 0, 0, WALL_COST, 0, 0, WALL_COST, 0, WALL_COST, 0 },
            { WALL_COST, 0, 0, 0, WALL_COST, 0, 0, WALL_COST, WALL_COST, WALL_COST },
            { 0, WALL_COST, WALL_COST, 0, 0, WALL_COST, 0, WALL_COST, 0, WALL_COST },
            { 0, 0, WALL_COST, 0, WALL_COST, 0, WALL_COST, WALL_COST, 0, 0 },
            { WALL_COST, WALL_COST, 0, WALL_COST, WALL_COST, 0, 0, WALL_COST, WALL_COST, WALL_COST },
            { WALL_COST, 0, 0, 0, WALL_COST, 0, WALL_COST, WALL_COST, WALL_COST, 0 },
            { WALL_COST, 0, WALL_COST, 0, 0, 0, 0, WALL_COST, 0, 0 },
            { 0, 0, WALL_COST, WALL_COST, WALL_COST, WALL_COST, WALL_COST, 0, 0, 0 }
        } };

    Point start_point = { 0, 0 };
    Point end_point = { 9, 9 };

    search(map, start_point, end_point);
}