//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of constants
#define ROW 6
#define COL 6
#define INF 99999

// Function to check if given co-ordinates (row, col) 
// are valid or not 
bool is_valid(int row, int col) {
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL);
}

// Function to check if current vertex is not blocked
bool is_unblocked(int grid[][COL], int row, int col) {
    return grid[row][col] == 1;
}

// Function to calculate the Manhattan distance between 
// the target co-ordinates and current co-ordinates 
int calculate_heuristic(int target_row, int target_col, 
                         int curr_row, int curr_col) {
    return abs(target_row - curr_row) + 
           abs(target_col - curr_col);
}

// Function to find the shortest path between a given source cell
// to a target cell using A* algorithm
void find_shortest_path(int grid[][COL], int start_row, int start_col, 
                        int target_row, int target_col) {

    // Check if start and target co-ordinates are valid
    if (!is_valid(start_row, start_col) || !is_valid(target_row, target_col)) {
        printf("Invalid start or target position.\n");
        return;
    }

    // Check if start and target positions are unblocked
    if (!is_unblocked(grid, start_row, start_col) || !is_unblocked(grid, target_row, target_col)) {
        printf("Start or target position is blocked.\n");
        return;
    }

    // Declare and initialize closed list and open list
    bool closed_list[ROW][COL];
    memset(closed_list, false, sizeof(closed_list));

    int dist[ROW][COL];
    memset(dist, INF, sizeof(dist));

    int parent_row[ROW][COL];
    int parent_col[ROW][COL];
    memset(parent_row, -1, sizeof(parent_row));
    memset(parent_col, -1, sizeof(parent_col));

    dist[start_row][start_col] = 0;

    // Declare and initialize heap
    int heap_size = ROW * COL;

    int heap[heap_size];
    memset(heap, 0, sizeof(heap));

    int heap_row[heap_size];
    int heap_col[heap_size];
    memset(heap_row, 0, sizeof(heap_row));
    memset(heap_col, 0, sizeof(heap_col));

    int heap_index = 0;

    // Insert start vertex into heap
    heap[heap_index] = dist[start_row][start_col] + 
                       calculate_heuristic(target_row, target_col, 
                                           start_row, start_col);
    heap_row[heap_index] = start_row;
    heap_col[heap_index] = start_col;
    heap_index++;

    // Loop until heap becomes empty or target vertex is found
    while (heap_index > 0) {

        // Extract minimum vertex from heap
        int min_value = heap[0];
        int min_row = heap_row[0];
        int min_col = heap_col[0];

        heap[0] = heap[heap_index - 1];
        heap_row[0] = heap_row[heap_index - 1];
        heap_col[0] = heap_col[heap_index - 1];
        heap_index--;

        // Perform heapify operation on heap
        int i = 0;
        while (1) {
            int left_child = 2 * i + 1;
            int right_child = 2 * i + 2;

            if (left_child >= heap_index)
                break;

            int smallest_child = left_child;
            if (right_child < heap_index && heap[right_child] < heap[left_child])
                smallest_child = right_child;

            if (heap[i] > heap[smallest_child]) {
                int temp = heap[i];
                heap[i] = heap[smallest_child];
                heap[smallest_child] = temp;

                temp = heap_row[i];
                heap_row[i] = heap_row[smallest_child];
                heap_row[smallest_child] = temp;

                temp = heap_col[i];
                heap_col[i] = heap_col[smallest_child];
                heap_col[smallest_child] = temp;

                i = smallest_child;
            }
            else
                break;
        }

        // Add current vertex to closed list
        closed_list[min_row][min_col] = true;

        // Check if target is reached
        if (min_row == target_row && min_col == target_col) {
            printf("Shortest path found from (%d,%d) to (%d,%d) with distance %d.\n", 
                    start_row, start_col, target_row, target_col, dist[target_row][target_col]);
            return;
        }

        // Check neighbors of current vertex
        for (int row_offset = -1; row_offset <= 1; row_offset++) {
            for (int col_offset = -1; col_offset <= 1; col_offset++) {

                // Skip if current cell is diagonal
                if (abs(row_offset) == abs(col_offset))
                    continue;

                int neighbor_row = min_row + row_offset;
                int neighbor_col = min_col + col_offset;

                // Skip if neighbor is out of bounds
                if (!is_valid(neighbor_row, neighbor_col))
                    continue;

                // Skip if neighbor is blocked or is already in closed list
                if (!is_unblocked(grid, neighbor_row, neighbor_col) || closed_list[neighbor_row][neighbor_col])
                    continue;

                int new_dist = dist[min_row][min_col] + 1;

                // Update neighbor if new path is shorter or neighbor is not in open list
                if (new_dist < dist[neighbor_row][neighbor_col]) {
                    dist[neighbor_row][neighbor_col] = new_dist;
                    parent_row[neighbor_row][neighbor_col] = min_row;
                    parent_col[neighbor_row][neighbor_col] = min_col;

                    bool neighbor_in_heap = false;
                    int heap_neighbor_index = 0;
                    for (int j = 0; j < heap_index; j++) {
                        if (heap_row[j] == neighbor_row && heap_col[j] == neighbor_col) {
                            neighbor_in_heap = true;
                            heap_neighbor_index = j;
                            break;
                        }
                    }

                    if (neighbor_in_heap) {
                        heap[heap_neighbor_index] = new_dist + 
                                                     calculate_heuristic(target_row, target_col, 
                                                                         neighbor_row, neighbor_col);

                        i = heap_neighbor_index;
                        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
                            int temp = heap[i];
                            heap[i] = heap[(i - 1) / 2];
                            heap[(i - 1) / 2] = temp;

                            temp = heap_row[i];
                            heap_row[i] = heap_row[(i - 1) / 2];
                            heap_row[(i - 1) / 2] = temp;

                            temp = heap_col[i];
                            heap_col[i] = heap_col[(i - 1) / 2];
                            heap_col[(i - 1) / 2] = temp;

                            i = (i - 1) / 2;
                        }
                    }
                    else {
                        heap[heap_index] = new_dist + 
                                           calculate_heuristic(target_row, target_col, 
                                                               neighbor_row, neighbor_col);
                        heap_row[heap_index] = neighbor_row;
                        heap_col[heap_index] = neighbor_col;
                        heap_index++;

                        i = heap_index - 1;
                        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
                            int temp = heap[i];
                            heap[i] = heap[(i - 1) / 2];
                            heap[(i - 1) / 2] = temp;

                            temp = heap_row[i];
                            heap_row[i] = heap_row[(i - 1) / 2];
                            heap_row[(i - 1) / 2] = temp;

                            temp = heap_col[i];
                            heap_col[i] = heap_col[(i - 1) / 2];
                            heap_col[(i - 1) / 2] = temp;

                            i = (i - 1) / 2;
                        }
                    }
                }
            }
        }
    }

    // Target vertex was not found
    printf("Target vertex not found.\n");
}

int main() {

    int grid[ROW][COL] = {{1, 0, 1, 1, 1, 1},
                          {1, 1, 1, 0, 1, 1},
                          {1, 1, 1, 1, 1, 0},
                          {0, 0, 1, 1, 1, 1},
                          {0, 0, 1, 0, 1, 0},
                          {0, 0, 1, 1, 1, 1}};

    find_shortest_path(grid, 0, 0, 5, 5);

    return 0;
}