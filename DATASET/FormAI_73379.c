//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 20

char maze[ROWS][COLS] = {
    "###################",
    "#.................#",
    "######.#####.#####.#",
    "#......#.......#...#",
    "####.###.#.###.#.#.#",
    "#...#...#.#...#.#.#.",
    "#.#.#.###.#.#.#.#.#.",
    "#.#.#.#...#.#.#...#.",
    "#.#.###.#.#.#.#.###.",
    "#.#.#...#.#...#.#...#",
    "#.#.#.#######.#.#.#.",
    "#.#.#.......#.#.#.#.",
    "#.#.#######.#.#.#.#.",
    "#.#.#.....#.#...#.#.",
    "#.#.#.###.#.#.#.#.#.",
    "#...#...#.#.#.#.#.#.",
    "###.#.#.#.#.#.#.#.#.",
    "#...#.#.#.#.#.#.#..X",
    "###################"
};

typedef struct {
    int row;
    int col;
    struct MazeNode* parent;
} MazeNode;

typedef struct {
    MazeNode nodes[ROWS*COLS];
    int size;
} MazeNodeList;

MazeNode* get_next_node(MazeNodeList* frontier) {
    // Get the node with the lowest cost
    int lowest_cost = -1;
    MazeNode* node_with_lowest_cost = NULL;
    for (int i = 0; i < frontier->size; i++) {
        MazeNode* node = &frontier->nodes[i];
        int cost = abs(node->row - ROWS) + abs(node->col - COLS);
        if (lowest_cost == -1 || cost < lowest_cost) {
            lowest_cost = cost;
            node_with_lowest_cost = node;
        }
    }
    return node_with_lowest_cost;
}

int main() {
    int start_row = 1;
    int start_col = 1;
    MazeNode start_node = {start_row, start_col, NULL};

    int end_row = ROWS-2;
    int end_col = COLS-2;

    MazeNodeList frontier = {0};

    frontier.nodes[frontier.size++] = start_node;
    int found_end = 0;

    while (frontier.size > 0 && !found_end) {
        MazeNode* current_node = get_next_node(&frontier);
        printf("Visiting node (%d, %d)\n", current_node->row, current_node->col);

        // Check if we've reached the end
        if (current_node->row == end_row && current_node->col == end_col) {
            printf("Found the end!\n");
            found_end = 1;
            break;
        }

        // Add the adjacent nodes to the frontier
        if (current_node->row > 0 && maze[current_node->row-1][current_node->col] != '#') {
            MazeNode next_node = {current_node->row-1, current_node->col, current_node};
            frontier.nodes[frontier.size++] = next_node;
        }
        if (current_node->row < ROWS-1 && maze[current_node->row+1][current_node->col] != '#') {
            MazeNode next_node = {current_node->row+1, current_node->col, current_node};
            frontier.nodes[frontier.size++] = next_node;
        }
        if (current_node->col > 0 && maze[current_node->row][current_node->col-1] != '#') {
            MazeNode next_node = {current_node->row, current_node->col-1, current_node};
            frontier.nodes[frontier.size++] = next_node;
        }
        if (current_node->col < COLS-1 && maze[current_node->row][current_node->col+1] != '#') {
            MazeNode next_node = {current_node->row, current_node->col+1, current_node};
            frontier.nodes[frontier.size++] = next_node;
        }
    }

    if (found_end) {
        // Trace back the route
        MazeNode* current_node = &frontier.nodes[frontier.size-1];
        while (current_node != NULL) {
            maze[current_node->row][current_node->col] = 'X';
            current_node = current_node->parent;
        }

        // Print the maze with the route
        for (int i = 0; i < ROWS; i++) {
            printf("%s\n", maze[i]);
        }
    } else {
        printf("No route found.\n");
    }

    return 0;
}